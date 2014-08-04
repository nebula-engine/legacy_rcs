float math_abs ( float a )
{
    if ( a >= 0 )
    {
        return a;
    }
    else
    {
        return (-1.0f*a);
    }
}

template <class T> void cubic_solve( T * Ip, T ** I )
{
	T Ixx = I[0][0];
	T Iyy = I[1][1];
	T Izz = I[2][2];
	T Ixy = I[0][1];
	T Ixz = I[0][2];
	T Iyz = I[1][2];

	T a = 1;

	T b = -1.0*( Ixx + Iyy + Izz );

	T c = -1.0*( Ixy*Ixy + Iyz*Iyz + Ixz*Ixz - Ixx*Iyy - Iyy*Izz - Ixx*Izz );

	T d = Ixx*Iyz*Iyz + Iyy*Ixz*Ixz + Izz*Ixy*Ixy - Ixx*Iyy*Izz - 2.0*Ixy*Iyz*Ixz;

	T p = ( 3.0*a*c - b*b )/( 3.0*a*a );
	T q = ( 2.0*b*b*b - 9.0*a*b*c + 27.0*a*a*d )/( 27.0*a*a*a );

	T r = 4.0*p*p*p + 27.0*q*q;

	if ( r == 0 )
	{
		T t1 = -3.0*q/2.0/p;

		T t2 = t1;

		T t3 = 3.0*q/p;

		Ip[0] = t1 - b/3.0/a;

		Ip[1] = t2 - b/3.0/a;

		Ip[2] = t3 - b/3.0/a;
	}
	else
	{
		MessageBox( NULL, _T("principal inertia not found"), NULL, 0 );
		return;
	}
}
