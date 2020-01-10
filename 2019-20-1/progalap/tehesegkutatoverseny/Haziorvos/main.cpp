#include <iostream>

using namespace std;

int abs(int x)
{
    if(x > 0) return x;
    else return -x;
}

// 100/100

int isInRange(int x, int y, int K)
{
    return abs(x-y) <= K;
}

int main()
{
    int V,M,N,K;
    cin >> V >> M >> N;
    int citys[V+1], jobs[M+1], worker[N+1];
    for(int i = 1; i <= V; i++) cin >> citys[i];
    for(int i = 1; i <= M; i++) cin >> jobs[i];
    for(int i = 1; i <= N; i++) cin >> worker[i];
    cin >> K;

    int i = 1;
    int k = 1;
    int found = 0;

    while (i <= M && k <= N)
    {
        int job = citys[jobs[i] >= V ? V : jobs[i]];
        int work = citys[worker[k]];
        if(isInRange(job, work, K))
        {
            found++;
            i++;
            k++;
        }
        else if(job - work > K) k++;
        else i++;
        //cout << i << " - " << k << "  " << found << endl;
    }

    cout << found;


    return 0;
}
