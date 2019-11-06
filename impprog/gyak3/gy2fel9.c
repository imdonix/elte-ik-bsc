

#include <stdio.h>


/*
'A' értéke valójában egy egész szám (65), az A sorszáma az ASCII kódtáblában
a táblában minden kisbetû-nagybetû pár között a különbség ugyanannyi,
ez pedig éppen 32, ami úgy jön ki hogy: 'a' - 'A'
*/

char lower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        return ch + 'a' - 'A';
    }
    else
    {
        return ch;
    }
}


int main()
{
    printf("%c\n", lower('F'));
    printf("%c\n", lower('f'));
}

