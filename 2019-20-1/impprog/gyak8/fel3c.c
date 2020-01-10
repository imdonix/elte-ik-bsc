

#include <stdio.h>
#include <stdlib.h>


// nagyon rossz megoldás
char* foo(int num, char ch)
{
    char arr[1000]; // az arr tömb lokális, a függvény blokkjába belépve jön létre
    for (int i = 0; i < num; ++i)
    {
        arr[i] = ch;
    }
    arr[num] = '\0';

    //return arr;
    return &arr[0]; // kilépéskor az arr tömb "megsemmisül":
    // lehet, hogy nem törlõdik, ezért néha jó eredményt
    // kapunk, de a rendszer mindenképpen felszabadított tárterületként
    // tartja számon; a blokkon belül a memóriacíme lekérdezhetõ, és
    // azzal vissza lehet térni
    // ökölszabály: lokálisan létrehozott változó
    // pointer-ével tilos visszatérni
}


int main()
{
    char* ptr = foo(3, 'C');
    printf("%s\n", ptr);
    free(ptr);
}
