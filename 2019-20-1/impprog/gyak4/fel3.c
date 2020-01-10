

#include <stdio.h>


int StrToInt(char str[])
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        res = 10 * res + str[i] - '0';
    }
    return res;
}


int main()
{
    int i = StrToInt("6452123");
    printf("%i\n", i);
    return 0;
}

