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
