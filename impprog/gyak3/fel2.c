

#include <stdio.h>

/*
int foo(int arr[])
{
    printf("arr %i elembõl áll\n", sizeof(arr) / sizeof(int)); // ez így nem mûködik
    return 0;
}
// ha tömböt adunk egy függvénynek paraméterként, akkor egy külön
// paraméterben át kell adnunk a tömb méretét is
// függvényen belül nincs lehetõség kiszámolni/lekérdezni a paraméterként
// kapott tömb méretét

// ha a kapott tömb egy sztring, akkor ott élhetünk azzal a feltételezéssel,
// hogy a sztring vége '\0' karakterrel van zárva, ezért sztringeknél
// felesleges külön átadni a méretet
*/


int main()
{
    int numbers[] = {56, 78, 34, -56, 0, 1, -1, 54, 7, 89, -2, 100, 566, 321523, -3, 87,
    0, 36, -1, -45, -25231285, 6, 14, -69, 123, 46747, 234, 7, -235, 346, 1325, -4436, 7457};

    /*
    sizeof(obj) - visszatér obj méretével bájtokban
    */

    printf("%i\n", sizeof(numbers) / sizeof(int)); // ha tudjuk a típust
    printf("%i\n", sizeof(numbers) / sizeof(numbers[0])); // az elsõ elem típusnának méretével osztunk
    //foo(numbers);
}

