

#include "func.h"


void CopyOrderedArray(int s[], int size1, int z[], int size2, int sz[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    int destsize = size1 + size2;

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
