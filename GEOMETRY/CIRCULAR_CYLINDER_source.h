template <class U> CIRCULAR_CYLINDER<U>::CIRCULAR_CYLINDER( float offset_x, float offset_y, float offset_z, float p, float n, float s, float radius, float height, float rho )
{
	geometry_type = GEOMETRY_TYPE_CIRCULAR_CYLINDER;
	density = rho;
	r = radius;
	h = height;

	// mass
	m = PI*r*r*h*density;

	// inertia relative to shape coor
	I.row[0].col[0] = m*( 3*r*r + h*h )/12;
	I.row[1].col[1] = m*( 3*r*r + h*h )/12;
	I.row[2].col[2] = m*( r*r )/12;

	// position relative to part coor
	offset.col[0] = offset_x;
	offset.col[1] = offset_y;
	offset.col[2] = offset_z;

	
	recalculate_constants();
}
