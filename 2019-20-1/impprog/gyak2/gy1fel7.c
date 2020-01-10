

#include <stdio.h>

int main()
{
    for (int idx = -40; idx <= 100; idx = idx + 20)
    {
        // az 5/9 egészosztás eredménye 0
        printf("%i    %f\n", idx, (idx - 32) * (5.0/9.0));
    }
}
