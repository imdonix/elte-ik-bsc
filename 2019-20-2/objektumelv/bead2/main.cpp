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

#define NORMAL_MODE
#ifdef NORMAL_MODE

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

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//sum first task

TEST_CASE("first task empty file", "t0.txt") 
{

    CHECK(count_catfish("t0.txt") == 0);
}

TEST_CASE("first task 1 angler, true", "t2.txt") 
{
    CHECK(count_catfish("t2.txt") == 1);
}

TEST_CASE("first task 1 angler, false", "t13.txt") 
{
    CHECK(count_catfish("t13.txt") == 0);
}

TEST_CASE("first task more anglers, first one meets the requirements", "tt3.txt") 
{
    CHECK(count_catfish("tt3.txt") == 3);
}

TEST_CASE("first task more anglers, third one meets the requirements", "tt5.txt") 
{
    CHECK(count_catfish("tt5.txt") == 5);
}

TEST_CASE("first task more anglers", "tt6.txt") 
{
    CHECK(count_catfish("tt6.txt") == 5);
}

TEST_CASE("first task more anglers, few meets the requirements", "t6.txt") 
{
    CHECK(count_catfish("t6.txt") == 4);
}

// file check

TEST_CASE("no catch", "t8.txt") 
{
    ContestEnor tt("t8.txt");
    tt.first();
    CHECK_FALSE(tt.current().catfish_catch);
}

// sum second task

TEST_CASE("empty file", "t0.txt") 
{
    CHECK_FALSE(is_angler_catch_catfish("t0.txt"));
}

TEST_CASE("1 angler", "t2.txt") 
{
    CHECK(is_angler_catch_catfish("t2.txt"));
}

TEST_CASE("more angler more contests", "t4.txt") 
{
    CHECK(is_angler_catch_catfish("t4.txt"));
}

TEST_CASE("all angler is skillful", "t4.txt") 
{
    CHECK(is_angler_catch_catfish("t4.txt"));
}

TEST_CASE("last angler is skillful", "t5.txt") 
{
    CHECK(is_angler_catch_catfish("t5.txt"));
}
#endif