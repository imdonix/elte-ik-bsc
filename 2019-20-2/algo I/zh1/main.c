#include <stdio.h>
#include "list.h"

#define TESTS = 5

int runTest();


#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    printf("NORMAL");
    return 0;
}

#else

int runTest()
{
    E1* lists[TESTS*3];
    int length;

    if(!readListsFromFile("input.txt", lists, &length))
    {
        for(int i=0;i<length;i+=3)
        {
            interselect(lists[i], lists[i+1]);
            printList(lists[i]);
            printList(lists[i+2]);
            printf("%i", eqv(lists[i], lists[i+2]));
            printf("---\n");
        }

    }
    return 0;
}

#endif