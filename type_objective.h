class OBJECTIVE_DATA
{
public:
	OB_STATE state;
    OB_TYPE  type;
    OB_WHOM  whom;
	
	Vector3Base wp;
	float prox;
    int level;
	MARINE * lower;
	int lower_id;

	void set(const OBJECTIVE_DATA &param)
	{
		state = param.state;
		type  = param.type;
		whom  = param.whom;
	
		wp    = param.wp;
		prox  = param.prox;
		level = param.level;
		lower_id = param.lower_id;
	};
};

class OBJECTIVE
{
public:
    OBJECTIVE_DATA data;
    
    std::vector<MARINE*> lower_pointer_vector;
    std::vector<OBJECTIVE*> spawn_pointer_vector;

	int dim;

	void setWP( float param )
	{
		data.wp.col[dim] = param;
	}

	void setProx( float param )
	{
		data.prox = param;
	}

	void operator= (OBJECTIVE_DATA param)
	{
		data.state = param.state;
		data.type  = param.type;
		data.whom  = param.whom;
	
		data.wp    = param.wp;
		data.prox  = param.prox;
		data.level = param.level;
		data.lower_id = param.lower_id;
	}
};
