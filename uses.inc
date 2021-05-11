{*!
 * libuv header translation for Free Pascal
 *
 * @link      https://github.com/zamronypj/libuv-pas
 * @copyright Copyright (c) 2021 Zamrony P. Juhara
 * @license   https://github.com/zamronypj/libuv/blob/master/LICENSE (MIT)
 *}

uses

    {$IFDEF MSWINDOWS}
    Windows,
    {$ENDIF}

    {$IFDEF UNIX}
    baseunix,
    unixtype,
    pthreads,
    {$ENDIF}

    sockets,
    sysutils;

