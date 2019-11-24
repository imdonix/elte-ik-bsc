

#include <stdio.h>


int* maxsearch(int* ptr, int size)
{
    if (size == 0)
    {
        return NULL; // NULL pointer, speciális pointer:
        // azt jelenti, hogy a pointer sehova sem mutat
    }
    int* pmax = ptr;
    for (int idx = 1; idx < size; ++idx)
    {
        if (*(ptr + idx) > *pmax)
        {
            pmax = ptr + idx;
        }
    }
    return pmax;
}


int main()
{
    int arr[] = {-4, 6, 1, 0, 10, 7};
    int* result;
    result = maxsearch(arr, 0);
    if (result == NULL)
    {
    }
    else
    {
        printf("%i\n", *result);
    }
}
