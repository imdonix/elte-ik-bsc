#include <iostream>

// 100/100

using namespace std;

int f(int* arr, int length)
{
    int max = *arr;
    int min = *arr;
    for(int i=0;i<length;++i)
        if(max < *(arr+i))
            max = *(arr+i);
        else if(min > *(arr+i))
            min = *(arr+i);
    return max - min;
}

int main()
{
    int N,M;
    cin >> N >> M;
    int nums[N];
    for(int i=0;i<N;cin >> nums[i++]);

    int tmp;
    int x = 0;
    int y = f(&nums[0], M);
    for(int i=1;i<=N-M;++i)
        if(y > (tmp=f(&nums[i], M)))
            y=tmp,x=i;

    cout << (x+1) << " " << y;
    return 0;
}
