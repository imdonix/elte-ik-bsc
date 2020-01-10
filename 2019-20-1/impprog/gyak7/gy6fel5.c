

#include <stdio.h>


void swap_pointers(int** ptr1, int** ptr2)
{
    int* tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;
}


int main()
{
    int x = 5;
    int y = 7;
    int* px = &x;
    int* py = &y;

    printf("*px = %i, *py = %i\n", *px, *py); // 5, 7

    swap_pointers(&px, &py);

    printf("*px = %i, *py = %i\n", *px, *py); // 7, 5
}

