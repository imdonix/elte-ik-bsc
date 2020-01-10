

#include <stdio.h>


void foo(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%i\n", *(arr + i));
    }
}


int main()
{
    int arr[3] = {-1, -2, -3};

    // minden kifejezésnek van típusa
    // pl "arr" típusa egy 3-elemű tömb
    // a legtöbb kifejezésben (kivétel: sizeof() és &) a tömb neve
    // a tömb első elemére mutató pointer-ré konvertálódik
    // foo-nak int-re mutató pointer adódik át, ami arr első elemére mutat
    foo(arr, 3);
}

