
#include <iostream>

using namespace std;

int main()
{
    int recordCount;
    cin >> recordCount;

    int brokenCount = 0;
    bool brokeFlag = false;

    int input;

    for(int i = 0; i < recordCount; i++)
    {

        cin >> input;

        if(input == 0 && brokeFlag == false)
        {
            brokenCount++;
            brokeFlag = true;
        }
        else
        {
            if(input != 0)
                brokeFlag = false;
        }
    }

    if(input==0) brokenCount-=1;

    cout << brokenCount<<endl;
    return 0;
}
