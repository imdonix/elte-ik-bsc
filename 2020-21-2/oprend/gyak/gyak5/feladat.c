#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    int pid,fd;
    char pipename[20];

    printf("Fifo start!\n");
    
    sprintf(pipename,"/tmp/rnyr2f-%d",getpid());

    int fid=mkfifo(pipename, S_IRUSR|S_IWUSR );
    if (fid==-1)
    {
        printf("Error number: %i",errno);
        perror("Gaz van:");
        exit(EXIT_FAILURE);
    }

    printf("Mkfifo vege, fork indul!\n");
    pid = fork();
    
    if(pid>0)   //parent 
	{
        int sum = 0;
        fd=open(pipename,O_RDONLY);

        int number = -1;
        while(number)
        {
            read(fd, &number, sizeof(int));
            sum += number;
        }

        
        printf("Az szamok osszege: %u \n", sum);
        close(fd);
        
        unlink(pipename);
    }
	else
	{
	    printf("Irj be szamokat | 0 kilepes\n");
        fd=open(pipename,O_WRONLY);

        int number = -1;
        while(number)
        {
            scanf("%i", &number);
            write(fd, &number, sizeof(int));
        }

        close(fd);
	    printf("Iras befejezve\n");
    }	
    
    return 0; 
}
