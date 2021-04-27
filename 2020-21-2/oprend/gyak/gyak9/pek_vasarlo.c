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
#include <sys/wait.h>
#include <time.h>


// posix semaphor requires to link: cc -lrt pek_vasarlo.c
#define MEMSIZE 1024
int *s;
sem_t* szabad;
sem_t* ures;
sem_t* tele;
//
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
void pek()
{
	long int li;
	while(s[1])
	{
	sem_wait(ures);
	sem_wait(szabad);
	s[0]+=1;
	printf("Pek, a kenyerek szama: %i\n",s[0]);
	sem_post(szabad);
	sem_post(tele);
	li=random();
	usleep(li%100000);	// wait 0-100000 microsecond
//	printf("Pek: sutottunk egy kenyeret!\n");
	}
}
void vasarlo()
{
	long int li;
	while(s[1])
	{
	sem_wait(tele);
	sem_wait(szabad);
	s[0]-=1;
	printf("Vasarlo, kenyerek szama: %i\n",s[0]);
	sem_post(szabad);
	sem_post(ures);
	li=random();
	usleep(li%100000);	// wait for a while, 0-100000 microsecond
//	printf("Vasarlo: megettunk 1 kenyeret!\n");
	}
}
int main (int argc,char* argv[]) {

    pid_t pek_id,vasarlo_id;
    key_t kulcs;
    int sh_mem_id, N=10;
    char* sem_nev1="alma";
    char* sem_nev2="korte";
    char* sem_nev3="barack";
//
    kulcs=ftok(argv[0],1);
    sh_mem_id=shmget(kulcs,MEMSIZE,IPC_CREAT|S_IRUSR|S_IWUSR);
    s = (int*)shmat(sh_mem_id,NULL,0);
    s[0]=0; 	// a polcon levo kenyerek szama
    s[1]=1;	// mehet a folyamat
    szabad = szemafor_letrehozas(sem_nev1,1);
    ures = szemafor_letrehozas(sem_nev2,N);	// ures a polc
    tele = szemafor_letrehozas(sem_nev3,0);
    vasarlo_id = fork();
    if(vasarlo_id>0)
    {    
  	pek_id=fork();
	if (pek_id>0)
	{  
       char buffer[100];
	printf("Szulo indul! \n");
	printf("Nyomjon le valamit!\n");
	scanf("%s",&buffer);
	s[1]=0;	// gyerekek vege
	wait(NULL);
	wait(NULL);
	shmdt(s);
	shmctl(sh_mem_id,IPC_RMID,NULL);
       szemafor_torles(sem_nev1);
       szemafor_torles(sem_nev2);
       szemafor_torles(sem_nev3);
	}
	else // pek folyamat
	{
		srandom(1000);	// init random generator in pek
		printf("Pek folyamat indul!\n");
		pek();
		printf("Pek befejezte!\n");
	//		shmdt(s);
	}
    } 
    else {	// vasarlo folyamat
		//srandom(10);	// init random generator in vasarlo
		srandom(time(NULL));
		printf("Vasarlo: Indul!\n");
       		vasarlo();
       		printf("Vasarlo befejezte\n");  
        //shmdt(s);
    }

   return 0;
}


