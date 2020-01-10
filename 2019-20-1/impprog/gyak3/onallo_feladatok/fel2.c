

#include <stdio.h>


int max_search(int arr[], int size)
{
    int max = arr[0];
    for (int idx = 0; idx < size; idx++)
    {
        if (arr[idx] > max)
        {
            max = arr[idx];
        }
    }
    return max;
}


int main()
{
    int example_array[] = {1, 2, 3, 4, 5};
    printf("%i\n", max_search(example_array, 5));
}

