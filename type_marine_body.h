class MARINE_BODY: public PART
{
public:
	RECTANGULAR_PARALLELEPIPED<PART> * rp;

	MARINE_BODY();

	void interact( INTERACT_TYPE interact_type, OBJECT * parent_object );
	bool interact_return( const Vector3 &O, const Vector3 &v, float &dist );
	void render();
	void physics();
	void collision();
};
