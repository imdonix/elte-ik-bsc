#include <stdio.h>
#include <stdlib.h>
//call it with some parameters from the command line 

int main(int argc,char ** argv) 
//char** means an array of character arrays = array of strings
{
 int i;

 for (i=0;i<atoi(argv[2]);i++){

  printf("%s\n",argv[1]);
 }
 return 0;
}
