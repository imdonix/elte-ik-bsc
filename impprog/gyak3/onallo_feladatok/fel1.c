

#include <stdio.h>
#include <math.h>


int main()
{
    float a, b;
    printf("Írjon be egy alapot: ");
    scanf("%f", &a);
    printf("Írjon be egy kitevõt: ");
    scanf("%f", &b);
    printf("Eredmény: %f\n", pow(a, b));
    return 0;
}

