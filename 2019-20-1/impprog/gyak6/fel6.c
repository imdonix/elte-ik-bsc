
#include <stdio.h>


int main()
{
    /*
    int arr[] = {-1, -2, -3};
    int* ptr;
    ptr = &arr[0];
    ptr = ptr + 1;
    printf("%i\n", *ptr);*/

    char str[] = "Sullyed a harossz";
    char* ptr = &str[0];
    ptr = ptr + 1;
    printf("%c\n", *ptr);
}
