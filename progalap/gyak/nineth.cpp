#include <iostream>
using namespace std;

void tombir(int x[], int n);
void rotatebalra(int x[], int n);

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for(int i=0;i<N; cin >> arr[i++]);
    tombir(arr, N);
    rotatebalra(arr, N);
    tombir(arr, N);
    return 0;
}

void tombir(int x[], int n)
{
    for(int i = 0; i<n;i++)
        cout << x[i];
    cout << endl;
}

void rotatebalra(int x[], int n)
{
    int temp = x[0];
    for(int i = 0; i < n-1; x[i] = x[++i] )
        
    x[n-1] = temp;
}
