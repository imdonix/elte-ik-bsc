#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Kaktusz{
    string nev;
    string orszag;
    string szin;
};

int main(){
    ifstream f;
    f.open("kaktusz.txt");
    ofstream g;
    g.open("result.txt");
    Kaktusz k;

    f >> k.nev >> k.orszag >> k.szin;
    while(!f.fail()){
        if(k.szin == "piros") g << k.nev << endl;
        f >> k.nev >> k.orszag >> k.szin;
    }
    g.close();

    return 0;
}