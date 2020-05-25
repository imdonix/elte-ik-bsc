#include <iostream>
#include <vector>

using namespace std;

int get(string str, int i) { return str[i] - '0';} 

int main()
{
    int n,d,r;
    string line;
    cout << "d: "; cin >> d; 
    cout << "r: "; cin >> r;
    cout << "lista hossza: "; cin >> n;
    cout << "Add meg a listat [num1 num2 num3]:\n";

    string nums[n];
    vector<string> radix[r];

    for(int i=0;i<n;i++)
        cin >> nums[i];

    cout << "\n\n";

    for(int i=0;i<d;i++)
    {
        for(int k=0;k<r;k++)
            vector<string>().swap(radix[k]);

        for(int k=0;k<n;k++)
            radix[get(nums[k],d-(i+1))].push_back(nums[k]);

        int j=0;
        for(vector<string> v : radix)
            for(string s : v)
                nums[j++] = s;

        for(string s : nums) cout << s << " ";
        cout << endl;
    }

    return 0;
}