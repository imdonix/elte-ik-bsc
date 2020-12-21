#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,M,n,e,m;
    cin >> N >> M;
    
    int verts[N+1] = {};

    cin >> n;
    for(int i = 0; i < M * 2 ; i++, cin >> n)
        verts[n]++;

    e = m = 0;
    for(int i = 0; i < N+1; i++)
    {
        if(verts[i] == 1 && i) e++;
        if(verts[m] < verts[i]) m = i;
    }

    cout << e << " " << m;
    return 0;
}