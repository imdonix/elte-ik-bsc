// Algo ZH1 
// Feladat: Két L1 lista metszete, az első listába képezve.
// Készítette: Magyar Tamás
// Dátum: 2020.04.09.
// Fordító: gcc 7.2.0 Target: x86_64-w64-mingw32

#include <stdio.h>
#include "list.h"

#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    char line[INP_LENGTH];
    E1 *A, *B;

    printf("Az egesz szamokat novekedo sorrendben szokozzel elvalasztva add meg!\nA hibas elemek torlodnek a listabol!\n");

    printf("Add meg az A halmaz elemeit!\n");
    fgets(line, sizeof(line), stdin), A = parse(line);
    printf("Add meg az B halmaz elemeit!\n");
    fgets(line, sizeof(line), stdin), B = parse(line);

    interselect(A, B);

    printf("A metszet B elemei: ");
    printList(A);

    return 0;
}

#else

#define FILE "input.txt"
#define TESTS 10
int run();

//A teszt fájlban 3-masával vannak felsorolva a halmazok, a hármas csoport az A,B,várt eredmény halmazt tartalmazza
//akkor sikeres a teszt ha az elvégzés után az eredmény megegyezik a várt eredményel.

int main()
{
    int ret = run();
    if(!ret)
        printf("All the %i test cased passed!\n", TESTS);
    else
        printf("%i test(s) failed!\n",ret);
    return 0;
}

//Run all test case
int run()
{
    E1* lists[TESTS*3];
    int length;

    int succesTests = 0;
    if(!readListsFromFile(FILE, lists, &length))
        for(int i=0;i<length;i+=3)
        {
            interselect(lists[i], lists[i+1]);
            if(eqv(lists[i], lists[i+2])) succesTests++;
        }
    return TESTS - succesTests;
}

#endif