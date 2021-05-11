{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

function uv_udp_init; external LIBUV_FILE;

function uv_udp_init_ex; external LIBUV_FILE;

function uv_udp_open; external LIBUV_FILE;

function uv_udp_bind; external LIBUV_FILE;

function uv_udp_connect; external LIBUV_FILE;
function uv_udp_getpeername; external LIBUV_FILE;
function uv_udp_getsockname; external LIBUV_FILE;
function uv_udp_get_send_queue_count; external LIBUV_FILE;
function uv_udp_get_send_queue_size; external LIBUV_FILE;

function uv_udp_set_membership; external LIBUV_FILE;

function uv_udp_set_multicast_loop; external LIBUV_FILE;

function uv_udp_set_multicast_ttl; external LIBUV_FILE;

function uv_udp_set_multicast_interface; external LIBUV_FILE;

function uv_udp_set_broadcast; external LIBUV_FILE;

function uv_udp_set_ttl; external LIBUV_FILE;

function uv_udp_send; external LIBUV_FILE;

function uv_udp_try_send; external LIBUV_FILE;

function uv_udp_recv_start; external LIBUV_FILE;

function uv_udp_recv_stop; external LIBUV_FILE;
