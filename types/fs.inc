{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

type

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
    puv_fs_t = ^uv_fs_t;

    uv_fs_event_s = record
        internal: array [1 .. sizeof_fs_event_t] of Byte;
    end;

    uv_fs_event_t = uv_fs_event_s;
    puv_fs_event_t = ^uv_fs_event_t;

    uv_fs_poll_s = record
        internal: array [1 .. sizeof_fs_poll_t] of Byte;
    end;

    uv_fs_poll_t = uv_fs_poll_s;
    puv_fs_poll_t = ^uv_fs_poll_t;

    (*
     * Flags to be passed to uv_fs_event_start().
     *)
    uv_fs_event_flags = (

        (*
         * By default, if the fs event watcher is given a directory name, we will
         * watch for all events in that directory. This flags overrides this behavior
         * and makes fs_event report only changes to the directory entry itself. This
         * flag does not affect individual files watched.
         * This flag is currently not implemented yet on any backend.
         *)
        UV_FS_EVENT_WATCH_ENTRY = 1,

        (*
         * By default uv_fs_event will try to use a kernel interface such as inotify
         * or kqueue to detect events. This may not work on remote filesystems such
         * as NFS mounts. This flag makes fs_event fall back to calling stat() on a
         * regular interval.
         * This flag is currently not implemented yet on any backend.
         *)
        UV_FS_EVENT_STAT = 2,

        (*
         * By default, event watcher, when watching directory, is not registering
         * (is ignoring) changes in it's subdirectories.
         * This flag will override this behaviour on platforms that support it.
         *)
        UV_FS_EVENT_RECURSIVE = 4
    );

