

#include <stdio.h>


int main()
{
    double d = 3.14;
    int i = 23;
    char c = 'A';

    double* pd;
    int* pi;
    char* pc;

    pd = &d;
    pi = &i;
    pc = &c;

    printf("d memcime = %p, d = %lf, meret: %i\n", &d, d, sizeof(d));
    printf("i memcime = %p, i = %i, meret: %i\n", &i, i, sizeof(i));
    printf("c memcime = %p, c = %c, meret: %i\n", &c, c, sizeof(c));

    printf("pd memcime = %p, pd = %p, meret: %i\n", &pd, pd, sizeof(pd));
    printf("pi memcime = %p, pi = %p, meret: %i\n", &pi, pi, sizeof(pi));
    printf("pc memcime = %p, pc = %p, meret: %i\n", &pc, pc, sizeof(pc));
}
