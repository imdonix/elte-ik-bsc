#include <iostream>

using namespace std;

// 100/100

int main()
{
    int N,M,K;
    cin >> N >> M >> K;
    int fal[M+1][N+1][2];

    for(int x = 1; x <= M; x++)
        for(int y = 1; y <= N; y++)
            for(int i = 0; i < 2; i++)
                fal[x][y][i]=0;

    for(int i = 0; i < K; i++)
    {
        string szin;
        int SY, SX, EY, EX;
        cin >> szin >> SY >> SX >> EY >> EX;
        int modifier = (szin == "P") ? 1 : -1;

        for(int x = SX; x <= EX; x++)
            for(int y = SY; y <= EY; y++)
            {
                fal[y][x][1] = fal[y][x][0];
                fal[y][x][0] = modifier;
            }

    }

    int P = 0;
    int Z = 0;
    for(int x = 1; x <= M; x++)
        for(int y = 1; y <= N; y++)
            if(fal[x][y][0] + fal[x][y][1])
                if((fal[x][y][0] + fal[x][y][1]) > 0)
                    P++;
                else
                    Z++;


    cout << P << " " << Z;

    return 0;
}
