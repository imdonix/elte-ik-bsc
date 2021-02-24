//print out the files from a directory
//sign each of the directories

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h> //opendir, readdir
#include <sys/types.h> //opendir
#include <sys/stat.h> //stat
#include <unistd.h>   //stat
/*
struct dirent {
    ino_t          d_ino;       // inode number
    off_t      d_off;       // offset to the next dirent 
    unsigned short d_reclen;    // length of this record 
    unsigned char  d_type;      // type of file; not supported
                                   by all file system types 
    char           d_name[256]; // filename 
};

struct stat {
    dev_t     st_dev;     // ID of device containing file 
    ino_t     st_ino;     // inode number 
    mode_t    st_mode;    // protection 
    nlink_t   st_nlink;   // number of hard links 
    uid_t     st_uid;     // user ID of owner 
    gid_t     st_gid;     // group ID of owner 
    dev_t     st_rdev;    // device ID (if special file) 
    off_t     st_size;    // total size, in bytes 
    blksize_t st_blksize; // blocksize for file system I/O 
    blkcnt_t  st_blocks;  // number of 512B blocks allocated 
    time_t    st_atime;   // time of last access 
    time_t    st_mtime;   // time of last modification 
    time_t    st_ctime;   // time of last status change 
};
*/
int main(){
 DIR* d;
 struct dirent * dp; //pointer to dirent struct
 struct stat st;
 d=opendir("."); //parameter the directory name (with path) we want to open
 if (d<0){perror("Some problem in opening");exit(1);}
 while (dp=readdir(d)){ 
   stat(dp->d_name,&st);  //fstat(file descriptor, stat structure)
   if (S_ISDIR(st.st_mode)) {
     printf("d:");
   }
   else {
     if (st.st_mode & S_IRUSR) printf("r "); //to read out the permissions 
     else printf("- ");
   }
   printf("%s\n",dp->d_name);
 }
 closedir(d); //close directory after opendir
 return 0;
}