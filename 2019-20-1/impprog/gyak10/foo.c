
#include <stdio.h>


// globális static változó: erre a fordítási egységre névre globális, viszont a generált
// fájlból nem látszik ki az i változó
// static int i = 0;


void counter()
{
    // lokális static változó: a fv hívások közben is megõrzi értékét, egyszer inicializálódik
    // a legelsõ fv híváskor
    static int i = 0;
    i++;
    printf("counter(): %i\n", i);
    // ...
}

