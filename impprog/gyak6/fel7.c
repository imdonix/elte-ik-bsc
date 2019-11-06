

#include <stdio.h>


int main()
{
    char str[] = "      Attila";
    char* ptr;
    ptr = &str[0];
    for (; *ptr == ' '; ptr = ptr + 1);
    printf("%c\n", *ptr);
}

