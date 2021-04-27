#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>   //perror
#include <unistd.h>  //fork
#include <sys/ipc.h>   //semaphor
#include <wait.h>  //wait
#include <sys/sem.h> //semaphor
#include <sys/types.h>//semaphor
#include <sys/stat.h> //S_IRUSR

#if !defined(__GNU_LIBRARY__) || defined(_SEM_SEMUN_UNDEFINED)
union semun{
 int val;
 struct semid_ds * buf;
 unsigned short int * array;
 struct seminfo * __buf;
};
#endif

int sem_create(key_t key) //to create a semaphor
{ 
  
  int semaphore=semget(key,1,IPC_CREAT | S_IRUSR | S_IWUSR);
  //1. parameter - uniq key
  //2. parameter - the number of semaphors in semaphore group
  //3. parameter - if it doesn't exist, then create with the given
  //permissions

  if (semaphore==-1){perror("Semaphore error\n");exit(1);}
  return semaphore; 
}
void sem_inic(int semaphore,int init)  //must inic before use
{
  union semun inic;
  inic.val=init; //open, there is number place for product 
  semctl(semaphore,0,SETVAL,inic);  
  //to set values of semaphor
  //1. parameter - the semaphor id
  //2. parameter - the ordinal number of semaphor, which I want to set new
  //value
  //3.parameter - SETVAL =means to set the value,
  //GETVAL=to read the value,
  //IPCRMD=to remove semaphor, e.g.   
  //4.parameter - the variable, which contains the semaphor value
  //returning value==-1, if there is an error, error code will be in errno
}
void semoperation(int semaphore,int op){
  struct sembuf semstate[1];
  semstate[0].sem_num=0;  //the ordinal number of semaphore in semafor group,
  			//which I want to use
  semstate[0].sem_op=op; //to modify the semaphore value, for closing
  semstate[0].sem_flg=0; //sem_flg=IPC_NOWAIT => it will not wait, immidiatly comes back; //
  semop(semaphore,semstate,1);  //to call the semaphore value modification
  
}
void sem_close(int semaphore)
{
  semoperation(semaphore,-1);  //to lower the semaphore value, for closing
  //return -1, if it has failed       
}
void sem_open(int semaphore)
{
  semoperation(semaphore,1); //to increase the semaphore         
}

int semaphore_free,semaphore_empty,semaphore_full;			//semaphore id
int number=3;  //how much product can be produced

union semun init,clear;

int main(int argc,char* argv[])
{ pid_t child;
  key_t key=ftok(argv[0],1); 	//make a uniq key 
  if (key<0){perror("Key error \n");exit(1);}
  semaphore_free=sem_create(key);
  sem_inic(semaphore_free,1);
  
  key_t key2=ftok(argv[0],2); 	//make a uniq key 
  if (key2<0){perror("Key error \n");exit(1);}
  semaphore_full=sem_create(key2);
  sem_inic(semaphore_full,0); //there is no full storage-place
  
  key_t key3=ftok(argv[0],3); 	//make a uniq key 
  if (key3<0){perror("Key error \n");exit(1);}
  semaphore_empty=sem_create(key3);
  sem_inic(semaphore_empty,number); //each storage is empty
  
  child=fork();  
  if (child<0){perror("Fork error");exit(0);}
  if (child>0) //parent - producer
  {   int i=0,r,status;
      while (i++!=10)
      { 
         sem_close(semaphore_empty); // there is no empty place for product
         sem_close(semaphore_free); //only one process is working, producer
         r=semctl(semaphore_empty,0,GETVAL,init);//to read the value of sem.
         printf("Produced and put it to an empty  place, number  %d\n",number-r-1);    
         sem_open(semaphore_free);
         sem_open(semaphore_full);
      }
      ;
      waitpid(child,&status,0);//waits the end of child process
      if( semctl(semaphore_free,0,IPC_RMID,clear)<0) printf("Hiba\n");
      if( semctl(semaphore_empty,0,IPC_RMID,clear)<0) printf("Hiba\n");
      if( semctl(semaphore_full,0,IPC_RMID,clear)<0) printf("Hiba\n");
      //to remove semaphores
  }
  else
  { //child
      int i,r;
      int end=0;    
      union semun init; 
      while (end++!=10)
          {  
            sem_close(semaphore_full); // if there is no product, the semaphore won't let to step in
            sem_close(semaphore_free); //only consumer can work
            r=semctl(semaphore_full,0,GETVAL, init);
            printf("Consumer %i get product number: %d\n",getpid(),r);    
            sem_open(semaphore_free);   //let the producer to work
            sem_open(semaphore_empty);  //the number of empty storage increase
            }
      }  
  return 0;
}
