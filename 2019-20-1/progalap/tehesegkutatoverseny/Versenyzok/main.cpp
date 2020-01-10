#include <iostream>

using namespace std;

// 100/100 

// Nagy Kicsi
int findIt(int nagy[], int kicsi[], int nagy_l, int kicsi_l)
{
    int i = nagy_l - 1;
    int j = 0;
    while (nagy[i] <= kicsi[j])
    {
        i--;
        j++;
    }
    return nagy[i];
}

int main()
{
    int E,M,H;
    cin >> E >> M >> H;
    int elso[E];
    int masodik[M];
    int harmadik[H];
    for(int i = 0; i < E; i++) cin >> elso[i];
    for(int i = 0; i < M; i++) cin >> masodik[i];
    for(int i = 0; i < H; i++) cin >> harmadik[i];

    cout << findIt(masodik, harmadik, M, H) << endl;
    cout << findIt(elso, masodik, E, M);

    return 0;
}
