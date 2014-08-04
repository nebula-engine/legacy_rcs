void SOCKET_CLASS::handler()
{
    if ( packet_handler == NULL )
    {
         MessageBox( NULL, TEXT("SOCKET_CLASS::handler packet_handler is NULL"), NULL, 0 );
    } else {
        (*packet_handler)( this );
    }
}

SOCKET_CLASS::SOCKET_CLASS()
{
    s = INVALID_SOCKET;
    buf_pos = 0;
    remaining_data_len = 0;
    packet_handler = NULL;
	error_handler = NULL;
}

void SOCKET_CLASS::rec()
{
    int result = 0;
	char temp_buf[SOCK_BUF_LEN];
	int temp_buf_pos = 0;

	if ( s != INVALID_SOCKET )
	{
		do
		{
			result = recv(s, temp_buf, SOCK_BUF_LEN, 0);
			//MessageBox( NULL, "2", NULL, 0 );
			if ( result > 0 )
			{
				//memset( &temp_buf[result], '\0', 1 );
				//MessageBox( NULL, "3", NULL, 0 );
				temp_buf_pos = 0;
				while ( temp_buf_pos < result )
				{
					if ( remaining_data_len == 0 )
					{
						//MessageBox( NULL, "4a", NULL, 0 );
						memcpy( buf.str, &temp_buf[temp_buf_pos], 4);
						remaining_data_len = buf.data.len - 4;
                    
						temp_buf_pos += 4;
						buf_pos += 4;
					}
					else
					{
						//MessageBox( NULL, "4b", NULL, 0 );
						if ( remaining_data_len > ( result - temp_buf_pos ) )
						{
							//MessageBox( NULL, "5", NULL, 0 );
							memcpy( &buf.str[buf_pos], &temp_buf[temp_buf_pos], (result - temp_buf_pos));
                        
							buf_pos += result - temp_buf_pos;
							remaining_data_len -= result - temp_buf_pos;
							temp_buf_pos = result;
						}
						else
						{
							//MessageBox( NULL, "6", NULL, 0 );
							memcpy( &buf.str[buf_pos], &temp_buf[temp_buf_pos], remaining_data_len);
							//MessageBox( NULL, "7", NULL, 0 );
							temp_buf_pos += remaining_data_len;
							buf_pos += remaining_data_len;
							remaining_data_len = 0;
                        
							handler();
							//printf("%s\n", buf.data.text);
                        
							buf_pos = 0;
						}
					}
				}
			}
			else
			{
				int error = WSAGetLastError();
				if ( error != WSAEWOULDBLOCK )
				{
					swprintf_s( msgbox_tchar, _T("SOCKET_CLASS::rec %i"), error );
					MessageBox( NULL, msgbox_tchar, NULL, 0 );
					(*error_handler)( this, error );
				}
			}
		} while (result > 0);
	}
}

