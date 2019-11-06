

#include <stdio.h>


int main()
{
    float a, b;
    printf("Írjon be egy számot: ");
    scanf("%f", &a);
    printf("Írjon be egy számot: ");
    scanf("%f", &b);
    if (b == 0)
    {
        // ha b == 0 igaz
        printf("Nullával nem lehet osztani\n");
    }
    else
    {
        // ha b == 0 hamis
        printf("A hányadosuk: %f\n", a / b);
    }

    return 0;
}
