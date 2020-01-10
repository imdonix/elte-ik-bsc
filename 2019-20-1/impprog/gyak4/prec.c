

#include <stdio.h>


int f1()
{
    printf("f1\n");
    return 1;
}

int f2()
{
    printf("f2\n");
    return 2;
}

int f3()
{
    printf("f3\n");
    return 3;
}


int main()
{
    // a kifejezések részkifejezéseinek (itt f3(), f1(), f2()) bármilyen sorrendben
    // kiértékelődhet (itt ez az f3(), f1(), f2() függvényhívásokat jelenti)
    // a precedencia nem a kiértékelési sorrendet határozza meg, hanem azt, hogy
    // itt a szorzás magasabb rendű mint az összeadás, ezért az 1 és 2 értékeket
    // előbb össze kell szorozni, majd utána hozzáadni a 3-at
    int i = f3() + (f1() * f2());
}

// precedencia: a matematikai jellegû "magasabb rendû", zárójelezési sorrend (order of computation)
// asszociativitás: zárójelezési sorrend azonos precedencia esetén
// a kifejezések részkifejezéseinek kiértékelési sorrendje nem definiált (hatékonysági okokból)
