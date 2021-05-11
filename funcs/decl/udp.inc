{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

  (* uv_udp_t is a subclass of uv_handle_t. *)
  (* uv_udp_send_t is a subclass of uv_req_t. *)

function uv_udp_init(loop: puv_loop_t; handle: puv_udp_t): integer; cdecl;

function uv_udp_init_ex(
    loop: puv_loop_t;
    handle: puv_udp_t;
    flags: UInt
) : integer; cdecl;

function uv_udp_open(handle: puv_udp_t; sock: uv_os_sock_t): integer; cdecl;

function uv_udp_bind(
    handle: puv_udp_t;
    const addr: TSockAddr_in_any;
    flags: UInt
): integer; cdecl;

function uv_udp_connect(
    handle: puv_udp_t;
    const addr: TSockAddr_in_any
) : integer; cdecl;

function uv_udp_getsockname(
    handle: puv_udp_t;
    name: psockaddr;
    var namelen: integer
): integer; cdecl;

function uv_udp_getpeername(
    handle: puv_udp_t;
    name: psockaddr;
    var namelen: integer
): integer; cdecl;

function uv_udp_get_send_queue_count(const handle: puv_udp_t): SIZE_T;
function uv_udp_get_send_queue_size(const handle: puv_udp_t): SIZE_T;

function uv_udp_set_membership(
    handle: puv_udp_t;
    multicast_addr: PUTF8Char;
    interface_addr: PUTF8Char;
    membership: uv_membership
): integer; cdecl;

function uv_udp_set_multicast_loop(
    handle: puv_udp_t;
    &on: integer
) : integer; cdecl;

function uv_udp_set_multicast_ttl(
    handle: puv_udp_t;
    ttl: integer
) : integer; cdecl;

function uv_udp_set_multicast_interface(
    handle: puv_udp_t;
    interface_addr: PUTF8Char
) : integer; cdecl;

function uv_udp_set_broadcast(handle: puv_udp_t; &on: integer) : integer; cdecl;

function uv_udp_set_ttl(handle: puv_udp_t; ttl: integer): integer; cdecl;

function uv_udp_send(
    req: puv_udp_send_t;
    handle: puv_udp_t;
    const bufs: puv_buf_t;
    nbufs: UInt;
    addr: psockaddr;
    send_cb: uv_udp_send_cb
) : integer; cdecl;

function uv_udp_try_send(
    handle: puv_udp_t;
    const bufs: puv_buf_t;
    nbufs: UInt;
    addr: psockaddr
) : integer; cdecl;

function uv_udp_recv_start(
    handle: puv_udp_t;
    alloc_cb: uv_alloc_cb;
    recv_cb: uv_udp_recv_cb
): integer; cdecl;

function uv_udp_recv_stop(handle: puv_udp_t): integer; cdecl;
