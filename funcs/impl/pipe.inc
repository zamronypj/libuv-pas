{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

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

