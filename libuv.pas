{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}
unit libuv;

interface

{$MODE OBJFPC}
{$PACKRECORDS C}

//libuv v1.27.0 or newer
{$IFDEF LIBUV_1_27_0}
    //libuv v1.19.0 or newer
    {$DEFINE LIBUV_1_19_0}
{$ENDIF}

uses

    {$IFDEF MSWINDOWS}
    Windows,
    {$ENDIF}

    {$IFDEF UNIX}
    baseunix,
    unixtype,
    pthreads,
    cnetdb,
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

    puv_loop_t = ^uv_loop_t;

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

    puv_handle_t = ^uv_handle_s;
    uv_close_cb = procedure(handle: puv_handle_t); cdecl;

    uv_handle_s = record
        case byte of
            0 : (
                data : pointer;
                loop : puvloop_t;
                &type : uv_handle_type;
                close_cb : uv_close_cb;
                handle_queue : array[0..1] of pointer;
                case boolean of
                    false : (fd : integer);
                    true : (reserved : array [0..3] of byte);

                {$IFDEF WINDOWS}
                endgame_next : puv_handle_t;
                flags : uint;
                {$ENDIF}

                {$IFDEF UNIX}
                next_closing : puv_handle_t;
                flags : uint;
                {$ENDIF}

            );
            1 : (
                internal: array [1 .. sizeof_handle_t] of Byte;
            );
    end;

    uv_handle_t = uv_handle_s;

    puv_fs_event_t = ^uv_fs_event_t;
    puv_signal_t = ^uv_signal_t;
    puv_fs_t = ^uv_fs_t;
    puv_work_t = ^uv_work_t;

    uv_write_s = record
        internal: array [1 .. sizeof_write_t] of Byte;
    end;

    uv_write_t = uv_write_s;
    puv_write_t = ^uv_write_s;

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

    uv_fs_event_s = record
        internal: array [1 .. sizeof_fs_event_t] of Byte;
    end;

    uv_fs_event_t = uv_fs_event_s;

    uv_fs_poll_s = record
        internal: array [1 .. sizeof_fs_poll_t] of Byte;
    end;

    uv_fs_poll_t = uv_fs_poll_s;
    puv_fs_poll_t = ^uv_fs_poll_t;

    uv_signal_s = record
        internal: array [1 .. sizeof_signal_t] of Byte;
    end;

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


    uv_fs_type = (
        UV_FS_UNKNOWN = -1,
        UV_FS_CUSTOM,
        UV_FS_OPEN_,
        UV_FS_CLOSE_,
        UV_FS_READ_,
        UV_FS_WRITE_,
        UV_FS_SENDFILE_,
        UV_FS_STAT_,
        UV_FS_LSTAT_,
        UV_FS_FSTAT_,
        UV_FS_FTRUNCATE_,
        UV_FS_UTIME_,
        UV_FS_FUTIME_,
        UV_FS_ACCESS_,
        UV_FS_CHMOD_,
        UV_FS_FCHMOD_,
        UV_FS_FSYNC_,
        UV_FS_FDATASYNC_,
        UV_FS_UNLINK_,
        UV_FS_RMDIR_,
        UV_FS_MKDIR_,
        UV_FS_MKDTEMP_,
        UV_FS_RENAME_,
        UV_FS_SCANDIR_,
        UV_FS_LINK_,
        UV_FS_SYMLINK_,
        UV_FS_READLINK_,
        UV_FS_CHOWN_,
        UV_FS_FCHOWN_,
        UV_FS_LCHOWN_,
        UV_FS_REALPATH_,
        UV_FS_COPYFILE_
    );

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

    uv_fs_cb = procedure(req: puv_fs_t); cdecl;

    // uv_fs_t is a subclass of uv_req_t.
    uv_fs_s = record
      case Boolean of
        true:
          (internal: array [1 .. sizeof_fs_t] of Byte);
        false:
          (req: uv_req_t;
            fs_type: uv_fs_type;
            loop: puv_loop_t;
            cb: uv_fs_cb;
            result: SSIZE_T;
            ptr: Pointer;
            path: PUTF8Char;
            statbuf: uv_stat_t;);
    end;

    uv_fs_t = uv_fs_s;

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
        uid, gid: clong;
        shell, homedir: PAnsiChar;
    end;

    uv_passwd_t = uv_passwd_s;
    puv_passwd_t = ^uv_passwd_t;
    uv_loop_option = (UV_LOOP_BLOCK_SIGNAL);

    uv_run_mode = (UV_RUN_DEFAULT = 0, UV_RUN_ONCE, UV_RUN_NOWAIT);

    uv_loop_s = record
        internal: array [1 .. sizeof_loop_t] of Byte;
    end;

    uv_loop_t = uv_loop_s;
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

  uv_exit_cb = procedure(
      process: puv_process_t;
      exit_status: Int64;
      term_signal: integer
  ); cdecl;

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

(*
  * This flag can be used with uv_fs_copyfile() to return an error if the
  * destination already exists.
*)
const
  UV_FS_COPYFILE_EXCL = $1;

  (*
    * This flag can be used with uv_fs_copyfile() to attempt to create a reflink.
    * If copy-on-write is not supported, a fallback copy mechanism is used.
  *)
  UV_FS_COPYFILE_FICLONE = $2;

  (*
    * This flag can be used with uv_fs_copyfile() to attempt to create a reflink.
    * If copy-on-write is not supported, an error is returned.
  *)
  UV_FS_COPYFILE_FICLONE_FORCE = $4;


(*
  * This flag can be used with uv_fs_symlink() on Windows to specify whether
  * path argument points to a directory.
*)
const
  UV_FS_SYMLINK_DIR = $0001;
  (*
    * This flag can be used with uv_fs_symlink() on Windows to specify whether
    * the symlink is to be created using junction points.
  *)
  UV_FS_SYMLINK_JUNCTION = $0002;


type
  uv_fs_event = integer;
  TFS_Event = set of (feRename, feChange);

const
  UV_RENAME = 1;
  UV_CHANGE = 2;


type
  uv_loadavg_param = array [0 .. 2] of Double;

type
  (*
    * Flags to be passed to uv_fs_event_start().
  *)
  uv_fs_event_flags = ( (*
      * By default, if the fs event watcher is given a directory name, we will
      * watch for all events in that directory. This flags overrides this behavior
      * and makes fs_event report only changes to the directory entry itself. This
      * flag does not affect individual files watched.
      * This flag is currently not implemented yet on any backend.
    *)
    UV_FS_EVENT_WATCH_ENTRY = 1, UV_FS_EVENT_STAT = 2,
    (*
      * By default uv_fs_event will try to use a kernel interface such as inotify
      * or kqueue to detect events. This may not work on remote filesystems such
      * as NFS mounts. This flag makes fs_event fall back to calling stat() on a
      * regular interval.
      * This flag is currently not implemented yet on any backend.
    *)
    UV_FS_EVENT_RECURSIVE = 4
    (*
      * By default, event watcher, when watching directory, is not registering
      * (is ignoring) changes in it's subdirectories.
      * This flag will override this behaviour on platforms that support it.
    *)
    );


{$INCLUDE callbacks.inc}
{$INCLUDE functions.inc}


implementation

{$INCLUDE functionsimpl.inc}

initialization

uv_replace_allocator(@malloc_func, @realloc_func, @calloc_func, @free_func);

finalization

end.
