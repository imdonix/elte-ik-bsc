
/*
#include <stdio.h>


int main()
{
    int x; // változódeklaráció; formája: adattípus változónév;
    x = 23; // értékadó utasítás; formája: változónév = érték;
    x = 54;
    printf("x = %i\n", x); // % vezérlőkarakter: i jelenti int-et
    printf("x = %i       vmi %i\n", x, 5634);

    printf("Kedves Felhasznalo, irj be egy szamot: ");
    int y;
    scanf("%i", &y);
    printf("Kedves Felhasznalo, az y erteke az hogy: %i", y);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    return 0;
}
*/

#include <stdio.h>


int main()
{
    int a, b;
    printf("Kérek egy számot: ");
    scanf("%i", &a);
    printf("Kérek egy másik számot: ");
    scanf("%i", &b);
    //int c = a + b;
    //printf("összegük: %i\n", c);
    printf("összegük: %i\n", a + b);

    return 0;
}


