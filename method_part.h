PART::PART()
{
	// time
	//T = (float)clock();
}
void PART::calcuate_constants( int num, ... )
{
	va_list args;

	POLYHEDRON<PART> * poly;

	Vector3 r;

	m = 0;
	
	// mass, part-coordinate center of mass, and part-coordinate inertia matrix
	va_start( args, num );
	for ( int i = 0; i < num; i++ )
	{
		poly = va_arg( args, POLYHEDRON<PART>* );

		I   += poly->I;
		COM += poly->offset * poly->m;
		m   += poly->m;
	}
	va_end( args );

	COM /= m;

	x += COM;

	va_start( args, num );
	for ( int i = 0; i < num; i++ )
	{
		poly = va_arg( args, POLYHEDRON<PART>* );
		poly->offset -= COM;
	}
	va_end( args );

	Matrix3 Mul = Matrix3::Eye() * m;
	
	M    = Matrix6(Mul          ,Matrix3(),Matrix3(),I);
	Minv = Matrix6(Mul.inverse(),Matrix3(),Matrix3(),I.inverse());
}
void PART::collision_part_rectangle( RECTANGULAR_PARALLELEPIPED<PART> * rp, SURFACE_RECTANGLE * rect )
{
	
}
/*
template <class T> void vector_pns( T &p, T &n, T &s, T * X, T * Y, T * Z, T ** t )
{
	T * x = new T[3];
	T * y = new T[3];
	T * z = new T[3];

	T * xp = new T[3];
	T * yp = new T[3];
	T * zp = new T[3];

	T * c = new T[3];

	T ** t1 = new T*[3];
	t1[0] = new T[3];
	t1[1] = new T[3];
	t1[2] = new T[3];
	
	matrix_vector_multiplication( x, t, X );
	matrix_vector_multiplication( y, t, Y );
	matrix_vector_multiplication( z, t, Z );

	vector_project_XY( xp, z );

	if ( vector_magnitude( xp ) == 0 )
	{
		vector_copy( yp, y );

		p = vector_angle( X, x, c );
		if ( vector_dot( c, Z ) < 0 ) p *= (T)(-1.0);

		n = 0;
		s = 0;
	}
	else
	{
		vector_normalize( xp );
		
		p = vector_angle( X, xp, c );
		if ( vector_dot( c, Z ) < 0 ) p *= (T)(-1.0);

		vector_cross( yp, Z, xp );

		n = vector_angle( Z, z, c );
		if ( vector_dot( c, yp ) < 0 ) n *= (T)(-1.0);

		s = vector_angle( yp, y, c );
		if ( vector_dot( c, z ) < 0 ) s *= (T)(-1.0);

	}
}
*/
void PART::rotate( const Vector3 &axis, float angle )
{
	q = Quaternion( axis, angle ) * q;
}

void PART::_gluLookAt()
{
	Vector3 Eye    = x + ( q.getConjugate() * eye_offset );
	Vector3 LookAt = Eye + ( q.getConjugate() * x );
	Vector3 Up     = q * Z;

	gluLookAt(
		Eye.col[0],    Eye.col[1],    Eye.col[2],
		LookAt.col[0], LookAt.col[1], LookAt.col[2],
		Up.col[0],     Up.col[1],     Up.col[2] );
}

void PART::_glPushMatrix()
{
	glPushMatrix();
	
	glTranslatef( x.col[0], x.col[1], x.col[2] );

	float * mat = new float[16];
	q.getMatrix(mat);
	glMultMatrixf(mat);
	delete[] mat;
}

void PART::update_dt()
{
	// calculate time step
	/*
	float T_new = (float)clock();
	dt = (T_new - T)/((float)CLOCKS_PER_SEC);
	if ( dt == 0 ) return;
	T = T_new;
	*/
}

void PART::physics_apply_force( Vector3 force, Vector3 moment )
{
	Vector3 gravity(0,GRAV,0);
	
	//update_dt();

	force += gravity;

	H = M * v;

	moment += H.lower().cross(v.lower());

	f = Vector6(force,moment);

	// apply force
	v += Minv * f * game->dt;
}

void PART::physics_apply_velocity()
{
	// apply velocity
	Vector3 vl = v.lower();
	Quaternion qrot( vl, vl.magnitude() * -game->dt );
	Quaternion qconj;

	x += v.upper() * game->dt;
	q = qrot * q;


	qconj = q.getConjugate();
	if ( qconj.magnitude() > 1.001 )
	{
		swprintf_s( msgbox_tchar, _T("part::apply_velocity\nq.magnitude %f\nqconj.magnitude %f\n%f %f %f %f\n%f %f %f %f"),
			q.magnitude(), qconj.magnitude(),
			q.w,q.v.col[0],q.v.col[1],q.v.col[2],
			qconj.w,qconj.v.col[0],qconj.v.col[1],qconj.v.col[2]);
		MessageBox(NULL, msgbox_tchar, NULL, MB_OK);
	}
}
