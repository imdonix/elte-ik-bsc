

#include <stdio.h>


int func()
{
    printf("hello");
    return 12;
}


// a globális változók használatát erősen meg kell indokolni,
// mert több szempontból is problémás a használatuk

int i = func();


int main()
{
    printf("world");
}
