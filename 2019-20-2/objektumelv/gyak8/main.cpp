#include "inFile.h"

using namespace std;

bool emptyFile(const string &fileName);
bool solutionOfAccepted(const string &fileName,Station &elem);
void solutionOfExcellent(const string &fileName);

int main()
{
    cout<< "----- Blackholes closer than 2700 light year -----\n\n";
    string fileName = "input.txt";
    /**cout << "Name of the input file: ";
    cin >> fileName;*/
    try
    {
        if (emptyFile(fileName))
        {
            cout << "Empty file!\n";
            return 1;
        }
        Station elem;
        if (solutionOfAccepted(fileName,elem))
        {
            cout << "Maximal weight of the close blackholes belongs to " << elem.name << " with " << elem.lastWeight << " billion tons.\n\n";
        }
        else
        {
            cout << "There was no close blackhole in the file.\n\n";
        }
        cout << "Average weight of the close blackholes:\n";
        solutionOfExcellent(fileName);
    }
    catch (inFile::Error exp)
    {
        cout << "Wrong file name!\n";
        return 2;
    }
    return 0;
}

bool emptyFile(const string &fileName)
{
    inFileMax t(fileName);
    t.first();
    if (t.end())
    {
        return true;
    }
    return false;
}


bool solutionOfAccepted(const string &fileName, Station &elem)
{
    inFileMax t(fileName);
    bool l = false;
    int max;
    for( t.first() ; !t.end() ; t.next())
    {
        if (l && t.current().close)
        {
            if (t.current().lastWeight > max)
            {
                max = t.current().lastWeight;
                elem = t.current();
            }
        }
        else if (!l && t.current().close)
        {
            l = true;
            max = t.current().lastWeight;
            elem = t.current();
        }
    }
    return l;
}

void solutionOfExcellent(const string &fileName)
{
    inFile t(fileName);
    for( t.first() ; !t.end() ; t.next())
    {
        if (t.current().allClose)
        {
            cout << "\t" << t.current().name << ", average weight: " << t.current().avgOfWeights << endl;
        }
    }
}
