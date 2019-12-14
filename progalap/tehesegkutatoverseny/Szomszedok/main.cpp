#include <iostream>

// 100/79

using namespace std;

void f(short int* nums, int N, int A, int B)
{
    bool find = false;
    int c = 0;
    int m = 0;
    for(int i=0;i<N;++i)
    {
        if(nums[i] == A)
            find = true, m = max(m,c), c = 0;

        if(find && nums[i] != A && nums[i] < B)
            c++;
    }
    cout << m << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);

    int N,M,K,A,B;
    cin >> N >> M >> K;
    short int nums[N];
    for(int i=0;i<N;cin >> nums[i++]);

    for(int i=0;i<K;++i)
    {
        cin >> A >> B;
        f(nums, N, A, B);
    }

    return 0;
}
