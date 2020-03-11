//Author:    Gregorics Tibor
//Date:     2015.02.22.
//Title:    Universal reading from keyboard

#pragma once

#include <iostream>
#include <string>

//Task: 	Read an Item type data from the keyboard
//Input:    string msg - text that must be written before reading
//          string err - text that must be written after a
//          bool valid(Item) - function that checks the correctness of the data that is read
//Output:   Item  n    - the value the data that is read
//Activity:	Reading a data from the keyboard, checking it according to the function valid
//          if the data is incorrect trying to read it once more
template <typename Item>
Item read( const std::string &msg, const std::string &err, bool valid(Item))
{
    Item n;
    bool wrong;
    do{
        std::cout << msg;
        std::cin >> n;
        if((wrong = std::cin.fail())) std::cin.clear();
        std::string tmp = "";
        getline(std::cin, tmp);
        wrong = wrong || tmp.size()!=0 || !valid(n);
        if(wrong) std::cout << err << std::endl;
    }while(wrong);
    return n;
}
