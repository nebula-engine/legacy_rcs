class GAME
{
private:
	int next_marine_id;
	static int next_game_id;
public:
    int id;
	std::vector<OBJECT*>    objects;
    
    std::vector<MARINE*>    marines;
    std::vector<TERMINAL*>  terminals;
    std::vector<TOY*>       toys;
	std::vector<VEHICLE*>   vehicles;

    std::vector<OBJECTIVE*> objectives;
    
	std::vector<WEAPON*>    weapons;

	OBJECTIVE tempObjective;

	

    ORG_MAP_LEVEL * level[2];
    int org_lvl;

    float * region_x;
    float * region_z;
    int region_nx;
    int region_nz;
    REGION * r;

	clock_t T;
	float dt;

    GAME();
	GAME( int level );

	void update_dt();
	void game_create_recursive( int level, TAG tag, int org_lvl, ORG_MAP_LEVEL * om_level, int * numAtLevel, int a );
	int get_next_marine_id();
};

int GAME::next_game_id = 0;
