

#include <stdio.h>


int main()
{
    int a = 10;
    int b = 200;
    for (int idx = a; idx <= b; idx++)
    {
        if (idx % 7 == 0 || idx % 11 == 0) // || logikai vagy
        {
            printf("%i\n", idx);
        }
    }
    return 0;
}
