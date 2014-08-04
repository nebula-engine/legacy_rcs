int interact_detect_sub( INTERACT_TYPE interact_type, GAME * g, float &dist, OBJECT * o, Vector3 O, Vector3 v, std::vector<OBJECT*> * thing_pointer, std::vector<INTERACT_HIT> &hits )
{
    OBJECT * target = NULL;
	INTERACT_HIT hit;
    for ( unsigned int a = 0; a < thing_pointer->size(); a++ )
    {
        target = thing_pointer->at(a);
        if ( ( target != o ) && ( target->health > 0 ) )
        {
            if ( target->interact_return( interact_type, O, v, dist ) );
            {
				hit.dist = dist;
				hit.object = target;
				hits.push_back(hit);
            }
        }
    }
    return 0;
}
