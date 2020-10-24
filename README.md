# ft_ls_1
The project ft_ls opens the path to the Unix branch of the sphere system. For the first time, you will have to face the one libc functions that will allow you to do other things than just read or write on a file descriptor (this is to simplify of course). You will discover a sub-system of functions of operating system’s API, the associated data structures, as well as the management of memory allocation and the associated data.

# Ft_ls

By: **aelouazz**

# Allowed functions man

---

### opendir

```c
#include <sys/types.h>
#include <dirent.h>

DIR *opendir(const char *name);
```

> opens a directory stream corresponding to the directory name, and returns a pointer to the directory stream. The stream is positioned at the first entry in the directory

---

### readdir

```c
#include <dirent.h>

struct dirent *readdir(DIR *dirp);
```

returns a pointer to a **dirent** structure representing the next directory entry in the directory stream pointed to by **dirp**. It returns NULL on reaching the end of the directory stream or if an error occurred.

**dirent struct**

```c
struct dirent {
               ino_t          d_ino;       /* Inode number */
               off_t          d_off;       /* Not an offset; see below */
               unsigned short d_reclen;    /* Length of this record */
               unsigned char  d_type;      /* Type of file; not supported
                                              by all filesystem types */
               char           d_name[256]; /* Null-terminated filename */
           };
```

**d_off**  

The value returned in d_off is the same as would be returned by calling telldir(3) at the current position in the directory stream.  Be aware that despite its type and name, the d_off field is filesystems.  Applications should treat this field as an opaque value, making no assumptions about its contents; see also *telldir(3)*.
**d_type**

**DT_BLK**       This is a block device.
**DT_CHR**      This is a character device.
**DT_DIR**        This is a directory.
**DT_FIFO**     This is a named pipe (FIFO).
**DT_LNK**      This is a symbolic link.
**DT_REG**      This is a regular file.
**DT_SOCK**     This is a UNIX domain socket.
**DT_UNKNOWN**  The file type could not be determined.

> Currently, only some filesystems (among them: Btrfs, ext2,ext3, and ext4) have full support for returning the file type in d_type.  All applications must properly handle a return of DT_UNKNOWN.

---

### closedir

```c
#include <sys/types.h>
#include <dirent.h>

int closedir(DIR *dirp);
```

The closedir() function closes the directory stream associated with dirp. A successful call to closedir() also closes the underlying file descriptor associated with dirp. The directory stream descriptor dirp is not available after this call.

---

### **stat, lstat**

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *path, struct stat *buf);
int lstat(const char *path, struct stat *buf);
```

These functions return information about a file. No permissions are required on the file itself, but-in the case of **stat**() and **lstat**() - execute (search) permission is required on all of the directories in *path* that lead to the file.

**stat**() stats the file pointed to by *path* and fills in *buf*.

**lstat**() is identical to **stat**(), except that if *path* is a symbolic link, then the link itself is stat-ed, not the file that it refers to.

All of these system calls return a stat structure, which contains the following fields:

```c
struct stat {
    dev_t     st_dev;     /* ID of device containing file */
    ino_t     st_ino;     /* inode number */
    mode_t    st_mode;    /* protection */
    nlink_t   st_nlink;   /* number of hard links */
    uid_t     st_uid;     /* user ID of owner */
    gid_t     st_gid;     /* group ID of owner */
    dev_t     st_rdev;    /* device ID (if special file) */
    off_t     st_size;    /* total size, in bytes */
    blksize_t st_blksize; /* blocksize for file system I/O */
    blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
    time_t    st_atime;   /* time of last access */
    time_t    st_mtime;   /* time of last modification */
    time_t    st_ctime;   /* time of last status change */
};
```
