

#include <stdio.h>


#include "foo.h"


void foo(int arr[], int size, int k, int arr1[], int* s1, int arr2[], int* s2)
{
    int j = 0;
    int m = 0;
    for (int i = 0; i < k; ++i)
    {
        if (arr[i] % 2 == 0)
        {
            arr1[j++] = arr[i];
        }
        else
        {
            arr2[m++] = arr[i];
        }
    }
    *s1 = j;
    *s2 = m;
}

void PrintArray(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%i, ", arr[i]);
    }
}

