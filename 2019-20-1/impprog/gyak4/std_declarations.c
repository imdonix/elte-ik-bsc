// fordítás:  gcc std_declarations.c -o std_declarations.out -std=c99 --pedantic-errors


#include <stdio.h>


int main()
{
    // C90-ben minden deklarációnak egy csoportban, a függvény
    // elején kell szerepelnie, az utasításokat megelõzve
    // ez a kód nem fordul C90-nel, mert a printf() utasítás
    // után deklaráció szerepel, C99-cel viszont fordul
    int i = 0;
    printf("foo");
    int j;
    return 0;
}

