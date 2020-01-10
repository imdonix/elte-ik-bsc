

#include <stdio.h>
#include <stdlib.h>

#include "foo.h"


int main()
{
    int usr_input;
    printf("Size: ");
    scanf("%i", &usr_input);

    int* arr = malloc(usr_input * sizeof(int));
    if (arr == NULL)
    {
        printf("Error: Memory alloc failed\n");
        return 1;
    }

    for (int i = 0; i < usr_input; ++i)
    {
        arr[i] = i;
    }

    int s1, s2;

    int* arr1 = malloc(usr_input * sizeof(int));
    if (arr1 == NULL)
    {
        printf("Error: Memory alloc failed\n");
        return 1;
    }

    int* arr2 = malloc(usr_input * sizeof(int));
    if (arr2 == NULL)
    {
        printf("Error: Memory alloc failed\n");
        return 1;
    }

    // lehetne egyben is:
    /*
    if (arr == NULL || arr1 == NULL || arr2 == NULL)
    {
        printf("Error: Memory alloc failed\n");

        // ha volt lefoglalt, felszabadítjuk
        // ez korrekt, mert free(NULL); nem csinál semmit
        free(arr);
        free(arr1);
        free(arr2);

        return 1;
    }
    */

    foo(arr, usr_input, usr_input, arr1, &s1, arr2, &s2);

    printf("Even: ");
    PrintArray(arr1, s1);
    printf("\n");

    printf("Odd: ");
    PrintArray(arr2, s2);
    printf("\n");

    free(arr1);
    free(arr2);
    free(arr);

    return 0;
}


