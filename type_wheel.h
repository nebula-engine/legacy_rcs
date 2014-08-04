class WHEEL: public PART
{
public:
	// pivot point and axis in part-coor
	Vector3 P;
	Vector3 axis;

	// wheel shape
	CIRCULAR_CYLINDER<PART> * cc;

	WHEEL(){};
	WHEEL( float radius, float width, float offset_x, float offset_y, float offset_z, float p, float n, float s, float P_z );
};
