#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //fork
#include <sys/wait.h> //waitpid
#include <errno.h> 


int main()
{
 int status;
 
 pid_t  child=fork(); //forks make a copy of variables
 if (child<0){perror("The fork calling was not succesful\n"); exit(1);} 
 if (child>0) //the parent process, it can see the returning value of fork - the child variable!
 {
    waitpid(child,&status,0); 
    printf("The end of parent process\n");
 }
 else //child process
 {
    //to start a program, like printing out a string (in parameter) 5 times (parameter)
    printf("Call ./write program by calling system function\n");
    system("./write 'Operating Systems' 5");
    printf("It returns to continue child process after system call \nbecause it starts a new child process and in it will be called an execv\n");
 }
 return 0;
}