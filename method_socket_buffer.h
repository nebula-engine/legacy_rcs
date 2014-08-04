SOCKET_BUFFER::SOCKET_BUFFER()
{
    error_handler = NULL;
}

void SOCKET_BUFFER::len()
{
    switch ( data.type )
    {
    case SM_CLI_CREATEGAME:
        data.len = 8 + sizeof(SD_GEN);
        break;
    case SM_CLI_JOINGAME:
        data.len = 8 + sizeof(SD_JOIN);
        break;
    case SM_CLI_REQUGAME:
        data.len = 8 + sizeof(SD_GEN);
        break;
    case SM_CLI_POSUP:
        data.len = 8 + sizeof(SD_GEN);
        break;
    case SM_CLI_SENDSHOT:
        data.len = 8 + sizeof(SD_GEN);
        break;
    case SM_CLI_EXITGAME:
        data.len = 8 + sizeof(SD_GEN);
        break;
    case SM_CLI_DISCONNECT:
        data.len = 8 + sizeof(SD_GEN);
        break;
    case SM_CLI_CTRLCHANGE:
        data.len = 8 + sizeof(SD_GEN);
        break;
    case SM_CLI_CO:
        data.len = 8 + sizeof(SD_CO);
        break;
    case SM_SRV_CREATEGAME:
        data.len = 8 + sizeof(SD_GEN);
        break;
    case SM_SRV_JOINGAME:
        data.len = 8 + sizeof(SD_JOIN);
        break;
    case SM_SRV_REQUGAME:
        data.len = 8 + sizeof(SD_GEN);
        break;
    case SM_SRV_POSUP:
        data.len = 8 + sizeof(SD_GEN);
        break;
    case SM_SRV_POSUPALL:
        data.len = 8 + sizeof(SD_POSUP);
        break;
    case SM_SRV_VICTIM:
        data.len = 8 + sizeof(SD_GEN);
        break;
    case SM_SRV_CO:
        data.len = 8 + sizeof(SD_CO);
        break;
    case SM_SRV_BLANK:
        data.len = 8;
        break;
    default:
        MessageBox( NULL, TEXT("SOCKET_BUFFER::len"), NULL, 0 );
        break;
    }
}

void SOCKET_BUFFER::send_buf( SOCKET_CLASS * recipient )
{
	if ( error_handler == NULL )
    {
		swprintf_s( msgbox_tchar, _T("SOCKET_BUFFER::send_buf error_handler=NULL" ));
        MessageBox( NULL, msgbox_tchar, NULL, 0 );
        return;
    }
    int result = send( recipient->s, str, data.len, 0);
    int error;
    if ( result == SOCKET_ERROR )
    {
        error = WSAGetLastError();
        if ( error != WSAEWOULDBLOCK )
        {
            (*error_handler)( recipient, error );
            swprintf_s( msgbox_tchar, _T("SOCKET_BUFFER::send_buf %i"), error );
            MessageBox( NULL, msgbox_tchar, NULL, 0 );
        }
    }
}
