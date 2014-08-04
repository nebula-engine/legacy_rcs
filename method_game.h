GAME::GAME()
{
    next_marine_id = 0;
	id = next_game_id++;

	// default game
	// toy
	TOY * toy1 = new TOY;

	toy1->toy_part.v.col[0] = -0.0f;
	toy1->toy_part.v.col[1] = 0.0f;
	toy1->toy_part.v.col[2] = 0.0f;

	toy1->toy_part.v.col[3] = 0.0f;
	toy1->toy_part.v.col[4] = 0.0f;
	toy1->toy_part.v.col[5] = 0.0f;

	toy1->toy_part.x.col[0] =  1.0f;
	toy1->toy_part.x.col[1] =  0.0f;
	toy1->toy_part.x.col[2] = -3.0f;

	toy1->toy_part.object = toy1;
	toy1->fixed = false;

	objects.push_back( toy1 );



	toy1 = new TOY;

	toy1->toy_part.v.col[0] =  0.05f;
	toy1->toy_part.v.col[1] =  0.0f;
	toy1->toy_part.v.col[2] =  0.0f;

	toy1->toy_part.v.col[3] =  0.0f;
	toy1->toy_part.v.col[4] =  0.0f;
	toy1->toy_part.v.col[5] =  0.0f;

	toy1->toy_part.x.col[0] = -0.3f;
	toy1->toy_part.x.col[1] =  0.5f;
	toy1->toy_part.x.col[2] = -3.5f;

	toy1->toy_part.object = toy1;
	toy1->fixed = false;

	objects.push_back( toy1 );
}

GAME::GAME( int level_param ) : org_lvl(level_param)
{
	next_marine_id = 0;
	id = next_game_id++;
	
	// not default game
	weapons.push_back( new WEAPON(0,40) );
	
	MARINE * m = NULL;
    std::vector<SPAWN> spawn;
	TAG tag;
	
    int numAtLevel[NUM_LEVEL];
    for ( int a = 0; a < NUM_LEVEL-1; a++ )
    {
        if ( org_lvl > a )
        {
            numAtLevel[a] = 3;
        }
        else
        {
            numAtLevel[a] = 1;
        }
    }
    numAtLevel[NUM_LEVEL-1] = 2;
    
	// load map
    map_load( this, spawn );
    
    int current_level = 3;
    for ( int a = 0; a < numAtLevel[current_level]; a++ )
    {
        level[a] = new ORG_MAP_LEVEL;
        game_create_recursive( current_level, tag, org_lvl, level[a], numAtLevel, a );
    }
    
    // assign positions
    SPAWN s;
    for ( unsigned int a = 0; a < spawn.size(); a++ )
    {
        s = spawn.at(a);
		m = lookup_marine_tag_2_pointer( this, s.tag );
        m->body.x = s.O;
    }
    
	region_initialize( this );
	region_assign_all( this, &objects );
}

void GAME::game_create_recursive( int level, TAG tag, int org_lvl, ORG_MAP_LEVEL * om_level, int * numAtLevel, int a )
{
    MARINE * m = NULL;
	tag.a[level] = a;
    
    if ( org_lvl >= level )
    {
        m = new MARINE( this, tag, weapons, om_level );
		marines.push_back( m );
        om_level->m = m;
    }
    else
    {
        om_level->m = NULL;
    }
    
    level--;
    
    for ( int a = 0; a < 3; a++ )
    {
        om_level->level[a] = NULL;
    }
    
    if ( level >= 0 )
    {
        for ( int a = 0; a < numAtLevel[level]; a++ )
        {
            om_level->level[a] = new ORG_MAP_LEVEL;
            game_create_recursive( level, tag, org_lvl, om_level->level[a], numAtLevel, a );
        }
    }
}

int GAME::get_next_marine_id()
{
	return (next_marine_id++);
}

void GAME::update_dt()
{
	// calculate time step
	/*
	float T_new = (float)clock();
	dt = (T_new - T)/((float)CLOCKS_PER_SEC);
	if ( dt == 0 ) return;
	T = T_new;
	*/
	dt = 0.01;
}