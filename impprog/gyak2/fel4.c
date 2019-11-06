

#include <stdio.h>


int main()
{
    char str[64];
    gets(str);
    int count_a = 0, count_e = 0, count_i = 0, count_o = 0, count_u = 0;
    // a ciklus addig lépeget elõre a sztringben, amíg az aktuális karakter
    // nem a '\0' (sztringvége jel)
    for (int idx = 0; str[idx] != '\0'; idx++)
    {
        switch (str[idx])
        {
            case 'a':
            {
                count_a++;
                break;
                // a switch általános (tipikus) használata esetén a case blokkok
                // végén kell írni egy break; utasítást
            }
            case 'e':
            {
                count_e++;
                break;
            }
            case 'i':
            {
                count_i++;
                break;
            }
            case 'o':
            {
                count_o++;
                break;
            }
            case 'u':
            {
                count_u++;
                break;
            }
        }
    }
    printf("a: %i\ne: %i\ni: %i\no: %i\nu: %i\n", count_a, count_e, count_i, count_o, count_u);
    return 0;
}

