

#include <stdio.h>
#include <stdlib.h>


int main()
{
    // a malloc() lefoglal a heap-en 100 bájtnyi területet, és
    // visszatér az első bájtra mutató pointer-rel
    // void* típus: általános mutatótípus, "csak" memóriacímet tartalmaz
    // (nem tartozik hozzá típus: nem derül ki, hogy azon a memcímen
    // milyen típusú adat és hány bájton van tárolva)
    void* pointer = malloc(100);

    // mivel void* típusú pointer-t nem lehet dereferálni,
    // a pointer-t előbb int-re mutató pointer-ré kell alakítani
    int* pointer_to_int = (int*)pointer;

    // így már írhatunk a lefoglalt memterületre
    *pointer_to_int = 27;
}

