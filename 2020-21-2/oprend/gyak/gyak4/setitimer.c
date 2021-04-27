#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <signal.h>
#include <unistd.h>

int count=0;
struct itimerval timer;

void handleralarm(int signalnumber){
 printf("The program was alarmed by alarm function\n");
 
}
void handlersetitimer(int signalnumber)
{ count++;
  printf("The program was alarmed by setitimer the %i. time\n",count);
  if (count==5) {
    timer.it_interval.tv_sec=0; /* it will be stopped */
    timer.it_interval.tv_usec=0;
    
    raise(SIGTERM); //it will stop process
    // raise a signal and send it to the process itself
  }
}
int main(){
 //1. trial of creating a timer by alarm function
 signal(SIGALRM,handleralarm);
 alarm(1); //it is implemented in POSIX systems - but it is adviced to use setitimer
 sleep(2); //waiting the end of alarm BUT usually do not use sleep and alarm or setitimer together - may interference
 printf("\n\n");
 //2. trial of creating a timer by setitimer function
 struct sigaction sigact;
 sigemptyset(&sigact.sa_mask); //no blocked signals only the one, which arrives
 sigact.sa_handler=handlersetitimer;
 sigact.sa_flags=0; //no special behaviour
 sigaction(SIGALRM,&sigact,NULL); //an alarm signal is set

 timer.it_interval.tv_sec=3; /* it will be repeated after 3 seconds */
 timer.it_interval.tv_usec=0;
 timer.it_value.tv_sec=1;    /* remaining time till expiration */
 timer.it_value.tv_usec=0;       

 setitimer(ITIMER_REAL,&timer,NULL ); //result = 0, if it is good  
  //when expires, a signal will be sent to the process, and it restarts
  //1. parameter ITIMER_REAL - real time, ITIMER_VIRTUAL (during process execution)
  //2. parameter timer 
  //3. old timer value
 struct itimerval expires;
 while (1){
  ;
  sleep(1); //be careful with sleep
  getitimer(ITIMER_REAL,&expires);//reads the remaining time 
  printf("\tTimer will be expired after %i seconds\n", expires.it_value.tv_sec);
 }
 
 return 0;
}