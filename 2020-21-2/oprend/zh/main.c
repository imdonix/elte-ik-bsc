#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/sem.h>
#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>


struct msg 
{ 
    long mtype;
    int id;
    int sick;
    int count;
}; 

int szemafor_letrehozas(const char* pathname,int szemafor_ertek)
{
    int semid;
    key_t kulcs;
    
    kulcs=ftok(pathname,1);    
    if((semid=semget(kulcs,1,IPC_CREAT|S_IRUSR|S_IWUSR ))<0) perror("semget");
    if(semctl(semid,0,SETVAL,szemafor_ertek)<0) perror("semctl");
       
    return semid;
}


void szemafor_muvelet(int semid, int op)
{
    struct sembuf muvelet;
    
    muvelet.sem_num = 0;
    muvelet.sem_op  = op; 
    muvelet.sem_flg = 0;
    
    if(semop(semid,&muvelet,1)<0) perror("semop");	    
}

void szemafor_torles(int semid)
{
    semctl(semid,0,IPC_RMID);
}


int lucky()
{
    return rand() % 100 < 20;
}

void handler(int signumber)
{
  printf("oltas vege\n");
}

int createpipe(int id)
{
    char pipe[30];
    sprintf(pipe,"/tmp/rnyr2f-%d", id);
    return mkfifo(pipe, S_IRUSR|S_IWUSR);
}

void printtofile(int s, int o)
{
    int semid = szemafor_letrehozas("szema",1);

    szemafor_muvelet(semid,-1);

    FILE* file = fopen("jegyzokonyv.txt", "a"); 
    if (file<0){ perror("Error at opening the file\n"); }

    char text[100];
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(text, sizeof(text)-1, "%d %m %Y", t);

    fprintf(file, "[%s] oltott: %d, beteg: %d\n", text, s, o);

    fclose(file);

    szemafor_muvelet(semid,1);
    szemafor_torles(semid);
}


int main(int argc, char *argv[])
{
    int count = atoi(argv[1]);

    int i, id, pid;

    signal(SIGTERM, handler);
    createpipe(0);
    createpipe(1);
    pid = 666;
    for(i = 0; i < 2; i++)
        if(pid > 0)
        {
            id = i;
            pid = fork();
        }

    int mq;
    mq = msgget(ftok(argv[0],1), 0600 | IPC_CREAT);
    
    if(pid > 0)
    {
        int fu = open("/tmp/rnyr2f-0", O_WRONLY);
        int fc = open("/tmp/rnyr2f-1", O_WRONLY);
        printf("[B] megkezdi a rendelest\n");

        int sent = count / 2;
        write(fc, &sent, sizeof(int));
        sent = count - sent;
        write(fu, &sent, sizeof(int));


        int sicks = 0;
        int oltott = 0;

        for(i = 0; i < 2; i++)
        {
            struct msg uz;
            msgrcv(mq, &uz, sizeof(struct msg), 5, 0);
            
            printf("[B] [%s] valaszolt: betegek: %d, sikerult: %d\n", uz.id ? "U" : "CS", uz.sick, uz.count);

            sicks += uz.sick;
            oltott += uz.count;
        }

        printtofile(sicks, oltott);

        close(fu);
        close(fc);
        msgctl(mq, IPC_RMID, NULL);
        unlink("/tmp/rnyr2f-0");
        unlink("/tmp/rnyr2f-1");
        exit(0);
    }
    else
    {
        srand(time(NULL) * getpid());
        sleep(2+id);

        char pipe[30];
        sprintf(pipe, "/tmp/rnyr2f-%d", id);
        int f = open(pipe, O_RDONLY);
        printf("[%s] megkezdi az oldast\n", id ? "U" : "CS");


        read(f, &count, sizeof(int));
        int sick = 0;
        for(i = 0; i < count; i++)
            if(lucky())
                sick++;

        printf("[%s] beoltott: %d, beteg: %d\n", id ? "U" : "CS", count - sick, sick);


        struct msg uz;
        uz.mtype = 5;
        uz.id = id,
        uz.sick = sick;
        uz.count = count-sick;
        msgsnd(mq, &uz, sizeof(struct msg), 0);

        kill(getppid(),SIGTERM);

        close(f);
        exit(0);
    }
    

    return 0;
}