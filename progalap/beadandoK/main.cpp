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
#include <string> //String összefűzés

//#define BIRO

using namespace std;

void readOne(int *num, string text, int min, int max);
void ReadAllAndSelectMax(int *tempetures, int N, int M);
int getMaximum(int tempetures[], int length);
void sortOut(int tempetures[], int M, int hotcolds[], int *db, int max);
void writeOut(int hotcolds[], int M);

int main()
{
    ios_base::sync_with_stdio(false);

    int N,M;
    readOne(&N, "Add meg a telepulesek szamat: ", 1, 1000);
    readOne(&M, "Add meg a napok szamat: ", 1, 1000);

    int tempetures[M];
    int hotcolds[M];
    int db = 0;

    ReadAllAndSelectMax(tempetures, N,M);
    sortOut(tempetures, M, hotcolds, &db, getMaximum(tempetures, M));
    writeOut(hotcolds, db);

    return 0;
}

void readOne(int *num, string text, int min, int max)
{
    #ifdef BIRO
        cin >> *num;
    #else
        cout << text;
        while(!(cin >> *num) || *num > max || *num < min){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Hibasan adta meg az adatot, kerem probalja ujra: ";
        }
    #endif
}

void ReadAllAndSelectMax(int *tempetures, int N, int M)
{
    int temp;
    for(int x=0;x<N;++x)
        for(int y=0;y<M;++y)
        {
            #ifdef BIRO
                readOne(&temp, "", -50, 50);
            #else
                readOne(&temp, "Add meg a(z) " + to_string(x+1) + ". napot a(z) " + to_string(y+1) + ". telepulesen mert adatot: ", -50, 50);
            #endif

            if(tempetures[y]>temp || x==0)
                tempetures[y] = temp;
        }
}

int getMaximum(int tempetures[], int length)
{
    int max = tempetures[0];
    for(int x=1;x<length;++x)
        if(tempetures[x] > max)
            max = tempetures[x];
    return max;
}

void sortOut(int tempetures[], int M, int hotcolds[], int *db, int max)
{
    for(int x=0;x<M;x++)
        if(tempetures[x] == max)
            hotcolds[(*db)++] = x;
}

void writeOut(int hotcolds[], int M)
{
    #ifdef BIRO
        cout << M;
        for(int x=0;x<M;++x)
            cout << " " << (hotcolds[x]+1);
    #else
        cout << M;
        cout << " napon a leghuvosebb telepulesen a leheto legnagyobb az elore jelzett homerseklet, ezek a napok: " << endl;
        for(int x=0;x<M;++x)
            cout << " " << (hotcolds[x]+1) ;
    #endif
}
