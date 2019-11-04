#include <iostream>

using namespace std;

int main()
{
    int N,K,T;
    cin >> N >> K;

    int good[N];
    int goodCount = 0;

    for(int i = 0; i < N; ++i)
    {
        cin >> T;
        if(T >= K)
        {
            good[goodCount] = i;
            ++goodCount;
        }
    }

    cout << goodCount << (goodCount == 0 ? "" : " ");

    for(int i = 0; i < goodCount; ++i)
        cout << good[i] + 1 << (i == goodCount - 1 ? "" : " ");

    return 0;
}
