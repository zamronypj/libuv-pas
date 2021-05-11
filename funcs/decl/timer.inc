{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

(*
  * uv_timer_t is a subclass of uv_handle_t.
  *
  * Used to get woken up at a specified time in the future.
*)

function uv_timer_init(loop: puv_loop_t; handle: puv_timer_t): integer; cdecl;

function uv_timer_start(handle: puv_timer_t; cb: uv_timer_cb; Timeout: UInt64;
  &repeat: UInt64): integer; cdecl;

function uv_timer_stop(handle: puv_timer_t): integer; cdecl;

function uv_timer_again(handle: puv_timer_t): integer; cdecl;

procedure uv_timer_set_repeat(handle: puv_timer_t; &repeat: UInt64); cdecl;

function uv_timer_get_repeat(handle: puv_timer_t): UInt64; cdecl;
