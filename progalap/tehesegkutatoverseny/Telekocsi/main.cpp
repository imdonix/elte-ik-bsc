#include <iostream>

using namespace std;


// 100/100

int main()
{
    const int abc_length = 'z' - 'a' + 1;
    const int seats = 3;

    int N,M;
    int seatless = 0;
    string autosok, utazok;
    cin >> N >> autosok >> M >> utazok;

    int slots[abc_length];
    for(int i = 0; i < abc_length; i++)
        slots[i] = 0;

    for(int i = 0; i < N; i++)
        slots['z' - (autosok[i])]+=seats;
    for(int i = 0; i < M; i++)
        slots['z' - (utazok[i])]-=1;


    for(int i = 0; i < abc_length; i++)
        if(slots[i] < 0)
            seatless-=slots[i];

    cout << (M - seatless);
    return 0;
}
