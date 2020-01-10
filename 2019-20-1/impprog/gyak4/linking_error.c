

#include <stdio.h>


/*
ez a fájl szintaktikaileg helyes, ezért fordul (compiles), viszont
calling_not_existing_function() néven nincs függvény, ezért
a szerkesztõ (linker) nem tud futtatható binárist elõállítani

ez tehát egy linkelési hiba, ami a hibaüzenetbõl is jól látszik:

(.text+0x2d): undefined reference to `calling_not_existing_function'
collect2: error: ld returned 1 exit status

az "ld" (linker) exitkódja volt nemnulla
*/


int main()
{
    printf("hello world");
    // nem létezõ függvény hívása
    calling_not_existing_function();
    return 0;
}

