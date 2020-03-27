#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

struct Szamla{ int osszeg; bool elegnagyok; };

enum Status{abnorm, norm};

bool read(ifstream &f, Szamla &e, Status &st);
bool felt(Szamla sz);

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
    int db = 0;
    //Összegzés + Feltételes megszámlálás(Speciális összegzés)
    while(read(x,dx,sx))
    {
        s += dx.osszeg;
        if(dx.elegnagyok)
            db++;
    }
        
    cout << "A napi bevetel: " << s << endl;
    cout << "Van csupa 20000-nel nagyobb szamla?: " << ( (db>0) ? "Van" : "Nincs" ) << endl;
    return 0;
}

bool felt(Szamla sz)
{
    return sz.elegnagyok;
}

bool read(ifstream &f, Szamla &e, Status &st){
    string line;
    getline(f,line);
    if (!f.fail() && line!="") {
        st = norm;
        istringstream in(line);

        string termek;
        int ar;
        //léptetés az első árúhoz, névvel nem foglakozom nincs rá szükség
        while(!(in >> termek >> ar)) in.clear();

        e.osszeg = ar;
        e.elegnagyok = ar >= 20000;
        while( in >> termek >> ar )
        {
            e.osszeg += ar;
            e.elegnagyok = e.elegnagyok && ar >= 20000;
        } 
    }
    else st=abnorm;

    return norm==st;
}