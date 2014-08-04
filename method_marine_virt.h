void MARINE::collide( POLYHEDRON<PART> * polyhedron )
{
}

void MARINE::collision( OBJECT * object )
{
}

void MARINE::interact( INTERACT_TYPE type )
{
	body.interact( type, this );
}

bool MARINE::interact_return( INTERACT_TYPE interact_type, const Vector3 &O, const Vector3 &v, float &dist )
{
	return body.interact_return( O, v, dist );
}

Vector3 MARINE::O()
{
	return Vector3();
}

void MARINE::render()
{
	switch (disp_mode)
    {
    case DM_NORMAL:
		body.render();
        break;
    case DM_EAGLE:
        body.render();
        break;
    }
}

void MARINE::physics()
{
}
