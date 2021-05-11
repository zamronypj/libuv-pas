{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

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

