{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

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
