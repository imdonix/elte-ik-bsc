

#include <stdio.h>
#include <string.h>


int main()
{
    // a mai legtöbb rendszeren a változók nem egymás mellett tárolódnak a stack-en
    // de ez implementációfüggõ
    // egy olyan rendszeren, ahol az is_admin rögtön a pwd után tárolódik,
    // a következõ program könnyen adminként autentikálhatja a felhasználót,
    // ha 20 karakternél többet gépel be
    char pwd[20];
    int is_admin = 0;
    printf("Enter password: ");
    // a gets() nem kapja meg, hogy mennyi a pwd max mérete, ezért könnyen túlírhatja azt
    gets(pwd); // gets(&arr[0]);
    if (strcmp(pwd, "password"))
    {
        is_admin = 1;
    }
    else
    {
        printf("Wrong passwd");
    }

    /*
    scanf("%i", &i); // ok
    scanf("%s", pwd); // ugyanaz a probléma mint gets()-el
    */
}
