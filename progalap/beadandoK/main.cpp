/*
 Készítette: Magyar Tamás
 Neptun: RNYR2F
 E-mail: rnyr2f@inf.elte.hu
 Feladat:
    A meteorológiai intézet az ország N településére adott M napos időjárás előrejelzést, az adott településen az adott napra várt legmagasabb hőmérsékletet.
    Egy napon az a leghűvösebb település, amelyre azon a napon a legkisebb hőmérsékletet jósolják.
    Készíts programot, amely azokat a napokat, amelyeken a leghűvösebb településen a lehető legnagyobb az előre jelzett hőmérséklet!
*/

#include <iostream> //Standart Input/Output
#include <sstream> //Stringstream a kiírások miatt

#define BIRO

using namespace std;

typedef short int SInt;

const SInt MAX = 1000;

void readOne(SInt *num, string text, int min, int max);
void GetColdestDays(SInt tempetures[][MAX], SInt N, SInt M, SInt colds[]);
int GetMax(SInt colds[], SInt M);
void SortOutByValue(SInt colds[], SInt M, SInt hotcolds[], SInt *db, SInt max);

int main()
{
    ios_base::sync_with_stdio(false);

    SInt N,M;
    readOne(&N, "Add meg a telepulesek szamat: ", 1, 1000);
    readOne(&M, "Add meg a napok szamat: ", 1, 1000);

    SInt tempetures[N+1][MAX];
    SInt colds[M+1];
    SInt hotcolds[M+1];
    SInt db;

    //beolvasás
    for(int x=1;x<=N;++x)
        for(int y=1;y<=M;++y)
        {
            #ifdef BIRO
                readOne(&tempetures[x][y], "", -50, 50);
            #else
                string str;
                stringstream ss;
                ss.str("");
                ss << "Add meg a(z) "; ss << x;
                ss << ". napot a(z) "; ss << y;
                ss << ". telepulesen mert adatot: ";
                getline(ss, str);
                readOne(&tempetures[x][y], str, -50, 50);
            #endif
        }

    //feldolgozás
    GetColdestDays(tempetures, N, M, colds);
    SortOutByValue(colds, M, hotcolds, &db, GetMax(colds, M));


    //kiírása
    #ifdef BIRO
        cout << db;
        for(int x=1;x<=db;++x)
            cout << " " << hotcolds[x];
    #else
        cout << db;
        cout << " db napon a leghuvosebb telepulesen a leheto legnagyobb az elore jelzett homerseklet" << endl << "Ezen a napok sorszamai: ";
        for(int x=1;x<=db;++x)
            cout << " " << hotcolds[x] << ".";
    #endif

    return 0;
}

//alprogramok

void readOne(SInt *num, string text, int min, int max)
{
    #ifdef BIRO
        cin >> *num;
    #else
        cout << text;
        while(!(cin >> *num) || *num > max || *num < min)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Hibasan adta meg az adatot, kerem probalja ujra: ";
        }
    #endif
}

void GetColdestDays(SInt tempetures[][MAX], SInt N, SInt M, SInt colds[])
{
    for(int y=1;y<=M;++y)
        colds[y] = tempetures[1][y];

    for(int x=2;x<=N;++x)
        for(int y=1;y<=M;++y)
            if(tempetures[x][y] < colds[y])
                colds[y] = tempetures[x][y];
}

int GetMax(SInt colds[], SInt M)
{
    SInt max = colds[1];
    for(int x=2;x<=M;++x)
        if(colds[x] > max)
            max = colds[x];
    return max;
}

void SortOutByValue(SInt colds[], SInt M, SInt hotcolds[], SInt *db, SInt max)
{
    *db = 0;
    for(int x=1;x<=M;++x)
        if(colds[x] == max)
            hotcolds[++(*db)] = x;
}
