MARINE::MARINE( GAME * g, TAG &tag_param, std::vector<WEAPON*> &weapons, ORG_MAP_LEVEL * om_level )
{
	id = g->get_next_marine_id();
	
	tag = tag_param;

    if ( !weapons.empty() )
    {
        weapon = weapons.at(0);
    }

    level = om_level;

    object_type = OBJECT_TYPE_MARINE;
    
    control = CTRL_AI;
    
    client = NULL;
    
    ai_target = NULL;
    
    weapon = NULL;
    
    next_shot = clock();
    last_move = clock();
    last_rotate = clock();
    
    eag_pos.col[1] = 10;
    
    move_w = false;
    move_s = false;
    move_a = false;
    move_d = false;
    
    jump = false;
    mousel = false;
    mouser = false;
}

void MARINE::stop()
{
    move_v.col[0] = 0;
    move_v.col[1] = 0;
    move_v.col[2] = 0;
}

void MARINE::fire()
{
	if ( next_shot > clock() )
    {
        interact( INTERACT_TYPE_SHOT );
        next_shot = clock() + weapon->cooldown;
    }
}
