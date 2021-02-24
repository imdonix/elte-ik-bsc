//print out the owner of a file


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h> //stat
#include <unistd.h>   //stat
#include <pwd.h> //password 
/*
struct passwd{
  char    *pw_name   User's login name. 
  uid_t    pw_uid    Numerical user ID. 
  gid_t    pw_gid    Numerical group ID. 
  char    *pw_dir    Initial working directory. 
  char    *pw_shell  Program to use as shell. 
}
*/
int main(int argc,char** argv){
 struct stat st;
 stat(argv[0],&st);  //fstat(file descriptor, stat structure)
 printf("The user id: %i\n",st.st_uid);
 struct passwd *pwd;
 pwd=getpwuid(st.st_uid);
 printf("The user name: %s\n",pwd->pw_name);
 return 0;
}