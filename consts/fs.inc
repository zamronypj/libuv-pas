(*
  * This flag can be used with uv_fs_copyfile() to return an error if the
  * destination already exists.
*)
const
  UV_FS_COPYFILE_EXCL = $1;

  (*
    * This flag can be used with uv_fs_copyfile() to attempt to create a reflink.
    * If copy-on-write is not supported, a fallback copy mechanism is used.
  *)
  UV_FS_COPYFILE_FICLONE = $2;

  (*
    * This flag can be used with uv_fs_copyfile() to attempt to create a reflink.
    * If copy-on-write is not supported, an error is returned.
  *)
  UV_FS_COPYFILE_FICLONE_FORCE = $4;


(*
  * This flag can be used with uv_fs_symlink() on Windows to specify whether
  * path argument points to a directory.
*)
const
  UV_FS_SYMLINK_DIR = $0001;
  (*
    * This flag can be used with uv_fs_symlink() on Windows to specify whether
    * the symlink is to be created using junction points.
  *)
  UV_FS_SYMLINK_JUNCTION = $0002;

