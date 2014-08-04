void TOY_PART::collide  ( OBJECT * object )
{
	object->collision( &rp );
}

void TOY_PART::collision( POLYHEDRON<PART> * polyhedron )
{
	vclip.algorithm( &rp, polyhedron );
}

void TOY_PART::interact( OBJECT * o )
{

}

bool TOY_PART::interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist )
{
	return false;
}

void TOY_PART::physics_apply_force_virt( Vector3 force, Vector3 moment )
{
	// calculate forces
	physics_apply_force(force,moment);
}

void TOY_PART::render()
{
	//_glPushMatrix();
	glPushMatrix();
	rp.render_poly();
	//rp.render();

	glPopMatrix();
}
