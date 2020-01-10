

#include <stdio.h>


int main()
{
    int* pi;
    int x = 14;
    pi = &x;
    int y;
    y = *pi;
    *pi = 20;

    printf("pi = %p\n", pi);
    printf("x memcime = %p\n", &x);
    return 0;
}

