{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

function uv_tty_init(
    loop: puv_loop_t;
    tty: puv_tty_t;
    os_fd: uv_file;
    unused: integer
) : integer; cdecl;

function uv_tty_set_mode(tty: puv_tty_t; mode: uv_tty_mode_t): integer; cdecl;

function uv_tty_reset_mode: integer; cdecl;

function uv_tty_get_winsize(
    tty: puv_tty_t;
    var width, height: integer
) : integer; cdecl;
