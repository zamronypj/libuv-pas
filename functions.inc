{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}


function UV_ONCE_INIT: uv_once_t;

function uv_version: UInt; cdecl;

function uv_version_string: PUTF8Char; cdecl;


function uv_replace_allocator(
    malloc_func: uv_malloc_func;
    realloc_func: uv_realloc_func;
    calloc_func: uv_calloc_func;
    free_func: uv_free_func
): integer; cdecl;

function uv_default_loop: puv_loop_t; cdecl;

function uv_loop_init(loop: puv_loop_t): integer; cdecl;

function uv_loop_close(loop: puv_loop_t): integer; cdecl;

(*
 * NOTE:
 *  This function is DEPRECATED (to be removed after 0.12), users should
 *  allocate the loop manually and use uv_loop_init instead.
 *)
function uv_loop_new: puv_loop_t; cdecl;

(*
 * NOTE:
 *  This function is DEPRECATED (to be removed after 0.12). Users should use
 *  uv_loop_close and free the memory manually instead.
 *)
procedure uv_loop_delete(loop: puv_loop_t); cdecl;

function uv_loop_size: SIZE_T; cdecl;

function uv_loop_alive(loop: puv_loop_t): integer; cdecl;

function uv_loop_configure(
    loop: puv_loop_t;
    option: uv_loop_option
): integer; varargs; cdecl;

function uv_run(loop: puv_loop_t; mode: uv_run_mode): integer; cdecl;

procedure uv_stop(loop: puv_loop_t); cdecl;

procedure uv_ref(loop: puv_handle_t); cdecl;

procedure uv_unref(handle: puv_handle_t); cdecl;

function uv_has_ref(const handle: puv_handle_t): integer; cdecl;

procedure uv_update_time(loop: puv_loop_t); cdecl;

function uv_no(loop: puv_loop_t): UInt64; cdecl;

function uv_backend_fd(const loop: puv_loop_t): integer; cdecl;

function uv_backend_timeout(const loop: puv_loop_t): integer; cdecl;

function uv_strerror(err: integer): PAnsiChar; cdecl;

function uv_err_name(err: integer): PAnsiChar; cdecl;

function uv_shutdown(
    req: puv_shutdown_t;
    handle: puv_stream_t;
    cb: uv_shutdown_cb
): integer; cdecl;

function uv_handle_size(&type: uv_handle_type): SIZE_T; cdecl;

function uv_cancel(req: puv_req_t): integer; cdecl;
function uv_req_size(&type: uv_req_type): SIZE_T; cdecl;
function uv_req_get_data(const req: puv_req_t): Pointer; cdecl;
procedure uv_req_set_data(const req: puv_req_t; data: Pointer); cdecl;
function uv_req_get_type(const req: puv_req_t): uv_req_type; cdecl;
function uv_req_type_name(const req: puv_req_t): PAnsiChar; cdecl;

function uv_is_active(handle: puv_handle_t): integer; cdecl;

procedure uv_walk(loop: puv_loop_t; walk_cb: uv_walk_cb; arg: pinteger); cdecl;

(* Helpers for ad hoc debugging, no API/ABI stability guaranteed. *)
procedure uv_print_all_handles(loop: puv_loop_t; stream: Pointer); cdecl;
procedure uv_print_active_handles(loop: puv_loop_t; stream: Pointer); cdecl;

procedure uv_close(handle: puv_handle_t; close_cb: uv_close_cb); cdecl;

function uv_send_buffer_size(
    handle: puv_handle_t;
    value: pinteger
) : integer; cdecl;

function uv_recv_buffer_size(
    handle: puv_handle_t;
    value: pinteger
) : integer; cdecl;

function uv_fileno(handle: puv_handle_t; var fd: uv_os_fd_t): integer; cdecl;

function uv_buf_init(Base: PByte; len: Cardinal): uv_buf_t;

function uv_listen(
    stream: puv_stream_t;
    backlog: integer;
    cb: uv_connection_cb
) : integer; cdecl;

function uv_accept(server: puv_stream_t; client: puv_stream_t): integer; cdecl;

function uv_read_start(
    req: puv_stream_t;
    alloc_cb: uv_alloc_cb;
    read_cb: uv_read_cb
): integer; cdecl;

function uv_read_stop(req: puv_stream_t): integer; cdecl;

function uv_write(
    req: puv_write_t;
    handle: puv_stream_t;
    const bufs: puv_buf_t;
    nbufs: UInt;
    cb: uv_write_cb
): integer; cdecl;

function uv_write2(
    req: puv_write_t;
    handle: puv_stream_t;
    const bufs: puv_buf_t;
    nbufs: UInt;
    send_handle: puv_stream_t;
    cb: uv_write_cb
): integer; cdecl;

function uv_try_write(
    handle: puv_stream_t;
    const bufs: puv_buf_t;
    nbufs: UInt
): integer;

(* uv_write_t is a subclass of uv_req_t. *)

function uv_is_readable(handle: puv_stream_t): integer; cdecl;

function uv_is_writable(handle: puv_stream_t): integer; cdecl;

function uv_stream_set_blocking(
    handle: puv_stream_t;
    blocking: integer
) : integer; cdecl;

function uv_is_closing(handle: puv_handle_t): integer; cdecl;

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
    const addr: sockaddr;
    flags: UInt
): integer; cdecl;

function uv_tcp_getsockname(
    handle: puv_tcp_t;
    out name: sockaddr;
    var namelen: integer
): integer; cdecl;

function uv_tcp_getpeername(
    handle: puv_tcp_t;
    out name: sockaddr;
    var namelen: integer
): integer; cdecl;

(* uv_connect_t is a subclass of uv_req_t. *)

function uv_tcp_connect(
    req: puv_connect_t;
    handle: puv_tcp_t;
    addr: psockaddr;
    cb: uv_connect_cb
): integer; cdecl;


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
    const addr: sockaddr;
    flags: UInt
): integer; cdecl;

function uv_udp_connect(
    handle: puv_udp_t;
    const addr: sockaddr
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

function uv_udp_get_send_queue_count(const handle: puv_udp_t): SIZE_T;cdecl;
function uv_udp_get_send_queue_size(const handle: puv_udp_t): SIZE_T;cdecl;

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


function uv_tty_init(
    loop: puv_loop_t;
    tty: puv_tty_t;
    os_fd: uv_file;
    unused: integer
) : integer; cdecl;

function uv_tty_set_mode(tty: puv_tty_t; mode: uv_tty_mode_t): integer; cdecl;

function uv_tty_reset_mode: integer; cdecl;

function uv_tty_get_winsize(
    tty: puv_tty_t;
    var width, height: integer
) : integer; cdecl;

function uv_guess_handle(&file: uv_file): uv_handle_type; cdecl;

(*
  * uv_pipe_t is a subclass of uv_stream_t.
  *
  * Representing a pipe stream or pipe server. On Windows this is a Named
  * Pipe. On Unix this is a Unix domain socket.
*)

function uv_pipe_init(
    loop: puv_loop_t;
    handle: puv_pipe_t;
    ipc: integer
) : integer; cdecl;

function uv_pipe_open(pipe: puv_pipe_t; os_fd: uv_file): integer; cdecl;

function uv_pipe_bind(handle: puv_pipe_t; name: PUTF8Char): integer; cdecl;

procedure uv_pipe_connect(
    req: puv_connect_t;
    handle: puv_pipe_t;
    name: PUTF8Char;
    cb: uv_connect_cb
); cdecl;

function uv_pipe_getsockname(
    handle: puv_pipe_t;
    buffer: PUTF8Char;
    var size: SIZE_T
): integer; cdecl;

function uv_pipe_getpeername(
    handle: puv_pipe_t;
    buffer: PUTF8Char;
    var size: SIZE_T
): integer; cdecl;

procedure uv_pipe_pending_instances(handle: puv_pipe_t; count: integer); cdecl;

function uv_pipe_pending_count(handle: puv_pipe_t): integer; cdecl;

function uv_pipe_pending_type(handle: puv_pipe_t): uv_handle_type; cdecl;

function uv_pipe_chmod(handle: puv_pipe_t; flags: integer): integer; cdecl;

function uv_poll_init(loop: puv_loop_t; handle: puv_poll_t; fd: integer)
  : integer; cdecl;

function uv_poll_init_socket(loop: puv_loop_t; handle: puv_poll_t;
  socket: uv_os_sock_t): integer; cdecl;

function uv_poll_start(handle: puv_poll_t; Events: integer; cb: uv_poll_cb)
  : integer; cdecl;

function uv_poll_stop(handle: puv_poll_t): integer; cdecl;

function uv_prepare_init(loop: puv_loop_t; prepare: puv_prepare_t)
  : integer; cdecl;

function uv_prepare_start(prepare: puv_prepare_t; cb: uv_prepare_cb)
  : integer; cdecl;

function uv_prepare_stop(prepare: puv_prepare_t): integer; cdecl;

function uv_check_init(loop: puv_loop_t; check: puv_check_t): integer; cdecl;

function uv_check_start(check: puv_check_t; cb: uv_check_cb): integer; cdecl;

function uv_check_stop(check: puv_check_t): integer; cdecl;

function uv_idle_init(loop: puv_loop_t; idle: puv_idle_t): integer; cdecl;

function uv_idle_start(idle: puv_idle_t; cb: uv_idle_cb): integer; cdecl;

function uv_idle_stop(idle: puv_idle_t): integer; cdecl;

function uv_async_init(loop: puv_loop_t; async: puv_async_t;
  async_cb: uv_async_cb): integer; cdecl;

function uv_async_send(async: puv_async_t): integer; cdecl;
(*
  * uv_timer_t is a subclass of uv_handle_t.
  *
  * Used to get woken up at a specified time in the future.
*)

function uv_timer_init(loop: puv_loop_t; handle: puv_timer_t): integer; cdecl;

function uv_timer_start(handle: puv_timer_t; cb: uv_timer_cb; Timeout: UInt64;
  &repeat: UInt64): integer; cdecl;

function uv_timer_stop(handle: puv_timer_t): integer; cdecl;

function uv_timer_again(handle: puv_timer_t): integer; cdecl;

procedure uv_timer_set_repeat(handle: puv_timer_t; &repeat: UInt64); cdecl;

function uv_timer_get_repeat(handle: puv_timer_t): UInt64; cdecl;
(*
  * uv_getaddrinfo_t is a subclass of uv_req_t.
  *
  * Request object for uv_getaddrinfo.
*)

function uv_getaddrinfo(loop: puv_loop_t; req: puv_getaddrinfo_t;
  getaddrinfo_cb: uv_getaddrinfo_cb; const node: PAnsiChar;
  const service: PAnsiChar; hints: PAddrInfo): integer; cdecl;

procedure uv_freeaddrinfo(ai: PAddrInfo); cdecl;
(*
  * uv_getnameinfo_t is a subclass of uv_req_t.
  *
  * Request object for uv_getnameinfo.
*)
function uv_getnameinfo(loop: puv_loop_t; req: puv_getnameinfo_t;
  getnameinfo_cb: uv_getnameinfo_cb; addr: psockaddr; flags: integer)
  : integer; cdecl;
(* uv_spawn() options. *)
{ !!!3 unknown typedef }

function uv_spawn(loop: puv_loop_t; handle: puv_process_t;
  const options: puv_process_options_t): integer; cdecl;

function uv_process_kill(process: puv_process_t; signum: integer)
  : integer; cdecl;

function uv_process_getpid(process: puv_process_t): uv_pid_t; cdecl;

function uv_kill(pid: uv_pid_t; signum: integer): integer; cdecl;
(*
  * uv_work_t is a subclass of uv_req_t.
*)

function uv_queue_work(loop: puv_loop_t; req: puv_work_t; work_cb: uv_work_cb;
  after_work_cb: uv_after_work_cb): integer; cdecl;

function uv_setup_args(argc: integer; argv: PAnsiCharArray)
  : PAnsiCharArray; cdecl;

function uv_get_process_title(buffer: PAnsiChar; size: SIZE_T): integer; cdecl;

function uv_set_process_title(const title: PAnsiChar): integer; cdecl;

function uv_resident_set_memory(rss: psize_t): integer; cdecl;

function uv_uptime(uptime: pdouble): integer; cdecl;

function uv_getrusage(rusage: puv_rusage_t): integer; cdecl;

function uv_os_homedir(buffer: PAnsiChar; size: psize_t): integer; cdecl;

function uv_os_tmpdir(buffer: PAnsiChar; size: psize_t): integer; cdecl;

function uv_os_get_passwd(pwd: puv_passwd_t): integer; cdecl;

procedure uv_os_free_passwd(pwd: puv_passwd_t); cdecl;

function uv_os_getpid: uv_pid_t; cdecl;

function uv_cpu_info(var cpu_infos: puv_cpu_info_t; var count: integer)
  : integer; cdecl;

procedure uv_free_cpu_info(cpu_infos: puv_cpu_info_t; count: integer); cdecl;

function uv_interface_addresses(var addresses: puv_interface_address_t;
  var count: integer): integer; cdecl;

procedure uv_free_interface_addresses(addresses: puv_interface_address_t;
  count: integer); cdecl;

procedure uv_fs_req_cleanup(req: puv_fs_t); cdecl;

function uv_fs_get_type(const req: puv_fs_t): uv_fs_type; cdecl;
function uv_fs_get_path(const req: puv_fs_t): PUTF8Char; cdecl;
function uv_fs_get_ptr(const req: puv_fs_t): Pointer; cdecl;
function uv_fs_get_result(const req: puv_fs_t): SSIZE_T; cdecl;
function uv_fs_get_statbuf(const req: uv_fs_t): puv_stat_t; cdecl;

function uv_fs_close(loop: puv_loop_t; req: puv_fs_t; &file: uv_file;
  cb: uv_fs_cb): integer; cdecl;

function uv_fs_open(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  flags: integer; mode: integer; cb: uv_fs_cb): integer; cdecl;

function uv_fs_read(loop: puv_loop_t; req: puv_fs_t; &file: uv_file;
  bufs: puv_buf_t; nbufs: UInt; offset: Int64; cb: uv_fs_cb): integer; cdecl;

function uv_fs_unlink(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  cb: uv_fs_cb): integer; cdecl;

function uv_fs_write(loop: puv_loop_t; req: puv_fs_t; &file: uv_file;
  bufs: puv_buf_t; nbufs: UInt; offset: Int64; cb: uv_fs_cb): integer; cdecl;

function uv_fs_mkdir(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  mode: integer; cb: uv_fs_cb): integer; cdecl;

function uv_fs_mkdtemp(loop: puv_loop_t; req: puv_fs_t; tpl: PUTF8Char;
  cb: uv_fs_cb): integer; cdecl;

function uv_fs_rmdir(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  cb: uv_fs_cb): integer; cdecl;

function uv_fs_scandir(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  flags: integer; cb: uv_fs_cb): integer; cdecl;

function uv_fs_scandir_next(req: puv_fs_t; ent: puv_dirent_t): integer; cdecl;

function uv_fs_stat(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  cb: uv_fs_cb): integer; cdecl;

function uv_fs_fstat(loop: puv_loop_t; req: puv_fs_t; &file: uv_file;
  cb: uv_fs_cb): integer; cdecl;

function uv_fs_rename(loop: puv_loop_t; req: puv_fs_t; const path: PUTF8Char;
  const new_path: PUTF8Char; cb: uv_fs_cb): integer; cdecl;


function uv_fs_copyfile(loop: puv_loop_t; req: puv_fs_t; const path: PUTF8Char;
  const new_path: PUTF8Char; flags: integer; cb: uv_fs_cb): integer; cdecl;

function uv_fs_fsync(loop: puv_loop_t; req: puv_fs_t; &file: uv_file;
  cb: uv_fs_cb): integer; cdecl;

function uv_fs_fdatasync(loop: puv_loop_t; req: puv_fs_t; &file: uv_file;
  cb: uv_fs_cb): integer; cdecl;

function uv_fs_ftruncate(loop: puv_loop_t; req: puv_fs_t; &file: uv_file;
  offset: Int64; cb: uv_fs_cb): integer; cdecl;

function uv_fs_sendfile(loop: puv_loop_t; req: puv_fs_t; out_fd: uv_file;
  in_fd: uv_file; in_offset: Int64; length: SIZE_T; cb: uv_fs_cb)
  : integer; cdecl;

function uv_fs_access(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  mode: integer; cb: uv_fs_cb): integer; cdecl;

function uv_fs_chmod(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  mode: integer; cb: uv_fs_cb): integer; cdecl;

function uv_fs_utime(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  atime: Double; mtime: Double; cb: uv_fs_cb): integer; cdecl;

function uv_fs_futime(loop: puv_loop_t; req: puv_fs_t; &file: uv_file;
  atime: Double; mtime: Double; cb: uv_fs_cb): integer; cdecl;

function uv_fs_lstat(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  cb: uv_fs_cb): integer; cdecl;

function uv_fs_link(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  new_path: PUTF8Char; cb: uv_fs_cb): integer; cdecl;


function uv_fs_symlink(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  new_path: PUTF8Char; flags: integer; cb: uv_fs_cb): integer; cdecl;

function uv_fs_readlink(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  cb: uv_fs_cb): integer; cdecl;

function uv_fs_realpath(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  cb: uv_fs_cb): integer; cdecl;

function uv_fs_fchmod(loop: puv_loop_t; req: puv_fs_t; &file: uv_file;
  mode: integer; cb: uv_fs_cb): integer; cdecl;

function uv_fs_chown(loop: puv_loop_t; req: puv_fs_t; path: PUTF8Char;
  uid: uv_uid_t; gid: uv_gid_t; cb: uv_fs_cb): integer; cdecl;

function uv_fs_fchown(loop: puv_loop_t; req: puv_fs_t; &file: uv_file;
  uid: uv_uid_t; gid: uv_gid_t; cb: uv_fs_cb): integer; cdecl;

  (*
    * uv_fs_stat() based polling file watcher.
  *)

function uv_fs_poll_init(loop: puv_loop_t; handle: puv_fs_poll_t)
  : integer; cdecl;

function uv_fs_poll_start(handle: puv_fs_poll_t; poll_cb: uv_fs_poll_cb;
  path: PUTF8Char; interval: UInt): integer; cdecl;

function uv_fs_poll_stop(handle: puv_fs_poll_t): integer; cdecl;

function uv_fs_poll_getpath(handle: puv_fs_poll_t; buffer: PUTF8Char;
  size: psize_t): integer; cdecl;

function uv_signal_init(loop: puv_loop_t; handle: puv_signal_t): integer; cdecl;

function uv_signal_start(handle: puv_signal_t; signal_cb: uv_signal_cb;
  signum: integer): integer; cdecl;

function uv_signal_stop(handle: puv_signal_t): integer; cdecl;


procedure uv_loadavg(avg: uv_loadavg_param); cdecl;





function uv_fs_event_init(loop: puv_loop_t; handle: puv_fs_event_t)
  : integer; cdecl;

function uv_fs_event_start(handle: puv_fs_event_t; cb: uv_fs_event_cb;
  path: PUTF8Char; flags: UInt): integer; cdecl;

function uv_fs_event_stop(handle: puv_fs_event_t): integer; cdecl;

function uv_fs_event_getpath(handle: puv_fs_event_t; buffer: PUTF8Char;
  var size: SIZE_T): integer; cdecl;

function uv_get_osfhandle(fd: uv_file): uv_os_fd_t; inline;

function uv_ip4_addr(ip: PAnsiChar; Port: integer; out addr: sockaddr_in)
  : integer; cdecl;

function uv_ip6_addr(ip: PAnsiChar; Port: integer; out addr: sockaddr_in6)
  : integer; cdecl;

function uv_ip4_name(src: PSockAddr_In; dst: PAnsiChar; size: SIZE_T)
  : integer; cdecl;

function uv_get_ip_port(src: PSockAddr_In): word;
procedure uv_set_ip_port(src: PSockAddr_In; Port: word);

function uv_ip6_name(src: psockaddr_In6; dst: PAnsiChar; size: SIZE_T)
  : integer; cdecl;

function uv_inet_ntop(af: integer; src: pinteger; dst: PAnsiChar; size: SIZE_T)
  : integer; cdecl;

function uv_inet_pton(af: integer; src: PAnsiChar; out dst): integer; cdecl;

function uv_exepath(buffer: PUTF8Char; size: psize_t): integer; cdecl;

function uv_cwd(buffer: PUTF8Char; size: psize_t): integer; cdecl;

function uv_chdir(dir: PUTF8Char): integer; cdecl;

function uv_get_free_memory: UInt64; cdecl;

function uv_get_total_memory: UInt64; cdecl;

function uv_hrtime: UInt64; cdecl;

procedure uv_disable_stdio_inheritance; cdecl;

function uv_dlopen(filename: PUTF8Char; lib: puv_lib_t): integer; cdecl;

procedure uv_dlclose(lib: puv_lib_t); cdecl;

function uv_dlsym(lib: puv_lib_t; name: PUTF8Char; var ptr: Pointer)
  : integer; cdecl;

function uv_dlerror(lib: puv_lib_t): PUTF8Char; cdecl;

function uv_mutex_init(handle: puv_mutex_t): integer; cdecl;

procedure uv_mutex_destroy(handle: puv_mutex_t); cdecl;

procedure uv_mutex_lock(handle: puv_mutex_t); cdecl;

function uv_mutex_trylock(handle: puv_mutex_t): integer; cdecl;

procedure uv_mutex_unlock(handle: puv_mutex_t); cdecl;

function uv_rwlock_init(rwlock: puv_rwlock_t): integer; cdecl;

procedure uv_rwlock_destroy(rwlock: puv_rwlock_t); cdecl;

procedure uv_rwlock_rdlock(rwlock: puv_rwlock_t); cdecl;

function uv_rwlock_tryrdlock(rwlock: puv_rwlock_t): integer; cdecl;

procedure uv_rwlock_rdunlock(rwlock: puv_rwlock_t); cdecl;

procedure uv_rwlock_wrlock(rwlock: puv_rwlock_t); cdecl;

function uv_rwlock_trywrlock(rwlock: puv_rwlock_t): integer; cdecl;

procedure uv_rwlock_wrunlock(rwlock: puv_rwlock_t); cdecl;

function uv_sem_init(sem: puv_sem_t; value: UInt): integer; cdecl;

procedure uv_sem_destroy(sem: puv_sem_t); cdecl;

procedure uv_sem_post(sem: puv_sem_t); cdecl;

procedure uv_sem_wait(sem: puv_sem_t); cdecl;

function uv_sem_trywait(sem: puv_sem_t): integer; cdecl;

function uv_cond_init(cond: puv_cond_t): integer; cdecl;

procedure uv_cond_destroy(cond: puv_cond_t); cdecl;

procedure uv_cond_signal(cond: puv_cond_t); cdecl;

procedure uv_cond_broadcast(cond: puv_cond_t); cdecl;

function uv_barrier_init(barrier: puv_barrier_t; count: UInt): integer; cdecl;

procedure uv_barrier_destroy(barrier: puv_barrier_t); cdecl;

function uv_barrier_wait(barrier: puv_barrier_t): integer; cdecl;

procedure uv_cond_wait(cond: puv_cond_t; mutex: puv_mutex_t); cdecl;

function uv_cond_timedwait(cond: puv_cond_t; mutex: puv_mutex_t;
  Timeout: UInt64): integer; cdecl;

procedure uv_once(guard: puv_once_t; callback: TOnceProcedure)cdecl;

function uv_key_create(key: puv_key_t): integer; cdecl;

procedure uv_key_delete(key: puv_key_t); cdecl;

procedure uv_key_get(key: puv_key_t); cdecl;

procedure uv_key_set(key: puv_key_t; value: pinteger); cdecl;

function uv_thread_create(tid: puv_thread_t; entry: uv_thread_cb; arg: Pointer)
  : integer; cdecl;

function uv_thread_self: uv_thread_t; cdecl;

function uv_thread_join(tid: puv_thread_t): integer; cdecl;

function uv_thread_equal(t1: puv_thread_t; t2: puv_thread_t): integer; cdecl;
(* The presence of these unions force similar struct layout. *)

function uv_rwlock_size(): SIZE_T; cdecl;
function uv_cond_size(): SIZE_T; cdecl;
function uv_barrier_size(): SIZE_T; cdecl;
function uv_sem_size(): SIZE_T; cdecl;
function uv_mutex_size(): SIZE_T; cdecl;
function uv_os_sock_size(): SIZE_T; cdecl;
function uv_os_fd_size(): SIZE_T; cdecl;
function uv_tcp_accept_size(): SIZE_T; cdecl;
function uv_pipe_accept_size(): SIZE_T; cdecl;
// function uv_buf_size() : SIZE_T; cdecl;

procedure uv_set_close_cb(h: puv_handle_t; close_cb: uv_close_cb); cdecl;
function uv_get_close_cb(h: puv_handle_t): uv_close_cb; cdecl;

function uv_get_handle_type(h: puv_handle_t): uv_handle_type; cdecl;
procedure uv_set_user_data(h: Pointer; data: Pointer); cdecl;
function uv_get_user_data(h: Pointer): Pointer; cdecl;
function uv_get_req_type(t: puv_req_t): uv_req_type; cdecl;
// function uv_process_options_size : SIZE_T; cdecl;
function uv_get_process_pid(h: puv_process_t): integer; cdecl;

function uv_now(loop: puv_loop_t): UInt64; cdecl;

// procedure WakeupLoop(loop: puv_loop_t);
// procedure uv_buf_set(var buf:uv_buf_t; base:PByte; len: Cardinal); cdecl;
