// fordítás: gcc example.c utils.c -o example.out


#include <stdio.h>

// másik fordítási egységből származó függvények fejlécei extern kulcsszóval
extern void reverse(char str[]);
extern void squeeze(char str[], char ch);


int main()
{
    char ex_str1[] = "tesst1";
    //reverse(ex_str1);
    // ex_str1 == 1tset
    //printf("5. fel: %s\n", ex_str1);
    squeeze(ex_str1, 's');
    printf("6. fel: %s\n", ex_str1);
}
