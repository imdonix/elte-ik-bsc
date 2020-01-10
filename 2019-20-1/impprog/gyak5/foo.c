#include <string.h>

// #include: a megadott fájl tartalmát bemásolja
// ide fordításkor
#include "func_header.h"


void IntToStr_old(int num, char dest[])
{
    int i = 0;
    do
    {
        dest[i] = num % 10 + '0';
        num = num / 10;
        i++;
    } while(num > 0);
    dest[i] = '\0';
    reverse(dest);
}

void IntToStr(int num, char dest[])
{
    int i = 0;
    do
    {
        dest[i++] = num % 10 + '0';
    } while((num /= 10) > 0);
    dest[i] = '\0';
    reverse(dest);
}


void expand_old(const char src[], char dest[])
{
    int i = 0; // src-n megyünk végig
    int j = 0; // dest-ben hol tartok
    while (src[i] != '\0')
    {
        if (src[i] == '-')
        {
            for (char ch = src[i - 1] + 1; ch < src[i + 1]; ++ch)
            {
                dest[j] = ch;
                ++j;
            }
            if (src[i - 1] == src[i + 1])
            {
               ++i;
            }
        }
        else
        {
            dest[j] = src[i];
            ++j;
        }
        ++i;
    }
    dest[j] = '\0';
}


void expand(const char src[], char dest[])
{
    int i = 0; // src-n megyünk végig
    int j = 0; // dest-ben hol tartok
    int len = strlen(src);
    while (src[i] != '\0')
    {
        if (i + 1 < len && src[i + 1] == '-')
        {
            for (char ch = src[i]; ch < src[i + 2]; ++ch)
            {
                dest[j++] = ch;
            }
            i++;
        }
        else
        {
            dest[j++] = src[i];
        }
        ++i;
    }
    dest[j] = '\0';
}
