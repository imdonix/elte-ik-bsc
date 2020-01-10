

#include <stdio.h>


int main()
{
    int i;
    for (i = 2002; i > 0; i--)
    {
        if (i % 123 == 0)
        {
            printf("%i\n", i);
            return 0;
        }
    }
}

