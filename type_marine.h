class MARINE: public OBJECT
{
public:
    int id;
    TAG tag;

    CTRL_TYPE control;
    
    Vector3 move_v;
    
    bool move_w;
    bool move_s;
    bool move_a;
    bool move_d;
    
    bool jump;
    bool mousel;
    bool mouser;
    
    Vector3 eag_pos;
    
	float vely;

    SOCKET_CLASS * client;
    std::vector<OBJECTIVE*> objective_pointer_vector;
    MARINE * ai_target;
    WEAPON * weapon;
    
    clock_t next_shot;
    clock_t last_move;
    clock_t last_rotate;
    
    ORG_MAP_LEVEL * level;
    
	MARINE_BODY body;

	// constructor
    MARINE( GAME * g, TAG &tag_param, std::vector<WEAPON*> &weapons, ORG_MAP_LEVEL * om_level );

    void stop();
	void fire();
	
	// virtual
	void collide  ( POLYHEDRON<PART> * polyhedron );
	void collision( OBJECT * object );
	void interact( INTERACT_TYPE type );
	bool interact_return( INTERACT_TYPE type, const Vector3 &O, const Vector3 &v, float &dist );
	Vector3 O();
	void render();
	void physics();
};
