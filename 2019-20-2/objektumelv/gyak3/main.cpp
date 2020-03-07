
#include "priorsor.h"

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE

#include <iostream>

int main()
{
    cout << "Item 1, 2: ";
    Item i1, i2;
    cin >> i1 >> i2;
    PrQueue q;
    try{
    q.max();
    }
    catch(PrQueue::PrQueueError e){
        cout << "hiba";
    }
    q.isEmpty();
    q.add(i1);
    q.add(i2);

    cout << q.max();

    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("isEmpty", "[PrQueue]"){

    PrQueue q;
    SECTION("Kezdetben üres sor"){
        CHECK(q.isEmpty() == true);
        CHECK(q.isEmpty() == true);
    }
    SECTION("Elem hozzáadása után"){
        Item i1 = Item("asd", 10);
        q.add(i1);
        CHECK(q.isEmpty() == false);
        q.remMax();
        CHECK(q.isEmpty() == true);
    }


}

TEST_CASE("empty Queue"){
    PrQueue q;
    CHECK_THROWS(q.remMax());
    CHECK_THROWS(q.max());
}



#endif
