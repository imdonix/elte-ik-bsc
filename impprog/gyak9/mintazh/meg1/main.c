

#include <stdio.h>


void CopyOrderedArray(int s[], int size1, int z[], int size2, int sz[])
{
    int i = 0; // firstindex: a tömb elsõ valid indexe
    int j = 0;
    int k = 0;

    // lastindex: a tömb utolsó valid indexe, ami méret - 1
    while (i <= size1 - 1 || j <= size2 - 1)
    {
        if (j > size2 - 1 || (i <= size1 - 1 && s[i] <= z[j]))
        {
            sz[k] = s[i];
            i++;
        }
        else
        {
            sz[k] = z[j];
            j++;
        }
        k++;
    }
}


int main()
{
    int arr1[100], arr2[100], res[200];
    for (int i = 0; i < 100; ++i)
    {
        arr1[i] = i;
        arr2[i] = 2*i;
    }

    CopyOrderedArray(arr1, 100, arr2, 100, res);
    for (int i = 0; i < 200; ++i)
    {
        printf("%i ", res[i]);
    }
}

