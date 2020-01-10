#include <iostream>

using namespace std;

int tobszor(int arr[], int n, int val)
{
    int db = 0;
    for(int i=0;i<n;i++)
        if(arr[i] == val)
            db++;
    return db;
}
int main()
{
    int M,T;
    cin >> M >> T;
    int tornadok[T];
    for(int i=0;i<T;cin >> tornadok[i++]);

    //1
    cout << "#" << endl;
    int egyedi[T];
    int db = 0;
    for(int x=0;x<T;x++)
        if(!tobszor(egyedi, db, tornadok[x]))
            egyedi[db++] = tornadok[x];
    cout << (M-db) << endl;

    //2
    cout << "#" << endl;
    int x;
    for(x=1;x<=M;x++)
        if(tobszor(tornadok, T, x-1) == 1 && tobszor(tornadok, T, x) == 1 && tobszor(tornadok, T, x+1) == 1)
            break;
    cout << x << endl;

    //3
    cout << "#" << endl;
    int max = 0;
    int adb = 0;
    for(int x=1;x<=M+1;x++)
        if(tobszor(tornadok, T, x) == 0)
            adb++;
        else
        {
            if(adb > max)
                max = adb;
            adb = 0;
        }
    cout << max << endl;

    //4
    cout << "#" << endl;
    max = tobszor(tornadok, T, tornadok[0]);
    for(int x=1;x<T;x++)
        if(tobszor(tornadok,T, tornadok[x]) > max)
           max = tobszor(tornadok,T, tornadok[x]);
    cout << max << endl;

    //5
    cout << "#" << endl;
    max = -1;
    db = 0;
    int start = 1;
    int end = 1;
    int s = 0;
    for(int x=1;x<=M+1;x++)
        if(tobszor(tornadok, T, x))
            db++;
        else
        {
            if(db > max)
            {
                max = db;
                start = s;
                end = x;
            }
            s = x;
            db = 0;
        }
    cout << (start+1) << " " << (end-1);
    return 0;
}




