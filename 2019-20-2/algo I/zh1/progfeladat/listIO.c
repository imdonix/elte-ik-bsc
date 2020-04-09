// Algo ZH1 
// Feladat: Két L1 lista metszete, az első listába képezve.
// Készítette: Magyar Tamás
// Dátum: 2020.04.09.
// Fordító: gcc 7.2.0 Target: x86_64-w64-mingw32

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
        printf("Unable to open file! (%s)\n", file);
        return 1;
    }

    *length = 0;
    char line[INP_LENGTH];
    while(fgets(line, sizeof(line), src) != NULL)
        dest[(*length)++] = parse(line);

    fclose(src);
    return 0;
}

E1* parse(char* line)
{
    E1* L = createHead();
    E1* p = L;
    for (char* ptr=strtok(line, " ");ptr!=NULL&&!(strcmp(ptr, "\n")==0);ptr=strtok(NULL, " "))
        if(atoi(ptr)||strcmp(ptr, "0")==0)
        {
            E1* q = new(atoi(ptr));
            follow(p,q);
            p=q;
        }
    return L;
}

void printList(E1* L)
{
    printf("{ ");
    for(E1* p=L->next;p!=NULL;p=p->next)
        printf("%i ", p->key);
    printf("}\n");
}