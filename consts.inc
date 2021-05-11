{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

const

    UV_EOF = -4095;
    UV_ECANCELED = -4081;
    UV_ENOBUFS = -4060;
    UV_DEFAULT_PORT = 0;
    UV_DEFAULT_BACKLOG = SOMAXCONN;
    UV_AF_INET = AF_INET;
    UV_AF_INET6 = AF_INET6;

    UV_STDIN_FD = 0;
    UV_STDOUT_FD = 1;
    UV_STDERR_FD = 2;

    UV_READABLE = 1;
    UV_WRITABLE = 2;
    UV_DISCONNECT = 4;
    UV_PRIORITIZED = 8;

const

{$IFDEF WINDOWS}
    LIBUV_FILE = 'libuv.dll';
{$ENDIF}
{$IFDEF UNIX}
    LIBUV_FILE = 'libuv.so';
{$ENDIF}

{$IFDEF WIN32}
const
    sizeof_loop_t = 256;
    sizeof_async_t = 116;
    sizeof_check_t = 60;
    sizeof_fs_event_t = 140;
    sizeof_fs_poll_t = 52;
    sizeof_handle_t = 48;
    sizeof_idle_t = 60;
    sizeof_pipe_t = 320;
    sizeof_poll_t = 256;
    sizeof_prepare_t = 60;
    sizeof_process_t = 136;
    sizeof_stream_t = 144;
    sizeof_tcp_t = 168;
    sizeof_timer_t = 96;
    sizeof_tty_t = 196;
    sizeof_udp_t = 288;
    sizeof_signal_t = 136;
    sizeof_req_t = 60;
    sizeof_connect_t = 68;
    sizeof_write_t = 92;
    sizeof_shutdown_t = 68;
    sizeof_udp_send_t = 68;
    sizeof_fs_t = 312;
    sizeof_work_t = 92;
    sizeof_addrinfo_t = 112;
    sizeof_nameinfo_t = 1288;
    sizeof_rwlock_t = 48;
    sizeof_cond_t = 36;
    sizeof_barrier_t = 40;
    sizeof_mutex_t = 24;

{$ENDIF}

{$IFDEF WIN64}
const

    sizeof_loop_t = 464;
    sizeof_async_t = 224;
    sizeof_check_t = 120;
    sizeof_fs_event_t = 272;
    sizeof_fs_poll_t = 104;
    sizeof_handle_t = 96;
    sizeof_idle_t = 120;
    sizeof_pipe_t = 576;
    sizeof_poll_t = 416;
    sizeof_prepare_t = 120;
    sizeof_process_t = 264;
    sizeof_stream_t = 272;
    sizeof_tcp_t = 320;
    sizeof_timer_t = 160;
    sizeof_tty_t = 344;
    sizeof_udp_t = 424;
    sizeof_signal_t = 264;
    sizeof_req_t = 112;
    sizeof_connect_t = 128;
    sizeof_write_t = 176;
    sizeof_shutdown_t = 128;
    sizeof_udp_send_t = 128;
    sizeof_fs_t = 456;
    sizeof_work_t = 176;
    sizeof_addrinfo_t = 216;
    sizeof_nameinfo_t = 1368;
    sizeof_rwlock_t = 80;
    sizeof_cond_t = 64;
    sizeof_barrier_t = 64;
    sizeof_mutex_t = 40;
{$ENDIF}


{$INCLUDE consts/fs.inc}