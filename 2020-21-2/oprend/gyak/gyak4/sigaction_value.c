//// LINK with -lrt 
////send addional data with a signal

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>
/*
union sigval {
   int   sival_int;  // the data is int, sent by a signal
   void *sival_ptr;  // or the data is a pointer!
};
*/                                         

struct student
{
  char name[80];
  int year;
};
  
  struct student who={"Who am i?",2014}; // define a data structure to send
  timer_t t_id;
// signal handler 
void handler(int signumber,siginfo_t* info,void* nonused){
  printf("Signal with number %i has arrived\n",signumber);
  switch (info->si_code){ 
    case SI_USER: printf("Process (PID number %i) sent the signal (calling kill)\n",info->si_pid); break;
    case SI_TIMER: printf("It was sent by a timer\n");
                   printf("Additional data: %i\n",info->si_value.sival_int);
                   timer_delete(t_id); //stops timer
                   break;
    case SI_QUEUE: printf("It was sent by a sigqueue, sending process (PID %i)\n",info->si_pid);
             //    printf("Additional value: %i\n",info->si_value.sival_int);
                   struct student* d=(struct student*)info->si_value.sival_ptr;                     
                   printf("Additional value: %s, %i\n",d->name,d->year);
                   break;
    default: printf("It was sent by something else \n");
  } 
}

int main(){

  struct student zoli={"Zoli",2014}; // define a data structure to send
  struct sigaction sigact;
  
  sigact.sa_sigaction=handler; //instead of sa_handler, we use the 3 parameter version
  sigemptyset(&sigact.sa_mask); 
  sigact.sa_flags=SA_SIGINFO; //we need to set the siginfo flag 
  sigaction(SIGTERM,&sigact,NULL); 
  
  struct sigevent myevent; //sigevent for creating a timer
  myevent.sigev_signo=SIGTERM; //  
  myevent.sigev_notify=SIGEV_SIGNAL;
  myevent.sigev_value.sival_int=5; // myevent.sigev_value.sival_ptr - an address
  
  
  int bad=timer_create(CLOCK_REALTIME, &myevent,&t_id);
  if (bad!=0) {perror("Error\n");exit(EXIT_FAILURE);}
  struct itimerspec mytimerspec;
  mytimerspec.it_value.tv_sec=1;
  mytimerspec.it_interval.tv_sec=1;
  mytimerspec.it_value.tv_nsec=0;
  mytimerspec.it_interval.tv_nsec=0;

  if (timer_settime(t_id,0,&mytimerspec,NULL)<0) {perror("SETtimer error\n"); exit(EXIT_FAILURE);};
  printf("Send a SIGTERM by the timer in 1 sec\n");
  pause();
  printf("\n---------------------------------\n");  
  // timer_delete(t_id);	// timer delete
  pid_t child=fork();
  if (child>0)
  {
    printf("Parent (PID %i) waits for a signal from child (PID %i) \n",getpid(),child);
    pause();
    printf("\n---------------------------------\n");  
    pause();
    wait(NULL);
    printf("Parent process ended\n");
  }
  else 
  {
    printf("Child process (PID %i), will send a SIGTERM to parent\n",getpid());
    sleep(1);
    kill(getppid(),SIGTERM);
    
    //sendig an integer as an additional data 
    /*
    sleep(1);
    union sigval s_value_int={5};
    sigqueue(getppid(),SIGTERM,s_value_int); //just the same as kill function, but we can send additional data too 
    */
  struct student adam={"Barath Adam",2014}; // define a data structure to send
    sleep(1);
    union sigval s_value_ptr;
    s_value_ptr.sival_ptr=&zoli;  //the struct data must define in commmon code
				//so &adam instead &zoli is a bad solution
    sigqueue(getppid(),SIGTERM,s_value_ptr);
    printf("Child process ended\n");  
  }
  return 0;
}
