

#include "func.h"


/*
s = 2 2 4 6 7
z = 1 2 3 5 6
sz = 1 2 2 2 3 4 5 6 6 7

duplikátumok nélkül:
sz = 1 2 3 4 5 6 7

amikor a 2 (ill. 6) bekerült az elsõ esetben, látható, hogy az
elõtte lévõ elem is 2 (ill. 6), mert a tömb rendezett
*/


void CopyOrderedArray(int s[], int size1, int z[], int size2, int sz[], int* newsize)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int tmp;
    int destsize = size1 + size2;

    while (i <= size1 - 1 || j <= size2 - 1)
    {
        if (j > size2 - 1 || (i <= size1 - 1 && s[i] <= z[j]))
        {
            tmp = s[i]; // tmp-ben tároljuk mi a tömb következõ lehetséges eleme
            i++;
        }
        else
        {
            tmp = z[j];
            j++;
        }

        // tmp csak akkor kerülhet be a tömbbe, ha eddig még nem szerepel a tömbben
        // ez két esetben fordulhat elõ:
        // vagy õ a legelsõ eleme az eredménytömbnek
        // vagy õ nem a legelsõ eleme az eredménytömbbnek ÉS a tömb elõzõ eleme nem a tmp
        // az utóbbit azért tudjuk, mert a tömbök rendezettek

        //if (k == 0 || (k > 0 && sz[k - 1] != tmp)) // k > 0 felesleges
        if (k == 0 || sz[k - 1] != tmp)
        {
            sz[k] = tmp;
            k++;
        }
    }
    // az eredménytömb végsõ mérete k, hiszen k-val
    // számoltuk, hol tartunk az eredmény tömbben
    *newsize = k;
}
