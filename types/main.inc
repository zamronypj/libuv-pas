{$IFDEF MSWINDOWS}

type
    SIZE_T = NativeUInt;
    psize_t = ^SIZE_T;
    SSIZE_T = NativeInt;
    uv_os_sock_t = TSOCKET;
    uv_os_fd_t = THANDLE;

    uv_thread_t = THANDLE;
    uv_sem_t = THANDLE;

    uv_uid_t = Byte;
    uv_gid_t = Byte;
    uv_pid_t = integer;

    uv_lib_t = record
        handle: HMODULE;
        errmsg: PAnsiChar;
    end;

    uv_once_t = record
        ran: Byte;
        event: THANDLE;
    end;

    uv_key_t = record
        tls_index: DWORD;
    end;

    uv_buf_t = record
        case Boolean of
            true:
                (
                    cast: WSABUF
                );
            false:
                (
                    len: { size_t } u_long;
                    Base: PByte;
                );
    end;
{$ENDIF}

{$IFDEF WINDOWS}
const

    sizeof_os_sock_t = sizeof(uv_os_sock_t);
    sizeof_os_fd_t = sizeof(uv_os_fd_t);

{$ENDIF}
