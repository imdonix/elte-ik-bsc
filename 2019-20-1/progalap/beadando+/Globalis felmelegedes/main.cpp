#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); // gyorsabb olvasas, sok input miatt

    int N,M;
    cin >> N >> M;
    int tempeture[N][M];
    double avarage[N];

    //temp nullazasa
    for(int x=0;x<N;x++)
        for(int y=0;y<M;y++)
            cin >> tempeture[x][y];

    //1-2 atlagok meghatarozasa
    int sum;
    for(int x=0;x<N;x++)
    {
        sum = 0;
        for(int y=0;y<M;y++)
            sum+=tempeture[x][y];
        avarage[x]=(double)sum/M;
    }

    //1 maxkeres
    int max = 0;
    for(int x=1;x<N;x++) if(avarage[x] > avarage[max]) max = x;
    cout << (max+1) << endl; //egytol indexel a feladat

    //2 kivalasztas
    int start=0;
    while (avarage[max-start] > avarage[max-start-1] && max-start > 0) start++;
    cout << (max - start + 1) << endl; //egytol indexel a feladat

    //3-4  Megkeresem a legnagyobb homersekleteket naponta
    int maxes[M];
    for(int x=0;x<M;x++) maxes[x] = tempeture[0][x]; // tomb nullazas
    for(int x=1;x<N;x++)
        for(int y=0;y<M;y++)
            if(maxes[y] < tempeture[x][y])
                maxes[y]=tempeture[x][y];

    //3  megszamlalas
    int melegebbnapok=0;
    for(int x=0;x<M;x++)
        if(maxes[x] == tempeture[N-1][x])
            melegebbnapok++;
    cout << melegebbnapok << endl;


    //4  kivalasztas => lesz olyan nap
    int melegnap = 0;
    for(int x=0;x<N&&!melegnap;x++)
        for(int y=0;y<M;y++)
            if(maxes[y] == tempeture[x][y])
                melegnap=x;

    cout << (melegnap+1);
    return 0;
}
