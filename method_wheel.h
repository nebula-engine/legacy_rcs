WHEEL::WHEEL( float radius, float height, float offset_x, float offset_y, float offset_z, float p, float n, float s, float P_z )
{
	// pivot and axis in shape-coor
	P.col[0] = 0;
	P.col[1] = 0;
	P.col[2] = P_z;

	axis.col[0] = 0;
	axis.col[0] = 0;
	axis.col[2] = 1;

	cc = new CIRCULAR_CYLINDER<PART>( offset_x, offset_y, offset_z, p, n, s, radius, height, 1 );
}
