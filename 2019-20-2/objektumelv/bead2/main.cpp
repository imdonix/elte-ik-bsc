//Author:   Magyar Tamás
//Date:     2020-03-29
//Title:    Anglers
#include <iostream>
#include "contest.h"
#include "angler.h"

using namespace std;

//Első feladat
//Leirás: Hány olyan sora van a fájlnak, melyben a fogott halak között a harcsa szerepel?
//Összegzés (megszámlálás)
int count_catfish(const string& src)
{
    ContestEnor t(src);

    int c = 0;
    for(t.first(); !t.end(); t.next())
        if(t.current().catfish_catch)
            c++;

    return c;
}


//Második feladat
//Leirás: Volt-e olyan horgász, aki mindegyik versenyén fogott harcsát?
//Összegzés (eldöntés)
bool is_angler_catch_catfish(const string& src)
{
    AnglerEnor t(src);

    bool l = false;
    for(t.first(); !l && !t.end(); t.next())
        l = l || t.current().skillful;

    return l;
}

int main()
{

    string filename;
    cout<<"Enter the name of the input file, please:"; cin>>filename;

    //Első feladat
    cout<<"First  task\n";
    try
    {
        int counter = count_catfish(filename);
        cout << "The file contain " << counter << " lines wich include a catfish catch!" << endl;
    }
    catch(ContestEnor::FileError err)
    {
        cerr<<"Can't find the input file:"<<filename<<endl;
    }


    //Második feladat
    cout<<"Second task\n";

    try
    {
        if(is_angler_catch_catfish(filename))
            cout << "There is a angler who catched catfish on all constest!" << endl;
        else
            cout << "There is no angler who catched catfish on all constest!" << endl;
    }
    catch(ContestEnor::FileError err)
    {
        cerr<<"Can't find the input file:"<<filename<<endl;
    }

    return 0;
}