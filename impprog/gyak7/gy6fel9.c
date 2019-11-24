

#include <stdio.h>


int main()
{
    // ha pointer egy sztringliterálra mutat, akkor a (*pointer)++ és ++(*pointer)
    // nem megengedett kifejezések, mert módosítják a pointer által kijelölt tárolót
    // a sztringliterálok azonban egy potenciálisan nem írható memterületen tárolódnak
    // ezért ez nem definiált viselkedést (undefined behaviour) okoz
    // a program valszeg segfault-olni fog
    //char* pointer = "alfa";

    // a tömbök viszont írhatóak, ezért az alábbi program helyes
    char str[] = "alfa";
    char* pointer = &str[0];

    printf("%c\n", *(pointer++) ); // a; pointer l-re mutat
    printf("%c\n", (*pointer)++ ); // l; str-ben amfa lesz, a pointer m-re mutat
    printf("%c\n", ++(*pointer) ); // n; str-ben anfa, a pointer n-re mutat
}

