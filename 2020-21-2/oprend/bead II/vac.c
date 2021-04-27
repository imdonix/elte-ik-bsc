#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "vac.h"

#define CAPACITY 5
#define BUS 2
#define ENDSIG -1

void handler(int signumber)
{
  printf("Bus is ready\n");
}

int dangered(char* line)
{
    return line[0] != '\0' && line[0] != 'V';
}

int sortout(char data[MAX][LINE], int len, int* patients)
{
    int i, c;
    i = c = 0;

    while(c < CAPACITY * BUS && i < len)
    {
        if(dangered(data[i]))
            patients[c++] = i;
        i++;
    }

    return c;
}

int createpipe(int id)
{
    char pipe[30];
    sprintf(pipe,"/tmp/rnyr2f-%d", id);
    return mkfifo(pipe, S_IRUSR|S_IWUSR);
}

int lucky()
{
    return rand() % 10 != 0;
}

void start(char data[MAX][LINE], int* patients, int len, int bus)
{
    signal(SIGTERM, handler);

    int i, fd, fe, id, pid;

    createpipe(0);
    createpipe(1);
    pid = 666;
    for(i = 0; i < bus; i++)
        if(pid > 0)
        {
            id = i;
            pid = fork();
        }


    if(pid > 0)
    {   
        fd = open("/tmp/rnyr2f-0", O_WRONLY);
        fe = open("/tmp/rnyr2f-1", O_RDONLY);
        printf("[M] The Operation is started\n");

        for(i = 0; i < bus; i++)
            pause();

        for(i = 0; i < len; i++) 
        {
            printf("[M] Patient is sent (%d)\n", patients[i]);
            write(fd, &patients[i], sizeof(int));
        }

        int sig = -1;
        for(i = 0; i < bus; i++) 
        {
            write(fd, &sig, 18);
        }

        int done = 0;
        int succes = 0;
        int current;
        while(done < bus)
        {
            read(fe, &current, sizeof(int));
            if(current >= 0)
            {
                data[current][0] = 'V';
                succes++;
            }
            else
                done++;
        }

        printf("[M] Vacinated patients is registred in the system (%d)\n", succes);

        close(fd);
        close(fe);

        unlink("/tmp/rnyr2f-0");
        unlink("/tmp/rnyr2f-1");
    }
    else
    {        
        fd = open("/tmp/rnyr2f-0", O_RDONLY);
        fe = open("/tmp/rnyr2f-1", O_WRONLY);
        printf("[%d] (%d) Bus is started\n", id, fd);

        sleep(id+1);
        kill(getppid(),SIGTERM);
        sleep(id+1);

        int current = 0;
        int dose = CAPACITY;
        while(dose > 0)
        {
            read(fd, &current, sizeof(int));
            if(current >= 0)
            {
                if(lucky())
                {
                    printf("[%d] Bus is inoculate %d\n", id, current);
                    write(fe, &current, sizeof(int));
                    dose--;
                }
                else
                    printf("[%d] %d doesnt come.\n", id, current);
            }
            else
                break;
        }

        printf("[%d] Bus is finished\n", id);
        
        current = -1;
        write(fe, &current, sizeof(int));

        close(fd);
        close(fe);

        exit(0);
    }
}

void vacinate(char data[MAX][LINE], int len)
{
    int patients[CAPACITY * BUS + 1];
    int l = sortout(data, len, patients);
    int bus = l / CAPACITY; 

    if(bus > 0)
        start(data, patients, l, bus);
    else
        printf("There is not enough patient to start a bus (%d)\n", l);
}