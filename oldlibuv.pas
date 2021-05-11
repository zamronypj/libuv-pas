{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}
unit libuv;

interface

uses

    {$IFDEF MSWINDOWS}
    Windows,
    {$ENDIF}

    {$IFDEF UNIX}
    baseunix,
    unixtype,
    pthreads,
    {$ENDIF}

    sockets,
    sysutils;

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

type

    uv_handle_type = (
        UV_UNKNOWN_HANDLE = 0,
        UV_ASYNC,
        UV_CHECK,
        UV_FS_EVENT_,
        UV_FS_POLL,
        UV_HANDLE,
        UV_IDLE,
        UV_NAMED_PIPE,
        UV_POLL,
        UV_PREPARE,
        UV_PROCESS,
        UV_STREAM,
        UV_TCP,
        UV_TIMER,
        UV_TTY,
        UV_UDP,
        UV_SIGNAL,
        UV_FILE_,
        UV_HANDLE_TYPE_MAX
    );

    uv_req_type = (
        UV_UNKNOWN_REQ = 0,
        UV_REQ,
        UV_CONNECT,
        UV_WRITE_,
        UV_SHUTDOWN_,
        UV_UDP_SEND_,
        UV_FS,
        UV_WORK,
        UV_GETADDRINFO_,
        UV_GETNAMEINFO_,
        UV_ACCEPT_,
        UV_FS_EVENT_REQ,
        UV_POLL_REQ,
        UV_PROCESS_EXIT,
        UV_READ,
        UV_UDP_RECV,
        UV_WAKEUP,
        UV_SIGNAL_REQ,
        UV_REQ_TYPE_MAX
    );

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

{$INCLUDE consts.inc}

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

const

    sizeof_os_sock_t = sizeof(uv_os_sock_t);
    sizeof_os_fd_t = sizeof(uv_os_fd_t);

{$ENDIF}

{$IFDEF LINUX}
    {$IFDEF CPU32}
        {$DEFINE LINUX32}
    {$ENDIF}

    {$IFDEF CPU64}
        {$DEFINE LINUX64}
    {$ENDIF}
{$ENDIF}

{$IFDEF LINUX64}

const
    sizeof_loop_t = 848;
    sizeof_async_t = 128;
    sizeof_check_t = 120;
    sizeof_fs_event_t = 136;
    sizeof_fs_poll_t = 104;
    sizeof_handle_t = 96;
    sizeof_idle_t = 120;
    sizeof_pipe_t = 264;
    sizeof_poll_t = 160;
    sizeof_prepare_t = 120;
    sizeof_process_t = 136;
    sizeof_stream_t = 248;
    sizeof_tcp_t = 248;
    sizeof_timer_t = 152;
    sizeof_tty_t = 312;
    sizeof_udp_t = 216;
    sizeof_signal_t = 152;

    sizeof_req_t = 64;
    sizeof_connect_t = 96;
    sizeof_write_t = 192;
    sizeof_shutdown_t = 80;
    sizeof_udp_send_t = 320;
    sizeof_fs_t = 440;
    sizeof_work_t = 128;
    sizeof_addrinfo_t = 160;
    sizeof_nameinfo_t = 1320;

    sizeof_rwlock_t = 56;
    sizeof_cond_t = 48;
    sizeof_barrier_t = 32;
    // sizeof_sem_t = 32;
    sizeof_mutex_t = 40;
    // sizeof_os_sock_t = 4;
    // sizeof_os_fd_t  = 4;

type
    SIZE_T = NativeUInt;
    psize_t = ^SIZE_T;
    SSIZE_T = NativeInt;
    UInt = Cardinal;
    PAnsiChar = PUTF8Char;
    uv_os_sock_t = integer;
    uv_os_fd_t = integer;
    uv_thread_t = pthread_t;
    uv_sem_t = sem_t;
    uv_uid_t = uid_t;
    uv_gid_t = gid_t;
    uv_pid_t = pid_t;

    uv_lib_t = record
        handle: Pointer;
        errmsg: PAnsiChar;
    end;

    uv_once_t = pthread_once_t;
    uv_key_t = pthread_key_t;

    uv_buf_t = record
      case Boolean of
        true:
            (
                cast: iovec
            );
        false:
            (
                Base: PByte; { Pointer to data. }
                len: SIZE_T; { Length of data. }
            );

    end;
{$ENDIF}

type

    uv_mutex_t = record
        interval: array [1 .. sizeof_mutex_t] of Byte;
    end;

    puv_mutex_t = ^uv_mutex_t;

    uv_rwlock_t = record
        interval: array [1 .. sizeof_rwlock_t] of Byte;
    end;

    puv_rwlock_t = ^uv_rwlock_t;

    uv_cond_t = record
        interval: array [1 .. sizeof_cond_t] of Byte;
    end;

    puv_cond_t = ^uv_cond_t;

    uv_barrier_t = record
        interval: array [1 .. sizeof_barrier_t] of Byte;
    end;

    puv_barrier_t = ^uv_barrier_t;

    puv_os_fd_t = ^uv_os_fd_t;
    puv_os_sock_t = ^uv_os_sock_t;
    puv_thread_t = ^uv_thread_t;
    puv_sem_t = ^uv_sem_t;
    puv_lib_t = ^uv_lib_t;
    puv_once_t = ^uv_once_t;
    puv_key_t = ^uv_key_t;


    puv_handle_t = ^uv_handle_s;

    uv_file = uv_os_fd_t;

{$POINTERMATH ON}
    puv_buf_t = ^uv_buf_t;
    PAnsiCharArray = ^PAnsiChar;
{$POINTERMATH OFF}
    // uv_buf_array = array [0 .. 0] of uv_buf_t;
    // puv_buf_array = ^uv_buf_array;

    (* Request types. *)
    uv_req_s = record
        internal: array [1 .. sizeof_req_t] of Byte;
    end;

    uv_req_t = uv_req_s;
    puv_req_t = ^uv_req_t;

    uv_dirent_type_t = (
        UV_DIRENT_UNKNOWN,
        UV_DIRENT_FILE,
        UV_DIRENT_DIR,
        UV_DIRENT_LINK,
        UV_DIRENT_FIFO,
        UV_DIRENT_SOCKET,
        UV_DIRENT_CHAR,
        UV_DIRENT_BLOCK
    );


    uv_handle_s = record
        internal: array [1 .. sizeof_handle_t] of Byte;
    end;

    uv_handle_t = uv_handle_s;

    puv_signal_t = ^uv_signal_t;
    puv_work_t = ^uv_work_t;

    uv_write_s = record
        internal: array [1 .. sizeof_write_t] of Byte;
    end;

    uv_write_t = uv_write_s;
    puv_write_t = uv_write_s;

    uv_stream_s = record
        internal: array [1 .. sizeof_stream_t] of Byte;
    end;

    uv_stream_t = uv_stream_s;
    puv_stream_t = ^uv_stream_t;

    uv_tcp_s = packed record
        internal: array [1 .. sizeof_tcp_t] of Byte;
    end;

    uv_tcp_t = uv_tcp_s;
    puv_tcp_t = ^uv_tcp_t;

    uv_udp_s = record
        internal: array [1 .. sizeof_udp_t] of Byte;
    end;

    uv_udp_t = uv_udp_s;
    puv_udp_t = ^uv_udp_t;

    uv_pipe_s = packed record
        internal: array [1 .. sizeof_pipe_t] of Byte;
    end;

    uv_pipe_t = uv_pipe_s;
    puv_pipe_t = ^uv_pipe_t;

    uv_tty_s = packed record
        internal: array [1 .. sizeof_tty_t] of Byte;
    end;

    uv_tty_t = uv_tty_s;
    puv_tty_t = ^uv_tty_t;

    uv_poll_s = record
        internal: array [1 .. sizeof_poll_t] of Byte;
    end;

    uv_poll_t = uv_poll_s;
    puv_poll_t = ^uv_poll_t;

    uv_timer_s = record
        internal: array [1 .. sizeof_timer_t] of Byte;
    end;

    uv_timer_t = uv_timer_s;
    puv_timer_t = ^uv_timer_t;

    uv_prepare_s = record
        internal: array [1 .. sizeof_prepare_t] of Byte;
    end;

    uv_prepare_t = uv_prepare_s;
    puv_prepare_t = ^uv_prepare_t;

    uv_check_s = record
        internal: array [1 .. sizeof_check_t] of Byte;
    end;

    uv_check_t = uv_check_s;
    puv_check_t = ^uv_check_t;

    uv_idle_s = record
        internal: array [1 .. sizeof_idle_t] of Byte;
    end;

    uv_idle_t = uv_idle_s;
    puv_idle_t = ^uv_idle_t;

    uv_async_s = record
        internal: array [1 .. sizeof_async_t] of Byte;
    end;

    uv_async_t = uv_async_s;
    puv_async_t = ^uv_async_t;

    uv_process_s = record
        internal: array [1 .. sizeof_process_t] of Byte;
    end;

    uv_process_t = uv_process_s;
    puv_process_t = ^uv_process_t;

    uv_signal_s = record
        internal: array [1 .. sizeof_signal_t] of Byte;
    end;

    {$INCLUDE types/fs.inc}
    uv_signal_t = uv_signal_s;

    uv_getaddrinfo_s = record
        internal: array [1 .. sizeof_addrinfo_t] of Byte;
    end;

    uv_getaddrinfo_t = uv_getaddrinfo_s;
    puv_getaddrinfo_t = ^uv_getaddrinfo_t;

    uv_getnameinfo_s = record
      internal: array [1 .. sizeof_nameinfo_t] of Byte;
    end;

    uv_getnameinfo_t = uv_getnameinfo_s;
    puv_getnameinfo_t = ^uv_getnameinfo_t;

    uv_shutdown_s = record
        internal: array [1 .. sizeof_shutdown_t] of Byte;
    end;
    uv_shutdown_t = uv_shutdown_s;
    puv_shutdown_t = ^uv_shutdown_s;

    uv_connect_s = record
        internal: array [1 .. sizeof_connect_t] of Byte;
    end;

    uv_connect_t = uv_connect_s;
    puv_connect_t = ^uv_connect_t;

    // uv_udp_send_t is a subclass of uv_req_t.
    uv_udp_send_s = record
      internal: array [1 .. sizeof_udp_send_t] of Byte;
    end;

    uv_udp_send_t = uv_udp_send_s;
    puv_udp_send_t = ^uv_udp_send_t;



    uv_timespec_t = timespec;

    uv_stat_t = record
      st_dev: UInt64;
      st_mode: UInt64;
      st_nlink: UInt64;
      st_uid: UInt64;
      st_gid: UInt64;
      st_rdev: UInt64;
      st_ino: UInt64;
      st_size: UInt64;
      st_blksize: UInt64;
      st_blocks: UInt64;
      st_flags: UInt64;
      st_gen: UInt64;
      st_atim: uv_timespec_t;
      st_mtim: uv_timespec_t;
      st_ctim: uv_timespec_t;
      st_birthtim: uv_timespec_t;
    end;

    puv_stat_t = ^uv_stat_t;

    uv_work_s = record
      internal: array [1 .. sizeof_work_t] of Byte;
    end;

    uv_work_t = uv_work_s;

    uv_cpu_times_s = record
        user, nice, sys, idle, irq: UInt64;
    end;

    uv_cpu_info_s = record
        model: PAnsiChar;
        speed: integer;
        cpu_times: uv_cpu_times_s;
    end;

    uv_cpu_info_t = uv_cpu_info_s;
    puv_cpu_info_t = ^uv_cpu_info_t;

    uv_interface_address_s = record
      name: PAnsiChar;
      phys_addr: array [0 .. 5] of Byte;
      is_internal: integer;

      address: record
        case integer of
          0:
            (address4: sockaddr_in;);
          1:
            (address6: sockaddr_in6;);
      end;

      netmask: record
        case integer of
          0:
            (netmask4: sockaddr_in;);
          1:
            (netmask6: sockaddr_in6;);
      end;
    end;

    uv_interface_address_t = uv_interface_address_s;
    puv_interface_address_t = ^uv_interface_address_t;

    uv_dirent_s = record
        name: PAnsiChar;
        &type: uv_dirent_type_t;
    end;

    uv_dirent_t = uv_dirent_s;
    puv_dirent_t = ^uv_dirent_t;

    uv_passwd_s = record
        username: PAnsiChar;
        uid, gid: Long;
        shell, homedir: PAnsiChar;
    end;

    uv_passwd_t = uv_passwd_s;
    puv_passwd_t = ^uv_passwd_t;

    uv_membership = (UV_LEAVE_GROUP = 0, UV_JOIN_GROUP);

    uv_tcp_flags = (
        (* Used with uv_tcp_bind, when an IPv6 address is used. *)
        UV_TCP_IPV6ONLY = 1
    );

(*
  * UDP support.
*)
const

    (* Disables dual stack mode. *)
    UV_UDP_IPV6ONLY = 1;

    (*
     * Indicates message was truncated because read buffer was too small. The
     * remainder was discarded by the OS. Used in uv_udp_recv_cb.
     *)
    UV_UDP_PARTIAL = 2;

    (*
     * Indicates if SO_REUSEADDR will be set when binding the handle.
     * This sets the SO_REUSEPORT socket flag on the BSDs and OS X. On other
     * Unix platforms, it sets the SO_REUSEADDR flag.  What that means is that
     * multiple threads or processes can bind to the same address without error
     * (provided they all set the flag) but only the last one to bind will receive
     * any traffic, in effect "stealing" the port from the previous listener.
     *)
    UV_UDP_REUSEADDR = 4;


type

    (*
     * uv_tty_t is a subclass of uv_stream_t.
     *
     * Representing a stream for the console.
     *)
    uv_tty_mode_t = (
        (* Initial/normal terminal mode *)
        UV_TTY_MODE_NORMAL,

        (* Raw input mode (On Windows, ENABLE_WINDOW_INPUT is also enabled) *)
        UV_TTY_MODE_RAW,

        (* Binary-safe I/O mode for IPC (Unix-only) *)
        UV_TTY_MODE_IO
    );

// type

// uv_poll_event = (UV_READABLE = 1, UV_WRITABLE = 2, UV_DISCONNECT = 4, UV_PRIORITIZED=8);


(*
  * These are the flags that can be used for the uv_process_options.flags field.
*)
type
  uv_process_flags = (
    (*
      * Set the child process' user id. The user id is supplied in the `uid` field
      * of the options struct. This does not work on windows; setting this flag
      * will cause uv_spawn() to fail.
    *)
    UV_PROCESS_SETUID = (1 shl 0), UV_PROCESS_SETGID = (1 shl 1),
    (*
      * Set the child process' group id. The user id is supplied in the `gid`
      * field of the options struct. This does not work on windows setting this
      * flag will cause uv_spawn() to fail.
    *)
    UV_PROCESS_WINDOWS_VERBATIM_ARGUMENTS = (1 shl 2),
    (*
      * Do not wrap any arguments in quotes, or perform any other escaping, when
      * converting the argument list into a command line string. This option is
      * only meaningful on Windows systems. On Unix it is silently ignored.
    *)
    UV_PROCESS_DETACHED = (1 shl 3),
    (*
      * Spawn the child process in a detached state - this will make it a process
      * group leader, and will effectively enable the child to keep running after
      * the parent exits.  Note that the child process will still keep the
      * parent's event loop alive unless the parent process calls uv_unref() on
      * the child's process handle.
    *)
    UV_PROCESS_WINDOWS_HIDE = (1 shl 4)
    (*
      * Hide the subprocess console window that would normally be created. This
      * option is only meaningful on Windows systems. On Unix it is silently
      * ignored.
    *)
    );

  uv_process_flags_set = set of uv_process_flags;

  (*
    * uv_process_t is a subclass of uv_handle_t.
  *)
const
  UV_IGNORE = $00;
  UV_CREATE_PIPE = $01;
  UV_INHERIT_FD = $02;
  UV_INHERIT_STREAM = $04;

  (*
    * When UV_CREATE_PIPE is specified, UV_READABLE_PIPE and UV_WRITABLE_PIPE
    * determine the direction of flow, from the child process' perspective. Both
    * flags may be specified to create a duplex data stream.
  *)
  UV_READABLE_PIPE = $10;
  UV_WRITABLE_PIPE = $20;

type

  v_stdio_flags = Byte;

  uv_stdio_container_s = record
    flags: v_stdio_flags;
    case integer of
      0:
        (stream: puv_stream_t;);
      1:
        (fd: integer;);
  end;
{$POINTERMATH ON}

  puv_stdio_container_t = ^uv_stdio_container_t;
{$POINTERMATH OFF}
  uv_stdio_container_t = uv_stdio_container_s;

  uv_process_options_s = record
    exit_cb: uv_exit_cb; (* Called after the process exits. *)
    &file: PAnsiChar; (* Path to program to execute. *)
    (*
      * Command line arguments. args[0] should be the path to the program. On
      * Windows this uses CreateProcess which concatenates the arguments into a
      * string this can cause some strange errors. See the note at
      * windows_verbatim_arguments.
    *)
    args: PAnsiCharArray;
    (*
      * This will be set as the environ variable in the subprocess. If this is
      * NULL then the parents environ will be used.
    *)
    env: PAnsiCharArray;
    (*
      * If non-null this represents a directory the subprocess should execute
      * in. Stands for current working directory.
    *)
    cwd: PAnsiChar;
    (*
      * Various flags that control how uv_spawn() behaves. See the definition of
      * enum uv_process_flags` below.
    *)
    flags: uv_process_flags_set; // Cardinal;
    (*
      * The `stdio` field points to an array of uv_stdio_container_t structs that
      * describe the file descriptors that will be made available to the child
      * process. The convention is that stdio[0] points to stdin, fd 1 is used for
      * stdout, and fd 2 is stderr.
      *
      * Note that on windows file descriptors greater than 2 are available to the
      * child process only if the child processes uses the MSVCRT runtime.
    *)
    stdio_count: integer;
    stdio: puv_stdio_container_t;
    (*
      * Libuv can change the child process' user/group id. This happens only when
      * the appropriate bits are set in the flags fields. This is not supported on
      * windows; uv_spawn() will fail and set the error to UV_ENOTSUP.
    *)
    uid: uv_uid_t;
    gid: uv_gid_t;

    cpumask: PAnsiChar;
    cpumask_size: SIZE_T;
  end;

  uv_process_options_t = uv_process_options_s;
  puv_process_options_t = ^uv_process_options_t;

  uv_timeval_t = record
    tv_sec: integer;
    tv_usec: integer;
  end;

  puv_timeval_t = ^uv_timeval_t;

  uv_rusage_t = record
    ru_utime: uv_timeval_t; (* user CPU time used *)
    ru_stime: uv_timeval_t; (* system CPU time used *)
    ru_maxrss: UInt64; (* maximum resident set size *)
    ru_ixrss: UInt64; (* integral shared memory size *)
    ru_idrss: UInt64; (* integral unshared data size *)
    ru_isrss: UInt64; (* integral unshared stack size *)
    ru_minflt: UInt64; (* page reclaims (soft page faults) *)
    ru_majflt: UInt64; (* page faults (hard page faults) *)
    ru_nswap: UInt64; (* swaps *)
    ru_inblock: UInt64; (* block input operations *)
    ru_oublock: UInt64; (* block output operations *)
    ru_msgsnd: UInt64; (* IPC messages sent *)
    ru_msgrcv: UInt64; (* IPC messages received *)
    ru_nsignals: UInt64; (* signals received *)
    ru_nvcsw: UInt64; (* voluntary context switches *)
    ru_nivcsw: UInt64; (* involuntary context switches *)
  end;

  puv_rusage_t = ^uv_rusage_t;


type
  uv_fs_event = integer;
  TFS_Event = set of (feRename, feChange);

const
  UV_RENAME = 1;
  UV_CHANGE = 2;


type
  uv_loadavg_param = array [0 .. 2] of Double;


{$INCLUDE callbacks.inc}
{$INCLUDE functions.inc}


implementation

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

{ uv_timespec_t }

function uv_timespec_t.toTimeStamp: Double;
begin
  result := Int64(tv_sec) * 1000 + tv_nsec / 1000000;
end;

initialization

uv_replace_allocator(malloc_func, realloc_func, calloc_func, free_func);

finalization

end.
