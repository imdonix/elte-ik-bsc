#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct FeltMaxKerResult{
    bool l;
    int ind;
    int max;
};

FeltMaxKerResult FeltMaxKer(vector<int> &x);
void beolvas(vector<int> &x);

int main(){
    setlocale(LC_ALL, "hun");
    vector<int> x;
    beolvas(x);
    FeltMaxKerResult result = FeltMaxKer(x);
    if(result.l){
        cout  << "max horpadás helye: " << result.ind << ", magassága: " << result.max << endl;
    }
    else cout << "nincs horpadás" << endl;

    return 0;
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

    for(int i = 0; i < x.size(); i++) cout << x[i] << "   ";
}



FeltMaxKerResult FeltMaxKer(vector<int> &x){
    FeltMaxKerResult result; 
    result.l = false;
    for(int i = 1; i < x.size() - 1; i++){
        if(x[i] < x[i + 1] && x[i] < x[i - 1]){
            if(!result.l) { result.l = true; result.max = x[i]; result.ind = i;}
            else if(result.max < x[i]) { result.max = x[i]; result.ind = i;}
        }
    }
    return result;
}