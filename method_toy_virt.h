void TOY::collide( OBJECT * o )
{
	toy_part.collide( o );
}

void TOY::collision( POLYHEDRON<PART> * polyhedron )
{
	toy_part.collision( polyhedron );
}

void TOY::interact( INTERACT_TYPE type )
{}

bool TOY::interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist )
{ return false; }

Vector3 TOY::O()
{
	return Vector3();
}

void TOY::render()
{
	toy_part.render();
}

void TOY::physics_apply_force_virt()
{
	Vector3 force, moment;
	toy_part.physics_apply_force_virt( force, moment );
}

void TOY::physics_apply_velocity_virt()
{
	toy_part.physics_apply_velocity();
}
