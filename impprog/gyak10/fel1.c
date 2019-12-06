

#include <stdio.h>
#include <math.h>


// typedef típusleírás azon
// a [típusleírás] típushoz azon néven bevezet egy szinonim nevet
// struct: összetett típus, több típusú adatból álló típus
typedef struct Point
{
    double x; // x és y a Point struct mezõi
    double y;
} point_t;


double distance(point_t p1, point_t p2)
{
    // mezõhivatkozás: változónév.mezõnév formában
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}


int main()
{
    /*
    point_t p1, p2;
    p1.x = 4; // mezõk értékadása
    p1.y = -5;
    p2.x = 4;
    p2.y = 8;
    printf("%lf\n", distance(p1, p2));*/

    // struct inicializálása
    point_t p1 = {.x = 4, .y = -5}, p2 = {.x = 4, .y = 8};
    printf("%lf\n", distance(p1, p2));
}

