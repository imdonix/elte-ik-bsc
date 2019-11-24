

// b

#include <stdio.h>
#include <stdlib.h>


// a foo() függvény nem foglalt le memóriaterületet, hanem
// megkapja azt a pointer-t, amely arra a területre mutat,
// ahol dolgozhat
void foo(int num, char ch, char* ptr)
{
    for (int i = 0; i < num; ++i)
    {
        *(ptr + i) = ch;
    }
    *(ptr + num) = '\0';
}


int main()
{
    int num = 3;
    char* res = (char*)malloc((num + 1) * sizeof(char)); // a hívó fv allokál
    foo(3, 'C', res);
    printf("%s\n", res);
    free(res); // a hívó fv takarít
}
