{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}


(*
 * uv_tcp_t is a subclass of uv_stream_t.
 *
 * Represents a TCP stream or TCP server.
 *)

function uv_tcp_init(loop: puv_loop_t; handle: puv_tcp_t): integer; cdecl;

function uv_tcp_init_ex(
    loop: puv_loop_t;
    handle: puv_tcp_t;
    flags: UInt
) : integer; cdecl;

function uv_tcp_open(handle: puv_tcp_t; sock: uv_os_sock_t): integer; cdecl;

function uv_tcp_nodelay(handle: puv_tcp_t; enable: integer): integer; cdecl;

function uv_tcp_keepalive(
    handle: puv_tcp_t;
    enable: integer;
    delay: UInt
) : integer; cdecl;

function uv_tcp_simultaneous_accepts(
    handle: puv_tcp_t;
    enable: integer
) : integer; cdecl;

function uv_tcp_bind(
    handle: puv_tcp_t;
    const addr: TSockAddr_in_any;
    flags: UInt
): integer; cdecl;

function uv_tcp_getsockname(
    handle: puv_tcp_t;
    out name: TSockAddr_in_any;
    var namelen: integer
): integer; cdecl;

function uv_tcp_getpeername(
    handle: puv_tcp_t;
    out name: TSockAddr_in_any;
    var namelen: integer
): integer; cdecl;

(* uv_connect_t is a subclass of uv_req_t. *)

function uv_tcp_connect(
    req: puv_connect_t;
    handle: puv_tcp_t;
    addr: PSockAddr_in_any;
    cb: uv_connect_cb
): integer; cdecl;

