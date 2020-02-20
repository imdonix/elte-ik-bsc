#include <iostream>
#include <fstream>
#include <vector>
#include "pont.h"
#include "kor.h"
#include <math.h> 

using namespace std;

int main(){
    ifstream f;
    f.open("input.txt");
    if(f.fail())
    {
        cout << "nincs ilyen file";
        return 1;
    }

    double x, y, r;
    f >> x >> y >> r;
    Kor kor(x, y, r);

    vector<Pont> pontok;
    while(!f.eof()){
        f >> x >> y;
        Pont p(x, y);
        pontok.push_back(p);
    }

    int i = 0;
    
    while(i < pontok.size() 
        && !kor.contains( pontok[i]))
    {i++;}

    if(i >= pontok.size()){
        cout << "nem volt ilyen pont." << endl;
    }
    else{
        cout << pontok[i].getX() << " " 
            << pontok[i].getY() << endl;
    }

    return 0;
}

double Pont::distance(Pont p2){
    double dx = x - p2.x;
    double dy = y - p2.y;
    return sqrt((dx * dx) + (dy*dy));
}

double Kor::area(){
    return r*r*M_PI;
}

double Kor::distance(Pont p){
    return p.distance(kp);
}

bool Kor::contains(Pont p){
    return distance(p) <= r;
}

