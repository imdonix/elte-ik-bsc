

#include <stdio.h>


int main()
{
    /*char ch[10]; // karaktertömb == karaktersorozat == sztring (szöveg)
    ch[0] = 't';
    ch[1] = 'e';
    ch[2] = 's';
    ch[3] = 't';
    ch[4] = '\0'; // a sztringeket \0 -val kell zárni*/
    //char ch[10 + 1] = "test1test2";
    //printf("%s\n", ch);

    /*char str1[32];
    char str2[32];
    printf("Írjon be a nevét: ");
    scanf("%s %s", str1, str2);
    printf("Szia, %s, %s\n", str1, str2);*/

    /*int a, b;
    scanf("%i:::%i", &a, &b);
    printf("a = %i\n b = %i", a, b);*/

    char str[32];
    gets(str); // gets() család elavult, késõbb getline()-t fogunk használni
    printf("Szia, %s\n", str);
    return 0;
}

