MARINE_BODY::MARINE_BODY()
{
}

void MARINE_BODY::render()
{
	rp->render();
}

void MARINE_BODY::physics()
{
	
}

void MARINE_BODY::collision()
{
	
}

bool MARINE_BODY::interact_return( const Vector3 &O, const Vector3 &v, float &dist )
{
	return false;
}

void MARINE_BODY::interact( INTERACT_TYPE interact_type, OBJECT * parent_object )
{
	REGION * region_array[9];
    region_neighbor( parent_object->game, parent_object, region_array );
    
    std::vector<float> victim_dist_vector;
    std::vector<OBJECT*> victim_pointer_vector;
    
	std::vector<INTERACT_HIT> hits;

	float dist = 0;

    for ( int a = 0; a < 9; a++ )
    {
        interact_detect_sub( interact_type, parent_object->game, dist, parent_object, x + (q * eye_offset), q * x, &region_array[a]->marine_pointer_vector, hits );
        interact_detect_sub( interact_type, parent_object->game, dist, parent_object, x + (q * eye_offset), q * x, &region_array[a]->terminal_pointer_vector, hits );
    }
    
	float victim_dist;
	OBJECT * victim_pointer;
	std::vector<float>::iterator it;
    if ( victim_pointer_vector.size() > 0 )
    {
		//it = std::vector<float>::max_element(victim_dist_vector.begin(),victim_dist_vector.end());
		
		victim_dist = victim_dist_vector.at(0);
        victim_pointer = victim_pointer_vector.at(0);
        for ( unsigned int a = 0; a < victim_pointer_vector.size(); a++ )
        {
            if ( victim_dist_vector.at(a) < victim_dist )
            {
                victim_dist = victim_dist_vector.at(a);
                victim_pointer = victim_pointer_vector.at(a);
            }
        }
    }
    
	// do something as result of interaction

}
