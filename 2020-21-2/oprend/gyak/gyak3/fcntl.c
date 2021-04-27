#include <stdlib.h>  
#include <stdio.h>
#include <sys/types.h> //fork-hoz
#include <sys/stat.h>
#include <unistd.h> //fork
#include <string.h> //strlen
#include <fcntl.h> //lock


int main()
{
  int f;
  char text1[]=" Parent Parent Parent Parent Parent Parent Parent Parent Parent Parent ";
  int length1=strlen(text1);
  char text2[]=" Child Child Child Child Child Child Child Child Child Child Child Child ";
  int length2=strlen(text2);
  int i;
  struct flock lock_data;
  lock_data.l_whence=SEEK_SET;//the absolute starting position of locking: SEEK_SET - start of file, SEEK_END - end of file, SEEK_CUR - actual place of 
  lock_data.l_start=0; // relative position of locking to l_whence
  lock_data.l_len=0; //how long is the locked part of the file, 0 - if it depends on the whole file
  int rc=0; //result of lock 
  f=open("data.txt",O_RDWR|O_TRUNC|O_CREAT,S_IRUSR|S_IWUSR);
  pid_t child=fork();
  if (child<0){ //hiba
    perror("Error"); exit(1);
  }
  if (child>0)
    { //Parent process
      int j;
      for (j=0;j<25;j++) //to avoid too big data files
      { 
       // printf("szulo %i ",getpid());
          lock_data.l_pid=getpid();    //which process locks
          lock_data.l_type=F_WRLCK;    //for what it is locked F_WRLCK-write,FRDLCK-read,F_UNLCK - unlock
          rc=fcntl(f,F_SETLKW,&lock_data); //F_setlkw - locks file for writing and it is waiting, F_SETLK - it locks if it can, but not wait
          struct flock l2;
          if (rc!=(-1))
          {        
           for (i=0;i<length1;i++)
           {
             write(f,&text1[i],1);
             usleep(20);  //waits 20 milisec to let slow down writing        
           }  
           write(f,"\n",1);
           lock_data.l_type=F_UNLCK;
           fcntl(f,F_SETLKW,&lock_data); //unlock file
          }
      }
      int status;
      waitpid(child,&status,0); //wait for the end of child process
    }
    else 
    { int j;
      for (j=0;j<25;j++) //to avoid too big data file
      {
         lock_data.l_pid=getpid();
         lock_data.l_type=F_WRLCK;
         rc=fcntl(f,F_SETLKW,&lock_data); //lock file
         if (rc!=(-1))
         {       
            for (i=0;i<length2;i++)
            {
              write(f,&text2[i],1);
              usleep(20);
            }  
            write(f,"\n",1);
            lock_data.l_type=F_UNLCK;
            fcntl(f,F_SETLKW,&lock_data);  //unlock file    
          };
        }
      }
    
    close(f);
    return 0;
}
