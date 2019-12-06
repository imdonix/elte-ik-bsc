

#include <stdio.h>
#include <stdlib.h>


int main()
{
    char* buf = malloc(5);
    printf("%p\n", buf);
    // size_t: sizeof() visszatérési típusa, objektumok méretének tárolására
    // alkalmas, egész jellegû, elõjel nélküli típus
    size_t s = 5;
    // beolvas stdin-rõl egy sort, a buf által címzett területre
    // ha a lefoglalt terület mérete nem elég nagy, realloc()-t hív,
    // az új méretet pedig s-be írja
    getline(&buf, &s, stdin);
    printf("%s\n", buf);
    printf("%i\n", s);
    printf("%p\n", buf);

    // ha buf == NULL és s == 0, akkor a getline() malloc()-ol
}
