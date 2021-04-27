#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <poll.h> // poll
#include <errno.h>
#include <fcntl.h> //O_RDONLY,
#include <unistd.h> //close
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h> //rand,poll
#include <sys/wait.h>


void handler(int sig)
{
	printf("Handler signal no. is: %i\n",sig);
}
int main(){
 
 int f=mkfifo("/tmp/fradi_cso",0600);
 if (f<0){perror("error");exit(1);}
 
 printf("The named pipe ppoll test was started!\n");
 f=open("/tmp/fradi_cso",O_RDWR);
 struct pollfd poll_fds[5]; // poll file descriptor array
 poll_fds[0].fd=f; 	// file decriptor
 poll_fds[0].events=POLLIN; //watch for  reading
 //------------------------------------------------------
 printf("Second part!\n"); 
 pid_t child=fork();
 if (child>0)
  { //parent process
   printf("Parent waites for a while...\n");
   sleep(3);
   printf("Parent sends a SIGUSR1 signal to the child!\n");
   kill(child,SIGUSR1);
  // int i=rand()%100,status;
  // write(f,&i,sizeof(i)); //writes to the pipe
   printf("Parant waits for child end!\n");
   wait(NULL);   //waits for the child
   printf("Parent was finished too!\n");
  }
 else
  { // child process
   printf("Child ppoll is started!\n");
  signal(SIGUSR1,handler);
  struct timespec delay;
  delay.tv_sec=20;  // 20 seconds delay
  delay.tv_nsec=0;
  sigset_t sigmask;
  sigfillset(&sigmask);  // sigmask is full now
  sigdelset(&sigmask,SIGUSR1); // SIGUSR1 removed from sigmask
				// it means ppoll accepts only SIGUSR1
  // poll - ppoll differences: timer (timespec), and sigmask(sigset_t)
  // if sigmask is NULL, no practical differences between poll-ppoll 
  int result=ppoll(poll_fds,1,&delay,&sigmask); //
  if (result>0) 
  { 
   printf("The ppoll revents field is: %i\n",poll_fds[0].revents);
   if (poll_fds[0].revents & POLLOUT) // POLLIN event occured
   {
   printf("Now we can read from the pipe \n");
   int data; char cdata;
   read(f,&cdata,sizeof(cdata));   
   printf("The data is: %c\n",cdata);                          
   } 
  }
  else
  {
	printf("The returned ppoll result is: %i\n",result);
  	printf("Child process is over!\n");
  }
 }
 unlink("/tmp/fradi_cso");
 return 0; 
}
