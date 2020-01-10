

#include <stdio.h>
#include <stdlib.h>


/*
// a
// probléma: ez a megoldás nem ellenõrzi, hogy a *dest valid
// memóriaterületre hivatkozik-e (azaz a dest elegendõõ méretû-e)
void strcopy(char* dest, char* src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// b
// ez már jobb: a size-ben megadjuk a maximális méretet,
// amely rendelkezésünkre áll
void strcopy(char* dest, char* src, int size)
{
    // size lokális másolat, minden iterációban csökkentjük 1-gyel
    // az 1 onnan jön, hogy a ciklus után még beírunk egy '\0'-t,
    // amit szintén tárolni kell vhol
    while (*src != '\0' && size-- > 1)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}
*/

void strcopy(char* dest, char* src, int size)
{
    // tömörebb de nehezebben olvasható megoldás
    // C-ben elég elterjedt, szokásos tömörítési mód
    if (size > 0)
        while ((*dest++ = size-- > 1 ? *src++ : '\0'));
}


int main()
{
    //char arr[128];
    char* ptr = (char*)malloc(7 * sizeof(char));
    strcopy(ptr, "string", 128);
    printf("%s\n", ptr);
}

