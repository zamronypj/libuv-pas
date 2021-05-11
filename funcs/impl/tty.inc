{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

function uv_tty_init; external LIBUV_FILE;

function uv_tty_set_mode; external LIBUV_FILE;

function uv_tty_reset_mode; external LIBUV_FILE;

function uv_tty_get_winsize; external LIBUV_FILE;