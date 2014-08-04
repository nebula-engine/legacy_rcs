int objective_check( GAME * g, OBJECTIVE * o )
{
    switch ( o->data.type )
    {
    case OBJECTIVE_TYPE_MOVE:
        objective_check_move( g, o );
        break;
    case OBJECTIVE_TYPE_MOVE_AT_LEVEL:
        objective_check_move_at_level( g, o );
        break;
    }
    
    return 0;
}

int objective_check_move( GAME * g, OBJECTIVE * o )
{
    Vector3 d;
    
    for ( unsigned int a = 0; a < o->lower_pointer_vector.size(); a++ )
    {
        d = o->data.wp - o->lower_pointer_vector.at(a)->body.x;
        if ( d.magnitude() > o->data.prox )
        {
            return 0;
        }
    }
    
    o->data.state = OBJECTIVE_STATE_COMPLETE;
    
    return 0;
}

int objective_check_move_at_level( GAME * g, OBJECTIVE * o )
{
    for ( unsigned int a = 0; a < o->spawn_pointer_vector.size(); a++ )
    {
        if ( o->spawn_pointer_vector.at(a)->data.state != OBJECTIVE_STATE_COMPLETE )
        {
            return 0;
        }
    }
    
    o->data.state = OBJECTIVE_STATE_COMPLETE;
    
    return 1;
}
