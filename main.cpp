#include <winsock2.h>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>
#include <cstdlib>
#include <iostream>

// Constants
#include "constants.h"

// definitions
#include "types.h"

// function prototypes
#include "proto.h"
#include "server_proto.h"

// global variable declarations
HWND hWnd;

char str[64];

std::vector<SOCKET_CLASS*> * client_pointer_vector = new std::vector<SOCKET_CLASS*>;

SOCKET_CLASS * server = new SOCKET_CLASS;
SOCKET_BUFFER * buf = new SOCKET_BUFFER;
int next_client_id = 0;

int (*packet_handler)( SOCKET_CLASS * client ) = server_socket_process_msg;
int (*error_handler)( SOCKET_CLASS * client, int error ) = server_socket_error;

std::vector<GAME*> game_pointer_vector;

std::vector<WEAPON*> weapon_pointer_vector;

BOX * box_marine_body = NULL;
BOX * box_terminal = NULL;

int next_game_id = 0;

float * forward = new float[3];
float * backward = new float[3];
float * right = new float[3];
float * left = new float[3];

// function definitions
#include "class_methods.h"
#include "functions.h"
#include "server_functions.h"

using namespace std;

int main(int argc, char *argv[])
{
    MSG messages;
    RECT rect;
    int counter = 0;
    printf("CTRL_AI = %i\n\n",CTRL_AI);
    printf("SD_GEN        %i\n",sizeof(SD_GEN));
    printf("SD_POSUP      %i\n",sizeof(SD_POSUP));
    printf("SD_JOIN       %i\n",sizeof(SD_JOIN));
    printf("SD_CTRLCHANGE %i\n",sizeof(SD_CTRLCHANGE));
    printf("SD_CO         %i\n",sizeof(SD_CO));
    
    buf->error_handler = error_handler;
    
    game_init();
    
    server_socket_core_create_listen_socket();
    
    bool loop = true;
    while (loop)
    {
        server_socket_core_accept_clients();
        server_socket_core_recv();
        
        server_region_detect_change_all();
        
        counter++;
        if ( counter > 10 )
        {
           server_ai_update();
           server_physics_marine_all();
           server_objective_check_all();
           server_socket_pos_up_all();
           counter = 0;
        }
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
