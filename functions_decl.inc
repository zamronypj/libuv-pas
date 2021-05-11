{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

function uv_get_constants: Pnodepas_constants;

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


{$INCLUDE funcs/decl/tcp.inc}

{$INCLUDE funcs/decl/udp.inc}

{$INCLUDE funcs/decl/tty.inc}

function uv_guess_handle(&file: uv_file): uv_handle_type; cdecl;

{$INCLUDE funcs/decl/pipe.inc}

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

{$INCLUDE funcs/decl/timer.inc}

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

{$INCLUDE funcs/decl/fs.inc}

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

function uv_ip4_addr(ip: PAnsiChar; Port: integer; out addr: Tsockaddr_in)
  : integer; cdecl;

function uv_ip6_addr(ip: PAnsiChar; Port: integer; out addr: Tsockaddr_in6)
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