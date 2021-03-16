#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h> // for errno, the number of last error

int main(int argc, char* argv[])
{
    int pid,fd;
    printf("Fifo start!\n");
    char pipename[20];
    // In most of system not required full path, 
    // enough a simple name, eg. alma.fa
    // In Debian must define full path name, 
    // so best place is in Debian the /tmp dir.
    sprintf(pipename,"/tmp/%d",getpid());
    int fid=mkfifo(pipename, S_IRUSR|S_IWUSR ); // creating named pipe file
    // S_IWGRP, S_IROTH (other jog), file permission mode
    // the file name: fifo.ftc
    // the real fifo.ftc permission is: mode & ~umask 
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
	char s[1024]="Semmi";		
	printf("Csonyitas eredmenye szuloben: %d!\n",fid);
	fd=open(pipename,O_RDONLY);
	read(fd,s,sizeof(s));
	printf("Ezt olvastam a csobol: %s \n",s);
	close(fd);
	// remove fifo.ftc
	unlink(pipename);
        }
	else // child
	{
	printf("Gyerek vagyok, irok a csobe!\n");
	printf("Csonyitas eredmenye: %d!\n",fid);
        fd=open(pipename,O_WRONLY);
        write(fd,"Hajra Fradi!\n",12);
        close(fd);
	printf("Gyerek vagyok, beirtam, vegeztem!\n");
    	}	
    
    return 0; 
}
