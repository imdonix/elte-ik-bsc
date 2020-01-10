

#include <stdio.h>
#include <limits.h>


int inc(int x)
{
    if (x == INT_MAX)
    {
        return x;
    }
    else
    {
        return x + 1;
    }
}

int main()
{
    int i = inc(8);
    printf("%i\n", i);
}

