{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}
unit libuv;

interface


{$INCLUDE uses.inc}
{$INCLUDE consts.inc}
{$INCLUDE types.inc}
{$INCLUDE functions_decl.inc}

implementation

{$INCLUDE functions_impl.inc}

initialization

uv_replace_allocator(malloc_func, realloc_func, calloc_func, free_func);

end.