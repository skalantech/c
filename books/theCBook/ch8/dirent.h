#define NAME_MAX 14 /* longest filename component; */
/* system-dependent */

typedef struct
{                            /* portable directory entry */
    long ino;                /* inode number */
    char name[NAME_MAX + 1]; /* name + '\0' terminator */
} Dirent;

typedef struct
{             /* minimal DIR: no buffering, etc. */
    int fd;   /* file descriptor for the directory */
    Dirent d; /* the directory entry */
} DIR;

DIR *opendir(char *dirname);
Dirent *readdir(DIR *dfd);
void closedir(DIR *dfd);

// struct stat /* inode information returned by stat */
// {
//     dev_t st_dev;    /* device of inode */
//     ino_t st_ino;    /* inode number */
//     short st_mode;   /* mode bits */
//     short st_nlink;  /* number of links to file */
//     short st_uid;    /* owners user id */
//     short st_gid;    /* owners group id */
//     dev_t st_rdev;   /* for special files */
//     off_t st_size;   /* file size in characters */
//     time_t st_atime; /* time last accessed */
//     time_t st_mtime; /* time last modified */
//     time_t st_ctime; /* time originally created */
// };