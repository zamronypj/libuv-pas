{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

type

    puv_loop_t = ^uv_loop_t;

    uv_loop_option = (UV_LOOP_BLOCK_SIGNAL);

    uv_run_mode = (UV_RUN_DEFAULT = 0, UV_RUN_ONCE, UV_RUN_NOWAIT);

    uv_loop_s = record
        internal: array [1 .. sizeof_loop_t] of Byte;
    end;

    uv_loop_t = uv_loop_s;

