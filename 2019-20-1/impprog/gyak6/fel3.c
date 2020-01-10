

#include <stdio.h>


void foo(int array[], int size, int* pos, int* neg, int* zero)
{
    *pos = *neg = *zero = 0;
    for (int i = 0; i < size; ++i)
    {
        if (array[i] > 0)
        {
            *pos = *pos + 1;
        }
        else if (array[i] < 0)
        {
            *neg = *neg + 1;
        }
        else
        {
            *zero = *zero + 1;
        }
    }
}


int main()
{
    int pos;
    int neg;
    int zero;
    int arr[] = {4, 7, 0, 0, -1, -5, 12};
    foo(arr, 7, &pos, &neg, &zero);
    printf("%i %i %i\n", pos, neg, zero);
}

