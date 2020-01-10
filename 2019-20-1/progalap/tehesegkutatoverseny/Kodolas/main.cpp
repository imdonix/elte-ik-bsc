#include <iostream>

using namespace std;

int codeToVal(char c)
{
    return (c == '+' ? 1 : (c == '-' ? -1 : 0));
}

int main()
{
    ios_base::sync_with_stdio(false);

    int N;
    string code;
    cin >> N >> code;

    int max = 0;
    int min = 0;
    int c = 0;
    for(int x=0;x<N;++x)
    {
        c += codeToVal(code[x]);
        if(max < c)
            max = c;
        if(min > c)
            min = c;
    }

    max = 9 - max;
    min = 0 - min;

    if(min < 1 max > 9 )
    {
        cout << "ROSSZ";
    }
    else
    {
        for(int x=0;x<N+1;++x)
            cout << min, min += codeToVal(code[x]);
        cout << endl;
        for(int x=0;x<N+1;++x)
            cout << max, max += codeToVal(code[x]);
    }


    return 0;
}
