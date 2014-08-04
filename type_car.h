class CAR: public VEHICLE
{
public:
	CAR_BODY body;
	WHEEL wheel[4];

	CAR( float width, float depth, float height );
	void physics();
	void render();
};
