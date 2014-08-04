CAR_BODY::CAR_BODY( float width, float depth, float height )
{
	float x[] = { -0.5, -0.5,  0.5, 0.5 };
	float y[] = { -0.5,  0.5, -0.5, 0.5 };
	
	// pivot and axis in shape-coor
	for ( int i = 0; i < 4; i++ )
	{
		P[i].col[0] = x[i]*width;
		P[i].col[1] = y[i]*depth;
		P[i].col[2] = -0.5*height;
		
		axis[i].col[0] = 0;
		axis[i].col[1] = 1;
		axis[i].col[2] = 0;
	}

	rp = new RECTANGULAR_PARALLELEPIPED<PART>(0,0,0,0,0,0,width,depth,height,1);
}