struct SD_GEN
{
    Vector3Base x;
	QuaternionBase q;
	Vector3Base v;
	Vector3Base r;
    int int1[8];
    int len;
    TAGBase tag;
    int id;
    int game_id;
};

struct SD_POSUP
{
    struct MARINE_POS
    {
        Vector3Base x;
    	QuaternionBase q;
    } marine_pos[10];
    int id[10];
    int len;
};

struct SD_JOIN
{
    int game_id;
    int my_id;
    float health[10];
    int id[10];
    int len;
};

struct SD_CTRLCHANGE
{
    int game_id;
    int marine_id;
    
    bool move_w;
    bool move_s;
    bool move_a;
    bool move_d;
    
    bool jump;
    bool mousel;
    bool mouser;
};

struct SD_CO
{
    int creator_id;
	int lower_id;
	OBJECTIVE_DATA data;
};

class SOCKET_DATA
{
public:
    int len;
    SOCK_MSG_TYPE type;
    union
    {
        char text[64];
        SD_GEN gen;
        SD_POSUP posup;
        SD_JOIN join;
        SD_CTRLCHANGE cc;
        SD_CO co;
    };
};

class SOCKET_BUFFER
{
public:
    union 
    {
        char str[SOCK_BUF_LEN];
        SOCKET_DATA data;
    };
    int (*error_handler)( SOCKET_CLASS * recipient, int error );
    SOCKET_BUFFER();
    void len();
    void send_buf( SOCKET_CLASS * recipient );
};

class SOCKET_CLASS
{
public:
    //int id;
    int marine_id;
    int game_id;
    MARINE * marine;
    GAME * game;
    SOCKET s;
    SOCKET_BUFFER buf;
    int buf_pos;
    int remaining_data_len;
    int (*packet_handler)( SOCKET_CLASS * client );
    int (*error_handler)( SOCKET_CLASS * recipient, int error );
    SOCKET_CLASS();
    void rec();
    void handler();
};

class SOCKET_CLASS_CLIENT: public SOCKET_CLASS
{
private:
	static int next_client_id;
public:
	SOCKET_CLASS_CLIENT();
};