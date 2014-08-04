int region_assign( GAME * g, OBJECT * o )
{
    int * x_ind = NULL;
    int * z_ind = NULL;

	Vector3 O = o->O();

    x_ind = &o->region_x_ind;
    z_ind = &o->region_z_ind;
    
    *x_ind = -1;
    *z_ind = -1;
    
    for ( int x = 0; x < g->region_nx; x++ )
    {
        for ( int z = 0; z < g->region_nz; z++ )
        {
            if ( O.col[0] >= g->region_x[x] )
            {
                if (  O.col[0] < g->region_x[x+1] )
                {
                    if (  O.col[2] >= g->region_z[z] )
                    {
                        if (  O.col[2] < g->region_z[z+1] )
                        {
                            *x_ind = x;
                            *z_ind = z;
                            
                            switch ( o->object_type )
                            {
                            case OBJECT_TYPE_MARINE:
                                g->r[x*(g->region_nz)+z].marine_pointer_vector.push_back(o);
                                break;
                            case OBJECT_TYPE_TERMINAL:
                                g->r[x*(g->region_nz)+z].terminal_pointer_vector.push_back(o);
                                break;
                            }
                            return SUCCESS;
                        }
                    }
                }
            }
        }
    }
    swprintf_s(msgbox_tchar, _T("x=%f\nregion_x[0]=%f region_x[1]=%f region_x[2]=%f"), O.col[0], g->region_x[0], g->region_x[1], g->region_x[2] );
    MessageBox( NULL, msgbox_tchar, NULL, 0 );
    return FAILURE;
};

int region_remove( GAME * g, OBJECT * o )
{
    REGION * r = &g->r[(o->region_x_ind)*(g->region_nz)+(o->region_z_ind)];
    std::vector<OBJECT*> * thing_pointer_vector = NULL;

    switch ( o->object_type )
    {
    case OBJECT_TYPE_MARINE:
        thing_pointer_vector = &r->marine_pointer_vector;
        break;
    case OBJECT_TYPE_TERMINAL:
        thing_pointer_vector = &r->terminal_pointer_vector;
        break;
    default:
        return FAILURE;
    }
    
    for ( unsigned int a = 0; a < thing_pointer_vector->size(); a++ )
    {
        if ( thing_pointer_vector->at(a) == o )
        {
             thing_pointer_vector->erase(thing_pointer_vector->begin()+a);
             return SUCCESS;
        }
    }
    return FAILURE;
}

int region_detect_change( GAME * g, OBJECT * o )
{
    int &x_ind = o->region_x_ind;
    int &z_ind = o->region_z_ind;
    
    Vector3 O = o->O();
    
    if (( O.col[0] < g->region_x[x_ind] ) || ( O.col[0] >= g->region_x[x_ind+1] ))
    {
        region_remove( g, o );
        region_assign( g, o );
    }
    else if (( O.col[2] < g->region_z[z_ind] ) || ( O.col[2] >= g->region_z[z_ind+1] ))
    {
        region_remove( g, o );
        region_assign( g, o );
    }
    return 0;
}

template <class T> int region_detect_change_all( GAME * g, T object_pointer_vector )
{
    OBJECT * o;
    for ( int a = 0; a < object_pointer_vector->size(); a++ )
    {
        o = object_pointer_vector->at(a);
        region_detect_change( g, o );
    }
    
    return 0;
}

template <class T> int region_assign_all( GAME * g, T object_pointer_vector )
{
    OBJECT * o;
    for ( unsigned int a = 0; a < object_pointer_vector->size(); a++ )
    {
        o = object_pointer_vector->at(a);
        region_assign( g, o );
    }
    return 0;
}

int region_initialize( GAME * g )
{
    float x[] = { -300, -200, -100, 0, 100, 200, 300 };
    float z[] = { -300, -200, -100, 0, 100, 200, 300 };
    
    g->region_nx = 6;
    g->region_nz = 6;
    
    try
    {
        g->region_x = new float[g->region_nx+1];
        g->region_z = new float[g->region_nz+1];
        g->r = new REGION[(g->region_nx)*(g->region_nz)];
    }
    catch ( std::exception &e )
    {
        MessageBox( NULL, NULL, NULL, 0 );
    }
    
    for ( int a = 0; a < (g->region_nx + 1); a++ )
    {
        g->region_x[a] = x[a];
    }
    for ( int a = 0; a < (g->region_nz + 1); a++ )
    {
        g->region_z[a] = z[a];
    }
    
    return 0;
}

int region_neighbor( GAME * g, OBJECT * o, REGION ** region_array )
{
    /*
    8 1 2
    7 0 3
    6 5 4
    */
    for ( int a = 0; a < 9; a++ ){ region_array[a] = NULL; }
    
    int x = o->region_x_ind;
    int z = o->region_z_ind;
    
    region_array[0] = &g->r[x*(g->region_nz)+z];
    
    if ( x > 0 )
    {
        region_array[7] = &g->r[(x-1)*(g->region_nz)+(z+0)];
    }
    if ( x < g->region_nx )
    {
        region_array[3] = &g->r[(x+1)*(g->region_nz)+(z+0)];
    }
    if ( z > 0 )
    {
        region_array[1] = &g->r[(x+0)*(g->region_nz)+(z-1)];
    }
    if ( z < g->region_nz )
    {
        region_array[5] = &g->r[(x+0)*(g->region_nz)+(z+1)];
    }
    
    if ( ( x > 0 ) && ( z > 0 ) )
    {
        region_array[8] = &g->r[(x-1)*(g->region_nz)+(z-1)];
    }
    if ( ( x > 0 ) && ( z < g->region_nz ) )
    {
        region_array[6] = &g->r[(x-1)*(g->region_nz)+(z+1)];
    }
    if ( ( x < g->region_nx ) && ( z > 0 ) )
    {
        region_array[2] = &g->r[(x+1)*(g->region_nz)+(z-1)];
    }
    if ( ( x < g->region_nx ) && ( z < g->region_nz ) )
    {
        region_array[4] = &g->r[(x+1)*(g->region_nz)+(z+1)];
    }
    
    return 0;
}
