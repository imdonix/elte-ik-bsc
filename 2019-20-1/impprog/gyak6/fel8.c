

#include <stdio.h>


int length(char* ptr)
{
    int res = 0;
    for (; *ptr != '\0'; ptr = ptr + 1)
    {
        res++;
    }
    return res;
}


int main()
{
     char str[] = "vmi";
     char* ptr = &str[0];
     printf("%i\n", length(ptr));
     printf("%i\n", length("vmi2"));
}
