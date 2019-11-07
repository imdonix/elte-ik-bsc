#include <iostream>

using namespace std;

int osztoosszeg(int x);
bool tokeletes(int x);
bool baratsagos(int x, int y);
void soronkent(string s);
long long int fakt(int n);
int fib(int n);

int main()
{
    int n,m;
    string s;
    cout << "Irjon be egy szampart!" << endl;
    cin >> n >> m;
    cout << "Irjon be egy szot!" << endl;
    cin >> s;

    soronkent(s);
    cout << fib(n);

    /*
    for(int i = 1; i < n; i++)
        if(tokeletes(i))
            cout << i << endl;
    */

    /*
    if(baratsagos(n,m))
        cout << "az" << endl;
    else
        cout << "nem az" << endl;
    */

    /*
    for(int i = 1; i < n; i++)
        for(int j = 1; j < n; j++)
            if(baratsagos(i,j))
                cout << i << ":" << j << endl;
    */

    return 0;
}

int osztoosszeg(int x)
{
    int ossz = 0;
    for(int i = 1; i <= x/2; i++)
        if(x % i == 0)
            ossz += i;
    return ossz;
}

bool tokeletes(int x)
{
    return osztoosszeg(x) == x;
}

bool baratsagos(int x, int y)
{
    return osztoosszeg(x) == y && osztoosszeg(y) == x;
}


void soronkent(string s)
{
    for(int i = 0; s[i]; i++) //mivel a '\0' karakter erteke 0 ezért ha bármi más van ott akkor igaz értéket ad
        cout << s[i] << endl;
}

long long int fakt(int n)
{
    long long int prod = 1;
    for(;n > 1; n--)
        prod *= n;
    return prod;
}


int fib(int n)
{
    int last = 1;
    int now = 1;
    for(int i = 2; i < n; i++)
    {
        int temp = now;
        now = last + now;
        last = temp;
    }

    return now;
}



