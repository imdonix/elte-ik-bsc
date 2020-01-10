

#include <stdio.h>
#include <stdlib.h>


int main()
{
    // a
    /*short int i = 3906;
    short int* pi = &i;
    printf("%i\n", *pi);
    unsigned char* pc = (unsigned char*)pi;
    printf("%i\n", *pc);*/

    // b
    void* pointer = malloc(100);
    int* pi = (int*)pointer;
    *pi = 45;
    printf("%i \n", *pi);
    char* pc = ((char*)pointer) + sizeof(int);
    *pc = 'A';
    printf("%c\n", *pc);
}

