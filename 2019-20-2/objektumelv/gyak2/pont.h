#pragma once

class Pont{
    private: 
        double x, y;
    public: 
        Pont(double x1 = 0, double y1 = 0){
            x = x1;
            y = y1;
        }
        double getX() { return x; }
        double getY() { return y; }
        void setX(double x1) {x = x1;}
        void setY(double y1) {y = y1;}
        double distance(Pont p2);
};