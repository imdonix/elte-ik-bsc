//gcc -lrt 
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void handler(int signumber){
  printf("Signal with number %i has arrived\n",signumber);
  printf("Signal handler ends \n");
}

int main(){

  struct sigaction sigact;
  sigact.sa_handler=handler; //SIG_DFL,SIG_IGN
  sigemptyset(&sigact.sa_mask); //during execution of handler these signals will be blocked plus the signal    
  //now only the arriving signal, SIGTERM will be blocked
  //sigact.sa_flags=0; //the handler execution interrupts the process - real time signal
  //sleep is not a real time safe function
  sigact.sa_flags=SA_RESTART; //the interrupted signal will restart!!!
  sigaction(SIGUSR1,&sigact,NULL);
  //SIGUSR1 normal signal *** ONLY ONE is delivered
  //1. parameter the signal number
  //2. parameter the new sigaction with handler and blocked signals during the execution of handler (sa_mask) and a 
  //special sa_flags - it change the behavior of signal, 
  //e.g. SIGNOCLDSTOP - after the child process ended it won't send a signal to the parent 
  //3. parameter - &old sigset or NULL. 
  //If there is a variable, the function will fill with the value of formerly set sigset
 //*************************
 //real time signals between SIGRTMIN - SIGRTMAX 32-64
 //Several delivery
 //************************************************  
  sigaction(SIGRTMIN,&sigact,NULL);
 
  pid_t child=fork();
  if (child>0)
  {
    printf("The program comes back from suspending\n");
    int status;
    wait(&status);
    printf("Parent process ended\n");
  }
  else 
  {
    printf("Waits 1 seconds, then send 5 SIGUSR %i signals and 5 SIGRTMIN %i signals \n", SIGUSR1,SIGRTMIN);
    //real time signals are between SIGRTMIN and SIGRTMAX
    //the smalest real time signal will be executed first
    //the execution order of normal signals is not predefined
    
    printf("If multiple copies of a normal signal is pending, only once of them will be executed\n ");
    printf("Each of real time signals will be executed - the order of execution is the same as the calling order\n ");
    sleep(1);
    int i;
    for (i=0;i<5;i++){
      kill(getppid(),SIGUSR1);
      kill(getppid(),SIGRTMIN);
//      sleep(2);  //if sleep is working, then sigusr1 has done before the next call performs
    }
    printf("Child process ended\n");  
  }
  return 0;
}
