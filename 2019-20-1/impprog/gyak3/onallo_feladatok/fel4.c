

#include <stdio.h>


int ContainsUpcase(char str[], int size)
{
    for (int idx = 0; idx < size; idx++)
    {
        if (str[idx] >= 'A' && str[idx] <= 'Z')
        {
            return 1;
        }
    }
    return 0;
}


int main()
{
    printf("%i\n", ContainsUpcase("alma", 4));
    printf("%i\n", ContainsUpcase("almaEffi", 8));
}

