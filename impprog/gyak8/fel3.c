

#include <stdio.h>
#include <stdlib.h>


char* foo(int num, char ch)
{
    char* res = (char*)malloc((num + 1) * sizeof(char));
    for (int i = 0; i < num; ++i)
    {
        *(res + i) = ch;
    }
    *(res + num) = '\0';
    return res;
}


int main()
{
    char* ptr = foo(3, 'C');
    printf("%s\n", ptr);
    free(ptr); // a foo() függvény foglalta le a memóriaterületet
    // a hívó függvénynek (main()) kell felszabadítania azt
    // probléma: a foo() függvény használójának emlékeznie kell arra,
    // h fel kell szabadítani a területet
}
