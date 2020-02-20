#pragma once
#include "pont.h"


class Kor{
    private:
        Pont kp;
        double r;
    public:
        Kor(double x = 0, double y = 0, double r1 = 1){
            r = r1;
            kp = Pont(x, y);
        }
        double area() ;
        bool contains(Pont p);
        double distance(Pont p);
};