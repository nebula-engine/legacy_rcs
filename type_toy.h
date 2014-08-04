class TOY: public OBJECT
{
public:
	TOY_PART toy_part;

	// virtual
	void collide  ( OBJECT * o );
	void collision( POLYHEDRON<PART> * polyhedron );
	void interact( INTERACT_TYPE type );
	bool interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist );
	Vector3 O();
	void render();
	void physics_apply_force_virt();
	void physics_apply_velocity_virt();
};
