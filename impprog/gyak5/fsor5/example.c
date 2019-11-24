
#include <stdio.h>


#include "func_header.h"


int main()
{
    char ex_str1[] = "tesst1";
    reverse(ex_str1);
    // ex_str1 == 1tset
    printf("5. fel: %s\n", ex_str1);

    squeeze(ex_str1, 's');
    printf("6. fel: %s\n", ex_str1);

    char dest[256];
    strcount(dest, 5, 16, 'A');
    printf("strcount() fel res: %s\n", dest);

    printf("fel7 res: %i\n", strany("alma", "wa"));
    printf("fel7 res: %i\n", strany("alma", "wcm"));
    printf("fel7 res: %i\n", strany("alma", "wcz"));

    IntToStr(123, dest);
    printf("fel8 res: %s\n", dest);

    expand("blah a-f 436 a-a a-z string vmi", dest);
    printf("fel9 res: %s\n", dest);
}

