class SURFACE_PART: public PART
{
public:
	Vector3 v1;
	Vector3 v2;
	Vector3 v3;

	Vector3 n;

	float C;

	SURFACE_PART( float O_x, float O_y, float O_z, float width, float depth, float pr, float nu, float sp );

	SQUARE<PART> square;

	// virtuals
	void collide  ( OBJECT * object );
	void collision( POLYHEDRON<PART> * polyhedron );
	void interact( OBJECT * o );
	bool interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist );
	void render();
	void physics();
};
