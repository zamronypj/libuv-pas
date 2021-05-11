{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

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
