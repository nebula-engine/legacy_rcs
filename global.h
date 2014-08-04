TCHAR msgbox_tchar[512];

SOCKET_CLASS * server = new SOCKET_CLASS;
SOCKET_BUFFER * buf = new SOCKET_BUFFER;

Vector3 X(1.0f,0.0f,0.0f);
Vector3 Y(0.0f,1.0f,0.0f);
Vector3 Z(0.0f,0.0f,1.0f);

DISP_MODE disp_mode = DM_NORMAL;

VCLIP<PART> vclip;