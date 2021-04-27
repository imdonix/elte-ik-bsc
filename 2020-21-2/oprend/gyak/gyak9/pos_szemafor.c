#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <wait.h>

#define MEMSIZE 1024

sem_t* szemafor_letrehozas(char*nev,int szemafor_ertek)
{
    sem_t *semid=sem_open(nev,O_CREAT,S_IRUSR|S_IWUSR,szemafor_ertek );
	if (semid==SEM_FAILED)
	perror("sem_open");
       
    return semid;
}

void szemafor_torles(char* nev)
{
      sem_unlink(nev);
}

int main (int argc,char* argv[]) {

    pid_t child;
    key_t kulcs;
    int sh_mem_id;
    sem_t* semid;
    char *s;
    char* sem_nev="/alma1";

    kulcs=ftok(argv[0],1);
    sh_mem_id=shmget(kulcs,MEMSIZE,IPC_CREAT|S_IRUSR|S_IWUSR);
    s = shmat(sh_mem_id,NULL,0);

    semid = szemafor_letrehozas(sem_nev,0);

    child = fork();
    if(child>0)	// parent
	{    
       	char buffer[] = "Hajra Fradi!\n";
	printf("Szulo indul, kozos memoriaba irja: %s\n",buffer);
       	sleep(4); // wait for a few seconds             
       	strcpy(s,buffer);	// copy data to shared memory
	printf("Szulo, szemafor up!\n");
       	sem_post(semid);	// semaphore up
	shmdt(s);	// release shared memory	
       	wait(NULL);       
       	szemafor_torles(sem_nev);
	shmctl(sh_mem_id,IPC_RMID,NULL);
    	} 
	else 
	if ( child == 0 ) //child
		{	
       		/*  kritikus szakasz kezdete   */
		printf("Gyerek: Indul a posix szemafor down!\n");
       		sem_wait(semid);	// semaphore down
       		printf("Gyerek, down rendben, eredmeny: %s",s);  
       		sem_post(semid);      
       		/*  kritikus szakasz vége  */  	  
       		shmdt(s);
    		}

   return 0;
}


