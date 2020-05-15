#include "system.h"
#include "crew.h"
#include "student.h"

using namespace std;

System::System(int n, int m, int c) : lab(c)
{
    for(int i = 0; i<n; ++i){
        Crew *crew = new Crew(i+1, this);
        crews.push_back(crew);
    }
    for(int j = 0; j<m; ++j){
        Student *stud = new Student(j+1, this);
        students.push_back(stud);
    }
}

System::~System()
{
    for(int i = 0; i<(int)crews.size(); ++i){
        delete crews[i];
    }
    for(int j = 0; j<(int)students.size(); ++j){
        delete students[j];
    }
}
