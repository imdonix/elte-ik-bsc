

#include <stdio.h>


int factorial(int base)
{
    int result = 1;

    for (int idx = 1; idx <= base; idx++)
    {
        result = result * idx;
    }
    return result;
}


int main()
{
    printf("%i\n", factorial(5));
    return 0;
}
