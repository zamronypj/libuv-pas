# Libuv header translation for Free Pascal

## What is this?

This is [libuv](https://libuv.org) header translation for [Free Pascal](https://www.freepascal.org) based on
[node.pas](https://github.com/vovach777/node.pas). Some codes that were not related to
[libuv header](https://github.com/libuv/libuv/blob/v1.x/include/uv.h) were removed.

This header translation is work in progress.

## libuv version
By default, this header translation use libuv 1.18.0.
To use libuv version >= 1.19.0 add conditional defines `LIBUV_1_19_0`.
To use libuv version >= 1.27.0, use `LIBUV_1_27_0`.

```
{$DEFINE LIBUV_1_19_0}
```

# Copyright Notice

Read [NOTICE.txt](NOTICE.txt).
