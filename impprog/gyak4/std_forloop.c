// fordítás: gcc std_forloop.c -o std_forloop.out -std=c99 --pedantic-errors


#include <stdio.h>


int main()
{
    // C90-nel nem fordul, C99-cel igen
    for (int idx = 0; idx < 10; idx++)
    {
        printf("%i\n", idx);
    }

    // C90-nel:
    /*
    int idx;
    for (idx = 0; idx < 10; idx++)
    {
        printf("%i\n", idx);
    }
    */

    return 0;
}
