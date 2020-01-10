


#include <stdio.h>


int main()
{
    char dest[256];
    // "alma (63, -34, 5.6, helloworld)"
    sprintf(dest, "%s (%i, %i, %lf, %s)", "alma", 63, -34, 5.6, "helloworld");
    printf("'%s'\n", dest);
}
