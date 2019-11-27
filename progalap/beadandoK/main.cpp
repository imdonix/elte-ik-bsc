#include <iostream>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    int tempetures[M];
    int hotcolds[M];
    int temp;
    int db = 0;

    for(int x=0;x<M;x++)
            cin >> tempetures[x];

    for(int x=1;x<N;x++)
        for(int y=0;y<M;y++)
        {
            cin >> temp;
            if(tempetures[y] > temp)
                tempetures[y] = temp;
        }

    temp = tempetures[0];
    for(int x=1;x<M;x++)
        if(tempetures[x] > temp)
            temp = tempetures[x];

    for(int x=0;x<M;x++)
        if(tempetures[x] == temp)
            hotcolds[db++] = x;

    cout << db;
    for(int x=0;x<db;x++)
        cout << " " << (hotcolds[x]+1);

    return 0;
}
