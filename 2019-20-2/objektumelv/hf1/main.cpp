#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int max(vector<int> &x);
void beolvas(vector<int> &x);

int main(){
    setlocale(LC_ALL, "hun");
    
    vector<int> x;
    beolvas(x);

    cout << "A leggyakoribb szam: " << max(x);

    return 0;
}

int max(vector<int> &x){
    int max = 0;
    int val = 0;
    for(int i=0;i<x.size();i++)
    {
        int temp = 0;
        for(int j=0;j<x.size();j++)
            if(x[i] == x[j])
                temp++;

        if(temp > max)
        {
            max = temp;
            val = x[i];
        }
    }
    return val;
}

void beolvas(vector<int> &x){
    ifstream f;
    bool hiba;
    do{
        cout << "Adja meg a file nevet: " << endl;
        string s;
        cin >> s;
        f.open(s.c_str());
        hiba = f.fail();
        if(hiba){
            cout << "nem sikerült megnyitni" << endl;
            f.clear();
        }
    }while(hiba);
    int a;
    while(!f.eof()){
        f >> a;
        x.push_back(a);
    }
}