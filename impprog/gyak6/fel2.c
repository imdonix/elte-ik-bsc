

#include <stdio.h>


void foo(int x)
{
    // Írja ki itt x memóriacímét és értékét
    printf("x = %i, x memcime: %p\n", x, &x);
    x = 20;
}

void foo2(int* x)
{
    *x = 20;
}


int main()
{
    foo(7);

    int var = 10;

    // Írja ki itt var memóriacímét és értékét
    printf("var = %i, var memcime: %p\n", var, &var);

    foo(var);
    printf("var = %i, var memcime: %p\n", var, &var);

    foo2(&var);
    printf("var = %i, var memcime: %p\n", var, &var);
    return 0;
}

