class OBJECT
{
public:
    GAME * game;
	
	bool fixed;

	float health;
    int region_x_ind;
    int region_z_ind;
    OBJECT_TYPE object_type;

    OBJECT();
	
	// virtual
	virtual void collide  ( OBJECT * o ){};
	virtual void collision( POLYHEDRON<PART> * polyhedron ){};
	virtual void interact( INTERACT_TYPE type ){};
	virtual bool interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist ){ return false; };
	virtual Vector3 O(){ return Vector3(); };
	virtual void render(){};
	virtual void physics_apply_force_virt(){};
	virtual void physics_apply_velocity_virt(){};
};

/*

class DERIVED_OBJECT
{

	// virtual
	void collide  ( POLYHEDRON * polyhedron );
	void collision( OBJECT * o );
	void interact( INTERACT_TYPE type );
	bool interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist );
	Vector3 O();
	void render();
	void physics();

};

void DERIVED_OBJECT::collide  ( POLYHEDRON * polyhedron )
{
}

void DERIVED_OBJECT::collision( OBJECT * o )
{
}

void DERIVED_OBJECT::interact( INTERACT_TYPE type )
{
}

bool DERIVED_OBJECT::interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist )
{
	return false;
}

Vector3 DERIVED_OBJECT::O()
{
	return Vector3();
}

void DERIVED_OBJECT::render()
{
}

void DERIVED_OBJECT::physics()
{
}


*/