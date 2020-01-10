#include <iostream>

using namespace std;

const int HOUR = 24;
const int MINUTE = 60;
const int WAIT = 10;

int F(int hour, int minute)
{
    return hour * MINUTE + minute;
}

int main()
{
    int N;
    cin >> N;

    bool Bstops[N];
    int Istops[N];
    int stopCount = 0;
    int hour, minute;
    cin >> hour >> minute;

    int maxTime = 0;
    for(int i = 1; i < N; ++i)
    {
        int last = F(hour, minute);
        cin >> hour >> minute;
        int consumed = F(hour, minute) - last;
        int real = (consumed < 0 ? HOUR * MINUTE + consumed : consumed) - (i > 1 ? WAIT : 0);
        maxTime = (maxTime < real) ? real : maxTime;

        if(consumed <= 0)
        {
            Bstops[stopCount] = last % MINUTE > MINUTE - WAIT || last % MINUTE == 0 ;
            Istops[stopCount] = i;
            stopCount++;
        }

    }

    cout << maxTime << endl;
    if(stopCount > 0)
        for(int i = 0; i < stopCount; ++i)
            if(Bstops[i])
            {
                cout << Istops[i] << ' ';
            }
            else
            {
                cout << Istops[i] << '-' << (Istops[i]+1) << ' ';
            }
    else
        cout << 0;

    return 0;
}
