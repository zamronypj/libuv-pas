{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

function uv_get_constants; external LIBUV_FILE;

function uv_version; external LIBUV_FILE;

function uv_version_string; external LIBUV_FILE;

function uv_replace_allocator; external LIBUV_FILE;

function uv_default_loop; external LIBUV_FILE;

function uv_loop_init; external LIBUV_FILE;

function uv_loop_close; external LIBUV_FILE;

function uv_loop_new; external LIBUV_FILE;

procedure uv_loop_delete; external LIBUV_FILE;

function uv_loop_size; external LIBUV_FILE;

function uv_loop_alive; external LIBUV_FILE;

function uv_loop_configure; external LIBUV_FILE;

function uv_run; external LIBUV_FILE;

procedure uv_stop; external LIBUV_FILE;

procedure uv_ref; external LIBUV_FILE;

procedure uv_unref; external LIBUV_FILE;

function uv_has_ref; external LIBUV_FILE;

procedure uv_update_time; external LIBUV_FILE;

function uv_no; external LIBUV_FILE;

function uv_backend_fd; external LIBUV_FILE;

function uv_backend_timeout; external LIBUV_FILE;

function uv_strerror; external LIBUV_FILE;

function uv_err_name; external LIBUV_FILE;

function uv_shutdown; external LIBUV_FILE;

function uv_handle_size; external LIBUV_FILE;

function uv_is_active; external LIBUV_FILE;

procedure uv_walk; external LIBUV_FILE;

procedure uv_print_all_handles; external LIBUV_FILE;

procedure uv_print_active_handles; external LIBUV_FILE;

procedure uv_close; external LIBUV_FILE;

function uv_send_buffer_size; external LIBUV_FILE;

function uv_recv_buffer_size; external LIBUV_FILE;

function uv_fileno; external LIBUV_FILE;

// function uv_buf_init; external LIBUV_FILE;

function uv_listen; external LIBUV_FILE;

function uv_accept; external LIBUV_FILE;

function uv_read_start; external LIBUV_FILE;

function uv_read_stop; external LIBUV_FILE;

function uv_write; external LIBUV_FILE;

function uv_write2; external LIBUV_FILE;

function uv_try_write; external LIBUV_FILE;

function uv_is_readable; external LIBUV_FILE;

function uv_is_writable; external LIBUV_FILE;

function uv_stream_set_blocking; external LIBUV_FILE;

function uv_is_closing; external LIBUV_FILE;

function uv_tcp_init; external LIBUV_FILE;

function uv_tcp_init_ex; external LIBUV_FILE;

function uv_tcp_open; external LIBUV_FILE;

function uv_tcp_nodelay; external LIBUV_FILE;

function uv_tcp_keepalive; external LIBUV_FILE;

function uv_tcp_simultaneous_accepts; external LIBUV_FILE;

function uv_tcp_bind; external LIBUV_FILE;

function uv_tcp_getsockname; external LIBUV_FILE;

function uv_tcp_getpeername; external LIBUV_FILE;

function uv_tcp_connect; external LIBUV_FILE;
function uv_udp_init; external LIBUV_FILE;

function uv_udp_init_ex; external LIBUV_FILE;

function uv_udp_open; external LIBUV_FILE;

function uv_udp_bind; external LIBUV_FILE;

function uv_udp_connect; external LIBUV_FILE;
function uv_udp_getpeername; external LIBUV_FILE;
function uv_udp_getsockname; external LIBUV_FILE;
function uv_udp_get_send_queue_count; external LIBUV_FILE;
function uv_udp_get_send_queue_size; external LIBUV_FILE;

function uv_udp_set_membership; external LIBUV_FILE;

function uv_udp_set_multicast_loop; external LIBUV_FILE;

function uv_udp_set_multicast_ttl; external LIBUV_FILE;

function uv_udp_set_multicast_interface; external LIBUV_FILE;

function uv_udp_set_broadcast; external LIBUV_FILE;

function uv_udp_set_ttl; external LIBUV_FILE;

function uv_udp_send; external LIBUV_FILE;

function uv_udp_try_send; external LIBUV_FILE;

function uv_udp_recv_start; external LIBUV_FILE;

function uv_udp_recv_stop; external LIBUV_FILE;

function uv_tty_init; external LIBUV_FILE;

function uv_tty_set_mode; external LIBUV_FILE;

function uv_tty_reset_mode; external LIBUV_FILE;

function uv_tty_get_winsize; external LIBUV_FILE;
function uv_guess_handle; external LIBUV_FILE;

function uv_pipe_init; external LIBUV_FILE;

function uv_pipe_open; external LIBUV_FILE;

function uv_pipe_bind; external LIBUV_FILE;

procedure uv_pipe_connect; external LIBUV_FILE;

function uv_pipe_getsockname; external LIBUV_FILE;

function uv_pipe_getpeername; external LIBUV_FILE;

procedure uv_pipe_pending_instances; external LIBUV_FILE;

function uv_pipe_pending_count; external LIBUV_FILE;

function uv_pipe_pending_type; external LIBUV_FILE;

function uv_pipe_chmod; external LIBUV_FILE;

function uv_poll_init; external LIBUV_FILE;

function uv_poll_init_socket; external LIBUV_FILE;

function uv_poll_start; external LIBUV_FILE;

function uv_poll_stop; external LIBUV_FILE;

function uv_prepare_init; external LIBUV_FILE;

function uv_prepare_start; external LIBUV_FILE;

function uv_prepare_stop; external LIBUV_FILE;

function uv_check_init; external LIBUV_FILE;

function uv_check_start; external LIBUV_FILE;

function uv_check_stop; external LIBUV_FILE;

function uv_idle_init; external LIBUV_FILE;

function uv_idle_start; external LIBUV_FILE;

function uv_idle_stop; external LIBUV_FILE;

function uv_async_init; external LIBUV_FILE;

function uv_async_send; external LIBUV_FILE;

function uv_timer_init; external LIBUV_FILE;

function uv_timer_start; external LIBUV_FILE;

function uv_timer_stop; external LIBUV_FILE;

function uv_timer_again; external LIBUV_FILE;

procedure uv_timer_set_repeat; external LIBUV_FILE;

function uv_timer_get_repeat; external LIBUV_FILE;

function uv_getaddrinfo; external LIBUV_FILE;

procedure uv_freeaddrinfo; external LIBUV_FILE;

function uv_getnameinfo; external LIBUV_FILE;

function uv_spawn; external LIBUV_FILE;

function uv_process_kill; external LIBUV_FILE;

function uv_process_getpid; external LIBUV_FILE;

function uv_kill; external LIBUV_FILE;

function uv_queue_work; external LIBUV_FILE;

function uv_cancel; external LIBUV_FILE;
function uv_req_size; external LIBUV_FILE;
function uv_req_get_data; external LIBUV_FILE;
procedure uv_req_set_data; external LIBUV_FILE;
function uv_req_get_type; external LIBUV_FILE;
function uv_req_type_name; external LIBUV_FILE;

function uv_setup_args; external LIBUV_FILE;

function uv_get_process_title; external LIBUV_FILE;

function uv_set_process_title; external LIBUV_FILE;

function uv_resident_set_memory; external LIBUV_FILE;

function uv_uptime; external LIBUV_FILE;

function uv_getrusage; external LIBUV_FILE;

function uv_os_homedir; external LIBUV_FILE;

function uv_os_tmpdir; external LIBUV_FILE;

function uv_os_get_passwd; external LIBUV_FILE;

procedure uv_os_free_passwd; external LIBUV_FILE;

function uv_os_getpid; external LIBUV_FILE;

function uv_cpu_info; external LIBUV_FILE;

procedure uv_free_cpu_info; external LIBUV_FILE;

function uv_interface_addresses; external LIBUV_FILE;

procedure uv_free_interface_addresses; external LIBUV_FILE;

procedure uv_fs_req_cleanup; external LIBUV_FILE;

function uv_fs_get_type; external LIBUV_FILE;
function uv_fs_get_path; external LIBUV_FILE;
function uv_fs_get_ptr; external LIBUV_FILE;
function uv_fs_get_result; external LIBUV_FILE;
function uv_fs_get_statbuf; external LIBUV_FILE;

function uv_fs_close; external LIBUV_FILE;

function uv_fs_open; external LIBUV_FILE;

function uv_fs_read; external LIBUV_FILE;

function uv_fs_unlink; external LIBUV_FILE;

function uv_fs_write; external LIBUV_FILE;

function uv_fs_mkdir; external LIBUV_FILE;

function uv_fs_mkdtemp; external LIBUV_FILE;

function uv_fs_rmdir; external LIBUV_FILE;

function uv_fs_scandir; external LIBUV_FILE;

function uv_fs_scandir_next; external LIBUV_FILE;

function uv_fs_stat; external LIBUV_FILE;

function uv_fs_fstat; external LIBUV_FILE;

function uv_fs_rename; external LIBUV_FILE;

function uv_fs_copyfile; external LIBUV_FILE;

function uv_fs_fsync; external LIBUV_FILE;

function uv_fs_fdatasync; external LIBUV_FILE;

function uv_fs_ftruncate; external LIBUV_FILE;

function uv_fs_sendfile; external LIBUV_FILE;

function uv_fs_access; external LIBUV_FILE;

function uv_fs_chmod; external LIBUV_FILE;

function uv_fs_utime; external LIBUV_FILE;

function uv_fs_futime; external LIBUV_FILE;

function uv_fs_lstat; external LIBUV_FILE;

function uv_fs_link; external LIBUV_FILE;

function uv_fs_symlink; external LIBUV_FILE;

function uv_fs_readlink; external LIBUV_FILE;

function uv_fs_realpath; external LIBUV_FILE;

function uv_fs_fchmod; external LIBUV_FILE;

function uv_fs_chown; external LIBUV_FILE;

function uv_fs_fchown; external LIBUV_FILE;

function uv_fs_poll_init; external LIBUV_FILE;

function uv_fs_poll_start; external LIBUV_FILE;

function uv_fs_poll_stop; external LIBUV_FILE;

function uv_fs_poll_getpath; external LIBUV_FILE;

function uv_signal_init; external LIBUV_FILE;

function uv_signal_start; external LIBUV_FILE;

function uv_signal_stop; external LIBUV_FILE;

procedure uv_loadavg; external LIBUV_FILE;

function uv_fs_event_init; external LIBUV_FILE;

function uv_fs_event_start; external LIBUV_FILE;

function uv_fs_event_stop; external LIBUV_FILE;

function uv_fs_event_getpath; external LIBUV_FILE;

function uv_get_osfhandle(fd: uv_file): uv_os_fd_t;
begin
  result := uv_os_fd_t(fd);
end;

function uv_ip4_addr; external LIBUV_FILE;

function uv_ip6_addr; external LIBUV_FILE;

function uv_ip4_name; external LIBUV_FILE;

function uv_ip6_name; external LIBUV_FILE;

function uv_inet_ntop; external LIBUV_FILE;

function uv_inet_pton; external LIBUV_FILE;

function uv_exepath; external LIBUV_FILE;

function uv_cwd; external LIBUV_FILE;

function uv_chdir; external LIBUV_FILE;

function uv_get_free_memory; external LIBUV_FILE;

function uv_get_total_memory; external LIBUV_FILE;

function uv_hrtime; external LIBUV_FILE;

procedure uv_disable_stdio_inheritance; external LIBUV_FILE;

function uv_dlopen; external LIBUV_FILE;

procedure uv_dlclose; external LIBUV_FILE;

function uv_dlsym; external LIBUV_FILE;

function uv_dlerror; external LIBUV_FILE;

function uv_mutex_init; external LIBUV_FILE;

procedure uv_mutex_destroy; external LIBUV_FILE;

procedure uv_mutex_lock; external LIBUV_FILE;

function uv_mutex_trylock; external LIBUV_FILE;

procedure uv_mutex_unlock; external LIBUV_FILE;

function uv_rwlock_init; external LIBUV_FILE;

procedure uv_rwlock_destroy; external LIBUV_FILE;

procedure uv_rwlock_rdlock; external LIBUV_FILE;

function uv_rwlock_tryrdlock; external LIBUV_FILE;

procedure uv_rwlock_rdunlock; external LIBUV_FILE;

procedure uv_rwlock_wrlock; external LIBUV_FILE;

function uv_rwlock_trywrlock; external LIBUV_FILE;

procedure uv_rwlock_wrunlock; external LIBUV_FILE;

function uv_sem_init; external LIBUV_FILE;

procedure uv_sem_destroy; external LIBUV_FILE;

procedure uv_sem_post; external LIBUV_FILE;

procedure uv_sem_wait; external LIBUV_FILE;

function uv_sem_trywait; external LIBUV_FILE;

function uv_cond_init; external LIBUV_FILE;

procedure uv_cond_destroy; external LIBUV_FILE;

procedure uv_cond_signal; external LIBUV_FILE;

procedure uv_cond_broadcast; external LIBUV_FILE;

function uv_barrier_init; external LIBUV_FILE;

procedure uv_barrier_destroy; external LIBUV_FILE;

function uv_barrier_wait; external LIBUV_FILE;

procedure uv_cond_wait; external LIBUV_FILE;

function uv_cond_timedwait; external LIBUV_FILE;

procedure uv_once; external LIBUV_FILE;

function uv_key_create; external LIBUV_FILE;

procedure uv_key_delete; external LIBUV_FILE;

procedure uv_key_get; external LIBUV_FILE;

procedure uv_key_set; external LIBUV_FILE;

function uv_thread_create; external LIBUV_FILE;

function uv_thread_self; external LIBUV_FILE;

function uv_thread_join; external LIBUV_FILE;

function uv_thread_equal; external LIBUV_FILE;

function uv_rwlock_size; external LIBUV_FILE;
function uv_cond_size; external LIBUV_FILE;
function uv_barrier_size; external LIBUV_FILE;
function uv_sem_size; external LIBUV_FILE;
function uv_mutex_size; external LIBUV_FILE;
function uv_os_sock_size; external LIBUV_FILE;
function uv_os_fd_size; external LIBUV_FILE;
function uv_tcp_accept_size; external LIBUV_FILE;
function uv_pipe_accept_size; external LIBUV_FILE;
// function uv_buf_size; external LIBUV_FILE;
// function uv_process_options_size; external LIBUV_FILE;

procedure uv_set_close_cb; external LIBUV_FILE;
function uv_get_close_cb; external LIBUV_FILE;
function uv_get_handle_type; external LIBUV_FILE;
procedure uv_set_user_data; external LIBUV_FILE;
function uv_get_user_data; external LIBUV_FILE;
function uv_get_req_type; external LIBUV_FILE;

function uv_get_process_pid; external LIBUV_FILE;

function uv_now; external LIBUV_FILE;

// procedure uv_buf_set; external LIBUV_FILE;

function uv_buf_init(Base: PByte; len: Cardinal): uv_buf_t;
begin
  result.len := len;
  result.Base := Base;
end;

function malloc_func(size: SIZE_T): Pointer; cdecl;
begin
  GetMem(result, size);
end;

function realloc_func(ptr: Pointer; size: SIZE_T): Pointer; cdecl;
begin
  result := ptr;
  ReallocMem(result, size);
end;

function calloc_func(count: SIZE_T; size: SIZE_T): Pointer; cdecl;
begin
  result := malloc_func(size * count);
end;

procedure free_func(ptr: Pointer); cdecl;
begin
  FreeMem(ptr);
end;

// procedure __async_cb(async: puv_async_t);cdecl;
// begin
// //Dispose(async);
// end;
//
// procedure WakeupLoop(loop: puv_loop_t);
// var
// dlawup: puv_async_t;
// begin
// new(dlawup);
// uv_async_init(loop, @dlawup, @__async_cb);
// uv_async_send(@dlawup);
// end;
{$Q-,O+}
// function _octal(oct:integer) : integer;
// var
// o1,o2,o3: integer;
// begin
/// /  result := 0;
/// /  o := 0;
/// /  while oct > 0 do
/// /  begin
/// /    tmp := oct mod 10 and 7;
/// /    o := (o shl 3) or tmp;
/// /    oct := oct div 10;
/// /  end;
/// /  while o > 0 do
/// /  begin
/// /    result := result shl 3;
/// /    result := result or (o and 7);
/// /    o := o shr 3;
/// /  end;
// o1 := (oct mod 10) and 7;
// o2 := (oct div 10 mod 10) and 7;
// o3 := (oct div 100 mod 10) and 7;
// result := o1 or (o2 shl 3) or (o3 shl 6);
// end;

function uv_get_ip_port(src: PSockAddr_In): word;
begin
  assert(src <> nil);
  result := ntohs(src.sin_port);
end;

procedure uv_set_ip_port(src: PSockAddr_In; Port: word);
begin
  src.sin_port := htons(Port);
end;

function UV_ONCE_INIT: uv_once_t;
begin
  result := default (uv_once_t);
end;

