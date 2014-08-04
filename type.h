class BOX;
class GAME;
struct ORG_MAP_LEVEL;
class SOCKET_CLASS;
class SOCKET_DATA;
class MARINE;
class MARINE_BODY;
class OBJECT;
class OBJECTIVE;
class PART;
class REGION;
class SPAWN;
class SURFACE_RECTANGLE;
class TOY;
class UNIT_VECTORS;
class VEHICLE;
class WEAPON;
class TAG;

class TAGBase
{
public:
	int a[NUM_LEVEL];

	void operator= (TAG param);
};

class TAG
{
public:
	int a[NUM_LEVEL];

	TAG()
	{
		_for(i,NUM_LEVEL)
		{
			a[i] = -1;
		}
	}

	void operator= (TAG param)
	{
		_for(i,NUM_LEVEL)
		{
			a[i] = param.a[i];
		}
	}
};

void TAGBase::operator= (TAG param)
{
	_for(i,NUM_LEVEL)
	{
		a[i] = param.a[i];
	}
}

#include "type_object.h"
#include "type_part.h"

#include "type_marine_body.h"
#include "type_marine.h"

#include "type_objective.h"

#include "type_terminal.h"

struct ORG_MAP_LEVEL
{
    MARINE * m;
    ORG_MAP_LEVEL * level[3];
};

struct DISPCHAR
{
    char c[64];
};

class REGION
{
public:
    float front;
    float back;
    float right;
    float left;
    std::vector<OBJECT*> marine_pointer_vector;
    std::vector<OBJECT*> terminal_pointer_vector;
};

#include "type_game.h"

class WEAPON
{
public:
    float cooldown;
    float damage;

	WEAPON( float cooldownParam, float damageParam ) : cooldown(cooldownParam), damage(damageParam){};
};

class SPAWN
{
public:
    TAG tag;
    Vector3 O;
	SPAWN(){};

	void operator= (const SPAWN &param)
	{
		tag = param.tag;
		O = param.O;
	}
};

class INTERACT_HIT
{
public:
	OBJECT * object;
	float dist;

	INTERACT_HIT()
	{
		object = NULL;
		dist = 0;
	}
};

#include "type_vehicle.h"
#include "type_car_body.h"
#include "type_wheel.h"
#include "type_car.h"

#include "types_socket.h"

#include "type_toy_part.h"
#include "type_toy.h"


#include "type_surface_part.h"
#include "type_surface.h"
