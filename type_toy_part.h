class TOY_PART: public PART
{
public:
	RECTANGULAR_PARALLELEPIPED<PART> rp;

	TOY_PART();

	// virtual
	void collide  ( OBJECT * object );
	void collision( POLYHEDRON<PART> * polyhedron );
	void interact( OBJECT * o );
	bool interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist );
	void physics_apply_force_virt( Vector3 force, Vector3 moment );
	void physics_apply_velocity_virt();
	void render();
};
