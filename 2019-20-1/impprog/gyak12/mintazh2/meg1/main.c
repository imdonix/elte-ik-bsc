


#include <stdio.h>


// a size méretû arr tömböt páros elemeit az arr1 tömbbe,
// páratlan elemeit az arr2 tömbbe tesszük
// az s1 pointer-ben adja meg az arr1 méretét
// az s1 pointer-ben adja meg az arr1 méretét
// k: csak a tömb elsõ k elemét dolgozzuk fel
// ami hiányzik: az arr1 terület max. méretét át kéne venni, h nehogy túlhivatkozzuk
// ha úgyis átvesszünk az s1 változó pointer-ét, a változót hívás elõtt be lehetne
// állítani az arr1 max. méretére, és azt ellenõrizni
void foo(int arr[], int size, int k, int arr1[], int* s1, int arr2[], int* s2)
{
    // pl. // if (k > size) k = size;
    int j = 0; // páros
    int m = 0; // páratlan
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


int main()
{
    int arr[50];
    for (int i = 0; i < 50; ++i)
    {
        arr[i] = i;
        //scanf("%i", &arr[i]); // a végsõ megoldás ez, csak órán futtatáskor nem akarunk 50 elemet kézzel bevinni
    }

    int arr1[50];
    int arr2[50];
    int s1, s2;

    foo(arr, 50, 40, arr1, &s1, arr2, &s2);

    printf("Even: ");
    PrintArray(arr1, s1);
    printf("\n");

    printf("Odd: ");
    PrintArray(arr2, s2);
    printf("\n");

    return 0;
}


