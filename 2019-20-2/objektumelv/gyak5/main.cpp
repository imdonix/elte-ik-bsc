#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Szamla{
    string nev;
    int osszeg; // a beolvasás egyből a számla végösszegét állítja majd elő
};

enum Status{abnorm, norm};

bool read(ifstream &f, Szamla &e, Status &st);

int main()
{
    ifstream x("inp.txt");
    if (x.fail() ) {
        cout << "hibas fajlnev!\n";
        return 1;
    }

    Szamla dx;
    Status sx;
    int s = 0;
    while(read(x,dx,sx)) {
        s += dx.osszeg  ;
    }

    cout << "A napi bevetel: " << s << endl;
    return 0;
}

bool read(ifstream &f, Szamla &e, Status &st){
    string line;
    getline(f,line);
    if (!f.fail() && line!="") {
        st = norm;
        istringstream in(line);
        in >> e.nev;

        string termek;
        int ar;
        e.osszeg = 0;
        while( in >> termek >> ar ) e.osszeg += ar;
    }
    else st=abnorm;

    return norm==st;
}
