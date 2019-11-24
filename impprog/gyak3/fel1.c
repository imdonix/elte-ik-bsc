

#include <stdio.h>


int length(char str[])
{
    /*int i; // for ciklussal
    for (i = 0; str[i] != '\0'; i++)
    {
    }
    return i;*/
    int i = 0; // while ciklussal
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}


int main()
{
    printf("%i\n", length("test"));
}

