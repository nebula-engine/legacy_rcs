SURFACE_PART::SURFACE_PART( float O_x, float O_y, float O_z, float width, float depth, float pr, float nu, float sp )
{
	
}
/*
void SURFACE_PART::collision( PART * part, SHAPE * shape )
{
	Vector3 A;
	std::vector<Vector3> corners;

	shape->getCorners( part, corners );

	int max_i;
	float penetration_temp = 0;
	float penetration = -1.0f;

	for ( int i = 0; i < corners.size(); i++ )
	{
		corners.at(i) += part->x;
		
		penetration_temp = C - corners.at(i).dot(n);

		if ( penetration_temp > penetration )
		{
			penetration = penetration_temp;
			max_i = i;
		}
	}

	if ( penetration < 0 ){ return; }

	//swprintf_s( msgbox_tchar, _T("penetration %f"), penetration );
    //MessageBox( NULL , msgbox_tchar, NULL, 0 );
	

	A = corners.at(max_i);
	
	Vector3 r = A - ( part->x + part->COM );
	
	Vector6 J(n,r.cross(n));

	solveSingleSolid( part, J );
}
*/
