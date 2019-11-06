// fordítás: gcc std_nestedfunctions.c -o std_nestedfunctions.out -std=c90 --pedantic-errors


#include <stdio.h>


int foo()
{
    /*
    // foo2() a foo() függvényen belül helyezkedik el
    // beágyazott (nested) függvény

    // se C90-nel, se C99-cel nem fordul, viszont -std kapcsoló nélkül lefordul
    // a szabvány nem definiálja a beágyazott függvényeket, ettõl még a
    // gcc ismeri és alapértelmezés szerint elfogadja
    // romlik a kód hordozhatósága
    */
    int foo2() { return 2; }
    return foo2() + 5;
}


int main()
{
    printf("%i\n", foo());
    return 0;
}

