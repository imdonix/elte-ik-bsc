

#include <stdio.h>


float power(float base, int exponent)
{
    float result = 1;
    for (int idx = 1; idx <= exponent; idx++)
    {
        result = result * base;
    }
    return result;
}


int main()
{
    printf("%f\n", power(2, 4));
    printf("%f\n", power(2.5, 4));
    printf("%f\n", power(2, 10));
}

