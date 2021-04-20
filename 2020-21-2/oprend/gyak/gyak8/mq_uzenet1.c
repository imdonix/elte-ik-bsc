#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <mqueue.h>
#include <errno.h>
// Posix Message queue sample
// mq_open, mq_send,mq_receive, mq_unlink

int main (int argc, char* argv[]) { 
     pid_t child; 
     int uzenetsor, status;
	char* mqname="/baba1";
	struct mq_attr attr;
	mqd_t mq1,mq2;
	attr.mq_maxmsg=5; //MAXMSGS
	attr.mq_msgsize=50; //MSGSIZE 
	//
	mq_unlink(mqname); // delete if exist
	mq1=mq_open(mqname, O_CREAT|O_RDWR,0600,&attr);
     if ( mq1 < 0 ) { 
          printf("mq_open error: %d \n",errno); 
          return 1; 
     } 
     char buffer[100];	// mq_send, mq_receive uses char array
	printf("Buffer length: %d\n",strlen(buffer));
     child = fork(); 
     if ( child > 0 ) { 
          char uzenet[30]="Hajra Fradi!";
	uzenet[13]=65; uzenet[14]=65; uzenet[15]=65;
	  int db=mq_send(mq1,uzenet,17, 5 );  //Parent sends a message. 
	  // 5 priority, higher number, higher priority
	  //sleep(1); // ha ez nincs a fogad be is olvassa!!!!
          mq_send(mq1,"Hajra Debrecen!",20, 4);
	  //mq_receive(mq1, buffer, strlen(buffer), 0); // get the first message
	  printf("Szulo: uzenet elkuldve!%d\n",db);
	  wait( NULL ); 
          // After terminating child process, the message queue is deleted. 
          mq_close(mq1);
	  mq_unlink(mqname);
	  printf("Szulo vege!\n"); 
     } else  { // child
	//sleep(1); 
	//mq2=mq_open(mqname,O_RDWR);
	//strcpy(buffer,"                  ");
	
        int db=mq_receive(mq1,buffer, 54,NULL);
	// 5 is the message priority
	//
	printf("Buffer length: %d\n",strlen(buffer));
	printf("mq_receive : %s, olvasott bajtok hossza: %d errno: %s\n",buffer, db,strerror(errno));
        db=mq_receive(mq1,buffer, 50, 0);
	printf("kovetkezo uzenet: %s hossza: %d\n", buffer,db);
	mq_close(mq1);
	//mq_send(mq1,"Gyerek befejezte!", 20,6);
	//msgsnd(uzenetsor,&valasz,sizeof(struct uzenet),0);
	return 0; 
          // The child process receives a message. 
     }
     
     return 0; 
} 
