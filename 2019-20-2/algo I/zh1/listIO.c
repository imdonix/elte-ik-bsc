#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

int readListsFromFile(char* file, E1** dest, int* length)
{
    FILE* src;
    src = fopen(file, "r");
    if(src == NULL)
    {
        printf("Unable to open file\n");
        return 1;
    }

    *length = 0;
    char line[256];
    while(fgets(line, sizeof(line), src) != NULL)
        dest[(*length)++] = parseLine(line);
    fclose(src);
}

E1* parseLine(char* line)
{
    E1* L = createHead();
    E1* p = L;
    for (char* ptr = strtok(line, " "); ptr!=NULL&&!(strcmp(ptr, "\n")==0); ptr = strtok(NULL, " "))
    {
        E1* q = new(atoi(ptr));
        follow(p,q);
        p=q;
    }
    return L;
}

void printList(E1* L)
{
    E1* p = L->next;
    printf("< ");
    for(;p!=NULL;p=p->next)
        printf("%i ", p->key);
    printf(">\n");
}