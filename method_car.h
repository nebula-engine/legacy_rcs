CAR::CAR( float width, float depth, float height )
{
	float x_wheel_offset = 0.5;
	float x[] = { -0.5, -0.5,  0.5, 0.5 };
	float y[] = { -0.5,  0.5, -0.5, 0.5 };

	body = CAR_BODY(2,4,1);

	for ( int i = 0; i < 4; i++ )
	{
		wheel[i] = WHEEL( 1, 0.5, width*x[i], depth*y[i], -0.5*height, PI/2.0,PI/2.0,0,x_wheel_offset*((x[i]>0)?1.0:-1.0));
	}
	
}

void CAR::physics()
{
	Vector3 F;
	Vector3 M;
	Vector6 f_temp;

	Vector3 P;
	Vector3 axis;
	
	for ( int i = 0; i < 4; i++ )
	{
		// convert wheel axis from wheel-coor to car_body-coor
		axis = body.q * ( wheel[i].q.getConjugate() * wheel[i].axis );

		// force
		F = ( body.P[i] - ( wheel[i].P + wheel[i].x - body.x ) );

		//moment
		M = body.axis[i].cross(axis);

		// combine
		f_temp = Vector6(F,M);

		// add to force sum
		body.f     += f_temp;
		wheel[i].f -= f_temp;
	}
}

void CAR::render()
{

}
