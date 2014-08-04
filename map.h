int map_load( GAME * g, std::vector<SPAWN> &spawn_pointer_vector )
{
    SPAWN s;
    // team 0
    s.tag.a[3] =  0;
    s.tag.a[2] =  0;
    s.tag.a[1] =  0;
    s.tag.a[0] = -1;
    
    s.O.col[0] = -10.0;
    s.O.col[1] =   0.0;
    s.O.col[2] =   1.0;
    spawn_pointer_vector.push_back(s);
    
    
    s.tag.a[3] =  0;
    s.tag.a[2] =  0;
    s.tag.a[1] =  0;
    s.tag.a[0] =  0;

    s.O.col[0] = -12.0;
    s.O.col[1] =   2.0;
    s.O.col[2] =   1.0;
    spawn_pointer_vector.push_back(s);
    
    
    s.tag.a[3] =  0;
    s.tag.a[2] =  0;
    s.tag.a[1] =  0;
    s.tag.a[0] =  1;

    s.O.col[0] = -12.0;
    s.O.col[1] =   1.0;
    s.O.col[2] =   0.0;
    spawn_pointer_vector.push_back(s);
    
    
    s.tag.a[3] =  0;
    s.tag.a[2] =  0;
    s.tag.a[1] =  0;
    s.tag.a[0] =  2;

    s.O.col[0] = -12.0;
    s.O.col[1] =   1.0;
    s.O.col[2] =  -2.0;
    spawn_pointer_vector.push_back(s);
    
    // team 1
    s.tag.a[3] =  1;
    s.tag.a[2] =  0;
    s.tag.a[1] =  0;
    s.tag.a[0] = -1;

    s.O.col[0] =  10.0;
    s.O.col[1] =   1.0;
    s.O.col[2] =   0.0;
    spawn_pointer_vector.push_back(s);
    
    
    s.tag.a[3] =  1;
    s.tag.a[2] =  0;
    s.tag.a[1] =  0;
    s.tag.a[0] =  0;

    s.O.col[0] =  12.0;
    s.O.col[1] =   1.0;
    s.O.col[2] =   2.0;
    spawn_pointer_vector.push_back(s);
    
    
    s.tag.a[3] =  1;
    s.tag.a[2] =  0;
    s.tag.a[1] =  0;
    s.tag.a[0] =  1;

    s.O.col[0] =  12.0;
    s.O.col[1] =   1.0;
    s.O.col[2] =   0.0;
    spawn_pointer_vector.push_back(s);
    
    
    s.tag.a[3] =  1;
    s.tag.a[2] =  0;
    s.tag.a[1] =  0;
    s.tag.a[0] =  2;
    
    s.O.col[0] =  12.0;
    s.O.col[1] =   1.0;
    s.O.col[2] =  -2.0;
    spawn_pointer_vector.push_back(s);
    
    
    return 0;
}
