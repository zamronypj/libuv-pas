{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

type

    {--------------start callback type declarations------------------}
    uv_connection_cb = procedure(server: puv_stream_t; Status: integer); cdecl;
    uv_check_cb = procedure(handle: puv_check_t); cdecl;
    uv_connect_cb = procedure(req: puv_connect_t; Status: integer); cdecl;
    uv_close_cb = procedure(handle: puv_handle_t); cdecl;
    uv_shutdown_cb = procedure(req: puv_shutdown_t; Status: integer); cdecl;
    uv_prepare_cb = procedure(handle: puv_prepare_t); cdecl;
    uv_idle_cb = procedure(handle: puv_idle_t); cdecl;
    uv_async_cb = procedure(handle: puv_async_t); cdecl;
    uv_signal_cb = procedure(handle: puv_signal_t; signum: integer); cdecl;
    uv_fs_cb = procedure(req: puv_fs_t); cdecl;
    uv_work_cb = procedure(req: puv_work_t); cdecl;
    uv_after_work_cb = procedure(req: puv_work_t; Status: integer); cdecl;

    uv_exit_cb = procedure(
        process: puv_process_t;
        exit_status: Int64;
        term_signal: integer
    ); cdecl;

    uv_fs_event_cb = procedure(
        handle: puv_fs_event_t;
        filename: PUTF8Char;
        Events: integer;
        Status: integer
    ); cdecl;

    uv_udp_send_cb = procedure(req: puv_udp_send_t; Status: integer); cdecl;

    uv_udp_recv_cb = procedure(
        handle: puv_udp_t;
        nread: SSIZE_T;
        buf: puv_buf_t;
        addr: psockaddr;
        flags: UInt
    ); cdecl;

    uv_alloc_cb = procedure(
        handle: puv_handle_t;
        suggested_size: SIZE_T;
        buf: puv_buf_t
    ); cdecl;

    uv_read_cb = procedure(
        stream: puv_stream_t;
        nread: SSIZE_T;
        const buf: puv_buf_t
    ); cdecl;

    uv_write_cb = procedure(req: puv_write_t; Status: integer); cdecl;

    uv_poll_cb = procedure(
        handle: puv_poll_t;
        Status: integer;
        Events: integer
    ); cdecl;

    uv_timer_cb = procedure(handle: puv_timer_t); cdecl;

    uv_malloc_func = function(size: SIZE_T): Pointer; cdecl;
    uv_realloc_func = function(ptr: Pointer; size: SIZE_T): Pointer; cdecl;
    uv_calloc_func = function(count: SIZE_T; size: SIZE_T): Pointer; cdecl;
    uv_free_func = procedure(ptr: Pointer); cdecl;

    uv_walk_cb = procedure(handle: puv_handle_t; arg: pinteger); cdecl;

    uv_getaddrinfo_cb = procedure(
        req: puv_getaddrinfo_t;
        Status: integer;
        res: PAddrInfo
    ); cdecl;

    uv_getnameinfo_cb = procedure(
        req: puv_getnameinfo_t;
        Status: integer;
        hostname: PUTF8Char;
        service: PUTF8Char
    ); cdecl;

    uv_fs_poll_cb = procedure(
        handle: puv_fs_poll_t;
        Status: integer;
        prev: puv_stat_t;
        curr: puv_stat_t
    ); cdecl;

    TOnceProcedure = procedure; cdecl;


    uv_thread_cb = procedure(arg: Pointer); cdecl;

    {--------------end callback type declarations------------------}
