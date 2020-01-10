#include <iostream>

using namespace std;

int main()
{
    //Beolvas
    int N;
    cout << "Hany szavazo adatat szeretne megadni? ";
    cin >> N;

    string nevek[N+1];
    int korok[N+1];
    string szigszamok[N+1];
    int szavazatok[N+1];

    for(int i = 1; i <= N; i++)
    {
        cout << endl << "Kerem a(z) " << (i) << ". szavazo nevet : ";
        cin >> nevek[i];
        cout << endl << "Kerem a(z) " << (i) << ". szavazo korat : ";
        cin >> korok[i];
        cout << endl << "Kerem a(z) " << (i) << ". szavazo szemelyigazolvany szamat : ";
        cin >> szigszamok[i];
        cout << endl << "Kerem a(z) " << (i) << ". szavazo szavazatat : ";
        cin >> szavazatok[i];
    }
    cout << endl;

    //A feladat
    int i = 1;
    while( i <= N && !(szavazatok[i] == i))
        i = i + 1;
    bool VanNemSzavazo = i<=N;

    //B
    int max = 1;
    for(i = 2; i <= N; i++)
        if(korok[i] > korok[max])
            max = i;
    string LegoregebbNev = nevek[max];
    string LegoregebbSzam = szigszamok[max];

    //C
    string MindharonNev[N+1];
    int MindharonVolt[N+1];
    int MindharonDb = 0;
    for(i = 1; i <= N; i++)
        if(szavazatok[i] == 3)
        {
            MindharonDb = MindharonDb + 1;
            MindharonVolt[MindharonDb] = i;
        }

    for(i = 1; i <= MindharonDb; i++)
        MindharonNev[i] = nevek[MindharonVolt[i]];

    //Kiir
    //A
    cout << (VanNemSzavazo ? "Van olyan szavazo aki nem adott le szavazolapot" : "Mindenki adott le szavazolapot") << endl;


    //B
    cout << "A legidosebb valasztopolgar neve: " << LegoregebbNev << ", szigszama: " << LegoregebbSzam << endl;

    //C
    cout << "A mindharom szavazok nevei:" << endl;
    for(i = 1; i < MindharonDb; i++)
        cout << MindharonNev[i] << endl;

    return 0;
}
