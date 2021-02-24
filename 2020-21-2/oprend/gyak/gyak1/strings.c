#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strlen,strcmp,strcat,strcpy and more ....

//there is no string type - instead of it You have to use char array
int length(char * str)
{
 int l=0;
 while (*str++!=0)l++; //*str points to the next character
 return l;
}
int main()
{
              //char str1[80]; //it would be an 80 characters long empty "string", - it is empty 
  char str1[]="Hello world"; //it's length is the length of the text
  printf("The content of variable str1: \'%s\'\n",str1); 
  //1. parameter formatstring, next parameter(s) variables
  //%s = string, %i = integer \n = new line e.g.
  
  printf("The length of variable str1 \'%s\'\n  %i (with length()), %i (with strlen())\n",str1,length(str1),strlen(str1)); 
  //The end of a string is a 0 character 
  //There is the function strlen!! in string.h
  
  char* str2; //it is a pointer variable (we have to allocate memory)
  str2=str1; //the pointer shows to the same memory place
  printf("The content of variable str2 \'%s\' is the same as str1 \'%s\' \n(pointing the same memory place)\n",str2,str1);
  str2=(char*)malloc(80*sizeof(char)); //allocate new memory 
  //calloc, realloc, free - functions for allocating memory and freeing up the memory
  str2[0]='O'; //to write value character by character
  str2[1]='S';
  str2[2]=0; //at the end of a string there is a 0 character!
  printf("We've given value character by character -  str2: \'%s\'\n",str2); //new content
  
  strcpy(str2,"New content by using strcpy");   
  printf("The new content of variable str2: \'%s\'\n",str2); //new content
  //instead of giving value character by character use function in string.h
  //important other functions: strcmp, strcat, strlen;
      
  free(str2);
  return 0;
}
