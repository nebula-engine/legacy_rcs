class PART
{
public:
	OBJECT * object;
	
	// part
    float a_x;
    float a_y;

	// global to part
	Quaternion q;

	// global
	Vector3 x;

	//global/part
	Vector6 v;
	Vector6 H;

	// part-coor --> principal-coor
	float precession;
	float nutation;
	float spin;

	// part
	Vector3 eye_offset;
	Vector3 COM;
	Matrix3 I;
	Matrix6 M;
	Matrix6 Minv;

	
	// temp
	Vector6 f;

	float m;

	// time
	//float dt;
	//float T;

	PART();
	void calcuate_constants( int num, ... );
	void rotate( const Vector3 &axis, float angle );
	
	void _gluLookAt();
	void _glPushMatrix();

	void collision_part_rectangle( RECTANGULAR_PARALLELEPIPED<PART> * rp, SURFACE_RECTANGLE * rect );

	void update_dt();
	void physics_apply_force( Vector3 F, Vector3 M );
	void physics_apply_velocity();


	// virtuals
	virtual void collide  ( OBJECT * object ){};
	virtual void collision( POLYHEDRON<PART> * polyhedron ){};
	virtual void interact( OBJECT * o ){};
	virtual bool interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist ){ return false; };
	virtual void render(){};
	virtual void physics_apply_force_virt(){};
};

/*

class DERIVED_PART
{

	// virtuals
	void collide  ( OBJECT * object );
	void collision( POLYHEDRON * polyhedron );
	void interact( OBJECT * o );
	bool interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist );
	void render();
	void physics();

}





void DERIVED_PART::collide  ( OBJECT * object )
{
}

void DERIVED_PART::collision( POLYHEDRON * polyhedron )
{
}

void DERIVED_PART::interact( OBJECT * o )
{
}

bool DERIVED_PART::interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist )
{
	return false;
}

void DERIVED_PART::render()
{
}

void DERIVED_PART::physics()
{
}


*/