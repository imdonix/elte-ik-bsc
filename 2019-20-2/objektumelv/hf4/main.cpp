#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Kaktusz{
    string nev;
    string orszag;
    string szin;
    string meret;
};

int main(){
    ifstream f;
    f.open("kaktusz.txt");
    ofstream g1;
    g1.open("mexiresult.txt");
    ofstream g2;
    g2.open("pirosresult.txt");
    ofstream g3;
    g3.open("bothresult.txt");
    Kaktusz k;

    f >> k.nev >> k.orszag >> k.szin >> k.meret;
    while(!f.fail()){
        if(k.szin == "piros" && k.orszag == "mexico") g3 << k.nev << endl;
        if(k.szin == "piros") g2 << k.nev << endl;
        if(k.orszag == "mexico") g1 << k.nev << endl;
        f >> k.nev >> k.orszag >> k.szin >> k.meret;
    }
    g1.close();
    g2.close();
    g3.close();


    return 0;
}