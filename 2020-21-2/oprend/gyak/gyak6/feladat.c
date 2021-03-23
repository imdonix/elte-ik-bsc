#include <sys/ipc.h> 
#include <sys/msg.h> 
#include <sys/types.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <wait.h> 
#include <time.h>

struct uzenet { 
     long mtype;
     int number;
}; 

int kuld( int uzenetsor ) 
{ 
     const struct uzenet uz = { 1, rand() }; 
     int status; 
     
     status = msgsnd( uzenetsor, &uz, sizeof(int), 0 ); 

     if ( status < 0 ) 
          perror("msgsnd"); 
     return 0; 
} 
     

int fogad( int uzenetsor ) 
{ 
     struct uzenet uz; 
     int status; 
     // az utolso parameter(0) az uzenet azonositoszama
	// ha az 0, akkor a sor elso uzenetet vesszuk ki
	// ha >0 (5), akkor az 5-os uzenetekbol a kovetkezot
	// vesszuk ki a sorbol 
     status = msgrcv(uzenetsor, &uz, sizeof(int), 1, 0 ); 
     
     if ( status < 0 ) 
          perror("msgsnd"); 
     else
          printf( "A kapott uzenet kodja: %ld, number:  %u\n", uz.mtype, uz.number ); 
     return 0; 
} 

int main (int argc, char* argv[]) { 
     pid_t child; 
     int uzenetsor, status; 
     key_t kulcs; 

     srand(time(0));

     kulcs = ftok(argv[0],1); 
     printf ("A kulcs: %d\n",kulcs);
     uzenetsor = msgget( kulcs, 0600 | IPC_CREAT ); 
     if ( uzenetsor < 0 ) { 
          perror("msgget"); 
          return 1; 
     } 
     
     child = fork(); 
     if ( child > 0 ) 
     { 
          kuld( uzenetsor ); 
          wait( NULL ); 

          status = msgctl( uzenetsor, IPC_RMID, NULL ); 
          if ( status < 0 ) 
               perror("msgctl"); 
          return 0; 
     } 
     else if ( child == 0 ) 
     { 
          return fogad( uzenetsor ); 
     } 
     else 
     { 
          perror("fork"); 
          return 1; 
     } 
     
     return 0; 
} 
