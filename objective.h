int objective_create( OBJECTIVE * o, MARINE * creator, MARINE * lower, GAME * g )
{
    g->objectives.push_back(o);
    
    o->lower_pointer_vector.clear();
    o->spawn_pointer_vector.clear();
    
    switch ( o->data.whom )
    {
    case OBJECTIVE_WHOM_TEAM:
        for ( int a = 0; a < 3; a++ )
        {
            if ( creator->level->level[a] != NULL )
            {
                o->lower_pointer_vector.push_back( creator->level->level[a]->m );
            }
        }
        break;
    case OBJECTIVE_WHOM_MARINE:
        o->lower_pointer_vector.push_back( lower );
        break;
    }
    
    lower = NULL;
    for ( unsigned int a = 0; a < o->lower_pointer_vector.size(); a++ )
    {
        lower = o->lower_pointer_vector.at(a);
        lower->objective_pointer_vector.push_back(o);
    }
    
    if ( o->data.type == OBJECTIVE_TYPE_MOVE_AT_LEVEL )
    {
        objective_create_move_at_level( o, creator, lower, g );
    }

    return 0;
}

int objective_create_move_at_level( OBJECTIVE * o, MARINE * creator, MARINE * lower, GAME * g )
{
    OBJECTIVE * spawn = NULL;
    
    if ( creator->tag.a[o->data.level + 1] != -1 )
    {
        spawn = new OBJECTIVE;
        
        (*spawn).data = (*o).data;
        
        objective_create( spawn, creator, lower, g );
        
        o->spawn_pointer_vector.push_back( spawn );
    }
    
    lower = NULL;
    for ( unsigned int a = 0; a < o->lower_pointer_vector.size(); a++ )
    {
        lower = o->lower_pointer_vector.at(a);
        if ( lower->tag.a[0] == -1 )
        {
            spawn = new OBJECTIVE;
            
            (*spawn) = (*o);
            
            spawn->data.whom = OBJECTIVE_WHOM_TEAM;
            
            objective_create( spawn, lower, NULL, g );
            
            o->spawn_pointer_vector.push_back( spawn );
        }
    }
    
    return 0;
}
