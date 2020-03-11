// Magyar Tamás | RNYR2F | rnyr2f@inf.elte.hu
// 1. beadandó feladat (6 feladat)

#include <iostream>
#include "nmatrix.h"
#include "read.hpp"

using namespace std;

#define NORMAL_MODE
#ifdef NORMAL_MODE

class Menu
{
    public:
        Menu() : a(0) { }
        void run();
    private:
        NMatrix a;

        void menuWrite();
        void getElement() const;
        void setElement();
        void readMatrix();
        void writeMatrix();
        void sum();
        void mul();
};

int main()
{
    Menu m;
    m.run();
}

bool check(int n) 
{ 
    return 0<=n && n<=5; 
}

void Menu::run()
{
    int n = 0;
    do {
        menuWrite();

        n = read <int> ( "\n>>>>", "integer between 0 and 6 is needed\n", check );

        switch(n)
        {
            case 1:
                getElement();
                break;
            case 2:
                readMatrix();
                break;
            case 3:
                writeMatrix();
                break;
            case 4:
                sum();
                break;
            case 5:
                mul();
                break;
        }
    } 
    while(n!=0);
}

void Menu::menuWrite()
{
    cout << endl << endl;
    cout << " 0. - Quit" << endl;
    cout << " 1. - Get an element of the matrix" << endl;
    cout << " 2. - Read matrix" << endl;
    cout << " 3. - Write matrix" << endl;
    cout << " 4. - Add matrices" << endl;
    cout << " 5. - Multiply matrices" << endl;
}

void Menu::getElement() const
{
    int i,j;
    cout << "Give the index of the row: ";
    cin >> i;
    cout << "Give the index of the column: ";
    cin >> j;
    try
    {
        cout << "a[" << i << "," << j << "]= " << a(i,j) << endl;
    }
    catch(NMatrix::Exceptions ex)
    {
        if(ex == NMatrix::OVERINDEXED)
            cout << "Overindexing!" << endl;
        else
            cout << "Unhandled ecxeption!" << endl;
    }
}

void Menu::readMatrix()
{
    try
    {
        cout << "Give the size and the items of the matrix, first the diagonal items after that the sides left to right : ";
        cin >> a;
    }
    catch(NMatrix::Exceptions ex)
    {
        cout << "Unhandled ecxeption!" << endl;
    }
}

void Menu::writeMatrix()
{
    cout << a << endl;
}

void Menu::sum()
{
    try
    {
        NMatrix b;

        cout << "Give the size and the items of the second  matrix: " << endl;
        cin >> b;
        cout << "Sum of the matrices: " << endl;
        cout << a + b << endl;
    }
    catch(NMatrix::Exceptions ex)
    {
        if(ex == NMatrix::DIFFERENT)
            cout << "Different sizes!" << endl;
    }
}

void Menu::mul()
{
    try
    {
        NMatrix b;

        cout << "Give the size and the items of the second  matrix: " << endl;
        cin >> b;
        cout << "Product of the matrices: " << endl;
        cout << a * b << endl;
    }
    catch(NMatrix::Exceptions ex)
    {
        if(ex == NMatrix::DIFFERENT)
            cout << "Different sizes!" << endl;
    }
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <sstream>

TEST_CASE("create", "[const]")
{
    stringstream ss1("3 1 2 3 4 5 6 7");
    stringstream ss2("2 1 1 1 1");
    stringstream ss3("1 1");

    NMatrix a;
    ss1 >> a; // 3
    CHECK(a(1,1) == 1);
    CHECK(a(2,2) == 2);
    CHECK(a(2,1) == 4);

    NMatrix b;
    ss2 >> b; // 2
    CHECK(b(1,1) == 1);
    CHECK(b(2,1) == 1);

    NMatrix c;
    ss3 >> c; // 1
    CHECK(c(1,1)==1);
}

TEST_CASE("getting and changing an element of the matrix", "[const]")
{
    stringstream ss1("2 1 1 1 1");
    NMatrix a;
    ss1 >> a; // 2

    CHECK(a(1,1) == 1);
    a(1,1) = 0;
    CHECK(a(1,1) == 0);
}

TEST_CASE("add", "[const]")
{
    stringstream ss1("2 1 1 1 1");
    stringstream ss2("2 4 1 2 3");
    stringstream ss3("5 1 2 3 4 5 6 7 8 9 10 11 12 13");
    stringstream ss4("5 4 3 3 1 5 5 7 2 9 1 1 1 1");
    stringstream ss5("1 1");
    stringstream ss6("1 5");


    NMatrix a, b, c, d, e, f, z; // 3
    ss1 >> a; ss2 >> b; 
    ss3 >> c; ss4 >> d; 
    ss5 >> e; ss6 >> z;

    f = a + b;
    CHECK(f(1,1) == 5);
    CHECK(f(2,2) == 2);
    CHECK(f(1,2) == 4);
    CHECK(f(2,1) == 3);

    f = b + a;
    CHECK(f(1,1) == 5);
    CHECK(f(2,2) == 2);
    CHECK(f(1,2) == 4);
    CHECK(f(2,1) == 3);

    f = c + d;
    CHECK(f(1,1) == 5);
    CHECK(f(2,2) == 5);
    CHECK(f(3,3) == 6);
    CHECK(f(2,1) == 11);

    f = e + z;
    CHECK(f(1,1) == 6);
}

TEST_CASE("multiply", "[const]")
{
    stringstream ss1("2 1 1 1 1");
    stringstream ss2("2 4 1 2 3");
    stringstream ss5("1 1");
    stringstream ss6("1 5");


    NMatrix a, b, c, d, f; // 3
    ss1 >> a; ss2 >> b; 
    ss5 >> c; ss6 >> d;

    f = a * b;
    CHECK(f(1,1) == 6);
    CHECK(f(2,2) == 4);
    CHECK(f(1,2) == 4);
    CHECK(f(2,1) == 6);

    f = c * d;
    CHECK(f(1,1) == 5);
}

TEST_CASE("exceptions", "[const]")
{

    NMatrix a(3);

    try
    {
        a(4,4) = 4;
    }
    catch(NMatrix::Exceptions ex)
    {
        CHECK(ex == NMatrix::OVERINDEXED);
    }

    try
    {
        a(0,3) = 4;
    }
    catch(NMatrix::Exceptions ex)
    {
        CHECK(ex == NMatrix::OVERINDEXED);
    }

    NMatrix b(2);
    NMatrix c(3);

    try
    {
        c = a + b;
    }
    catch(NMatrix::Exceptions ex)
    {
        CHECK(ex == NMatrix::DIFFERENT);
    }

    try
    {
        c = a * b;
    }
    catch(NMatrix::Exceptions ex)
    {
        CHECK(ex == NMatrix::DIFFERENT);
    }

    try
    {
        a(1,2) = 4;
    }
    catch(NMatrix::Exceptions ex)
    {
        CHECK(ex == NMatrix::NULLPART);
    }

    try
    {
        int  k = a(1,2);
    }
    catch(NMatrix::Exceptions ex)
    {
        CHECK(ex == NMatrix::NULLPART);
    }
}
#endif