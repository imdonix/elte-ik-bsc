

#include <stdio.h>
#include <stdlib.h>

#include "func.h"


#define ARRAY_SIZE 100
#define DEST_ARRAY_SIZE 200


int main()
{
    int* arr1 = malloc(ARRAY_SIZE * sizeof(int));
    if (arr1 == NULL)
    {
        printf("Memory allocation error");
        return 1;
    }

    int* arr2 = malloc(ARRAY_SIZE * sizeof(int));
    if (arr2 == NULL)
    {
        printf("Memory allocation error");
        return 1;
    }

    int* res = malloc(DEST_ARRAY_SIZE * sizeof(int));
    if (res == NULL)
    {
        printf("Memory allocation error");
        return 1;
    }

    for (int i = 0; i < ARRAY_SIZE; ++i)
    {
        arr1[i] = i; // arr1[i] == *(arr1 + i)
        arr2[i] = 2*i;
    }

    int newsize;
    // utolsó paraméter: a newsize mutatóját adjuk át,
    // a fv a mutatót dereferálva meg tudja változtatni
    // a newsize változó tartalmát
    CopyOrderedArray(arr1, ARRAY_SIZE, arr2, ARRAY_SIZE, res, &newsize);
    for (int i = 0; i < newsize; ++i)
    {
        printf("%i ", res[i]);
    }

    free(arr1);
    free(arr2);
    free(res);

    return 0;
}

