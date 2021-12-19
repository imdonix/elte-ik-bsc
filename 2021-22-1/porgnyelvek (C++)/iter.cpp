#include <iostream>
#include "mmapview.h"
#include <map>

int main()
{
    multimap_view<int, double> mvid;

    std::map<int, double> m;
    mvid.add( m );

    std::map<int, double> mm;
    mvid.add( mm );


    int c = 0;
    for(multimap_view<int, double>::iterator it = mvid.begin(); !(it == mvid.end()); ++it) 
    {
        for(int i = 0; i < 1000; ++i)
        {
            (*it).insert(std::pair<int, double>(i, (double) (i*c*2)));
        }
        c++;
        
    }

    if(mvid.count(0) != 2 || mvid.count(999) != 2)
    {
        std::cout << "err" << std::endl;
        return 1;
    }

    std::cout << "ok" << std::endl;
    return 0;
}