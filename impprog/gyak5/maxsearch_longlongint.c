

#include <stdio.h>


long long int max_search(long long int arr[], int size)
{
    long long int max = arr[0];
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
    long long int numbers[] = { 56, 78, 34, -56, 0, 1, -1, 54, 7, 89, -2, 100, 566, 3215234562ll,
    -3, 87, 0, 36, -1, -45, -25231285, 6, 14, -69, 123, 46747, 234, 7, -235, 346, 1325, -4436, 7457 };

    long long int res = max_search(numbers, 33);
    printf("max = %lli\n", res);
}
