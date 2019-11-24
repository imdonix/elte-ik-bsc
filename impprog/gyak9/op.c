

#include <stdio.h>


int main()
{
    int i = 5;
    // kif1 ? kif2 : kif3
    // ha kif1 eredménye nemnulla (igaz), akkor a kifejezés értéke
    // kif2, máskülönben kif3
    printf("%s\n", (i % 2 == 0) ? "páros" : "páratlan");
}

