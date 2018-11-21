//  main.cpp
//  adv_cpp_hw_ch17

#include <string>
#include <iostream>
#include <cstddef>
#include <cstdlib>

#include "slist2.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

using namespace KBCode;

int main()
{
    
    Slist<string> myList;
    myList.insert("Hello");
    myList.insert("My name is");
    myList.insert("Donald Trump");
    
    for(ListIterator<string> n = myList.begin(); n != myList.end(); ++n)
        cout << n << endl;
    cout << endl;

    myList.insert("Slim Shady");
    myList.erase("Donald Trump");

    
    for(ListIterator<string> n = myList.begin(); n != myList.end(); ++n)
        cout <<  n << endl;
    
    cout << endl;
    

    Slist<int> aList;
    aList.insert(1);
    aList.insert(2);
    aList.insert(3);
    aList.insert(5);
    aList.insert(10);

    for(ListIterator<int> n = aList.begin(); n != aList.end(); ++n)
        cout <<  n << endl;
    
    cout << endl;
    
    aList.erase(10);
    aList.erase(5);
    aList.insert(4);
    aList.insert(5);
    aList.insert(6);
    aList.insert(7);
    aList.insert(8);
    aList.insert(9);
    
    for(ListIterator<int> n = aList.begin(); n != aList.end(); ++n)
        cout <<  n << endl;
    
    cout << endl;
    
    return 0;
}
