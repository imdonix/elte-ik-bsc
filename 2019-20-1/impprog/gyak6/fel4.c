

#include <stdio.h>


void swap(int* px, int* py)
{
    int tmp = *px;
    *px = *py;
    *py = tmp;
}


int main()
{
    int x = 5;
    int y = 7;
    swap(&x, &y);
    printf("x = %i\ny = %i\n", x, y);
}

