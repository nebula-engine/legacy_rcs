class CAR_BODY: public PART
{
public:
	// pivot point and axis for each wheel in part-coor
	Vector3 P[4];
	Vector3 axis[4];

	// body shape
	RECTANGULAR_PARALLELEPIPED<PART> * rp;

	CAR_BODY(){};
	CAR_BODY( float width, float depth, float height );
};
