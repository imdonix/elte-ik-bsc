

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



// ./fel7.out arg1 arg2 ... argN; terminálból futtatva a programot a program neve után szóközzel
// megadott adatokat a program megkapja az argv[] tömbben
// argc: hány argumentum van (az elsõ mindig a program neve)
// a tömb elemei char-ra mutató pointer-ek
// használat: ./fel7.out [min] [max]
int main(int argc, char* argv[]) // mivel elsõ elemre mutató pointer-ré alakul, ezért ugyanaz mint char** argv
{
    // ha nem megfelelõ a program paraméterezése, 1-es exitkóddal leáll a program
    if (argc != 3)
    {
        printf("Invalid interval\n");
        return 1;
    }

    int a, b;
    // atoi(s): az s string-et számmá alakítja
    a = atoi(argv[1]);
    b = atoi(argv[2]);

    int win;
    srand(time(NULL));
    // rand() 0 és RAND_MAX közötti értékkel tér vissza
    win = rand() % (b - a + 1) + a;
    int choice;
    printf("win = %i\n", win);
    do
    {
        printf("Írjon be egy tippet: ");
        scanf("%i", &choice);
        if (choice < win)
        {
            printf("A tipp kisebb\n");
        }
        else if (choice > win)
        {
            printf("A tipp nagyobb\n");
        }
    } while(choice != win);

    printf("Eltalálta\n");
    return 0;
}
