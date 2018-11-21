//  main.cpp
//  adv_cpp_final

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
    char ans;
    int num;
    
    do{
        cout << "Would you like to make a list of type\n"
        << "string(s), float(f), int(i), or char(c)?\n";
        cin >> ans; cout << endl;
        
        cout << "How many members would like to have in\n"
        << "your list?:\n";
        cin >> num; cout << endl;
        
        
        if (ans == 's'){
            Slist<string>* stringList;
            Node<string>* stringNode_ptr;
            string tempString;
            int tempInt;
            stringList = new Slist<string>;
            
            //Populating the list
            cout << "Please enter " << num << " items:\n";
            for (int count(0); count < num; count++){
                cin >> tempString;
                stringList->insert(tempString);
            }
            cout << "Thank you. The list you entered is:\n";
            for(ListIterator<string> n = stringList->begin(); n != stringList->end(); ++n)
                cout <<  n << " ";
            cout << endl;
            
            // Edit the list
            do{
                //Remove particular elements from the list
                cout << "Would you like to remove an item from the list(y/n)?: ";
                cin >> ans;
                
                if ( ans == 'y'){
                    cout << "Would you like to remove an item by element number(e), or by value(v), or (n) to exit?\n";
                    cin >> ans;
                    
                    if ( ans == 'e'){ //Remove by element number
                        cout << "Which element would you like to remove?: ";
                        cin >> tempInt;
                        stringList->remove(tempInt);
                    } else if ( ans == 'v'){ //Remove by searching for first instance of value
                        cout << "What value would you like to remove?\n";
                        cin >> tempString;
                        stringList->erase(tempString);
                    } else if ( ans == 'n'){
                        // Empty
                    }
                    if (ans != 'n'){
                        cout << "The new list is:\n";
                        for(ListIterator<string> n = stringList->begin(); n != stringList->end(); ++n)
                            cout << n << " ";
                        cout << endl;
                    }
                } else if (ans == 'n'){
                    // Empty
                }
                
                // Search for a user defined input
                cout << "Would you like to search for a particular value(y/n)?: ";
                cin >> ans;
                if ( ans == 'y'){
                    //Search for a value and inform if it is found
                    cout << "Which value would you like to search for?\n";
                    cin >> tempString;
                    stringNode_ptr = stringList->start();
                    if (search(stringNode_ptr, tempString) == NULL){
                        cout << "No such data exists. Try again.\n";
                    } else {
                        cout << "Data item " << tempString << " found!\n";
                    }
                } else if (ans == 'n'){
                    //Empty
                }
                
                // Insert a new node a location X and provide input
                cout << "Would you like to insert a new node into the list(y/n)?: ";
                cin >> ans;
                if ( ans == 'y'){
                    cout << "After which element number would you like to insert the data?: ";
                    cin >> tempInt;
                    cout << "What value would you like to insert?: ";
                    cin >> tempString;
                    stringList->insert(tempString, tempInt);
                } else if (ans == 'n'){
                    // Empty
                }
                if (ans != 'n'){
                    cout << "The new list is:\n";
                    for(ListIterator<string> n = stringList->begin(); n != stringList->end(); ++n)
                        cout << n << " ";
                    cout << endl;
                }
                
                do{
                    cout << "Would you like to make any more changes to the list(y/n)?: ";
                    cin >> ans;
                    if ( ans == 'y' || ans == 'n')
                        break;
                } while (1);
            } while (ans != 'n');
            
            cout << "The final list is:\n";
            for(ListIterator<string> n = stringList->begin(); n != stringList->end(); ++n)
                cout << n << " ";
            cout << endl;
        } else if (ans == 'f'){
            Slist<float>* floatList;
            Node<float>* floatNode_ptr;
            float tempFloat;
            int tempInt;
            floatList = new Slist<float>;
            
            //Populating the list
            cout << "Please enter " << num << " items:\n";
            for (int count(0); count < num; count++){
                cin >> tempFloat;
                floatList->insert(tempFloat);
            }
            cout << "Thank you. The list you entered is:\n";
            for(ListIterator<float> n = floatList->begin(); n != floatList->end(); ++n)
                cout <<  n << " ";
            cout << endl;
            
            // Edit the list
            do{
                //Remove particular elements from the list
                cout << "Would you like to remove an item from the list(y/n)?: ";
                cin >> ans;
                
                if ( ans == 'y'){
                    cout << "Would you like to remove an item by element number(e), or by value(v), or (n) to exit?\n";
                    cin >> ans;
                    
                    if ( ans == 'e'){ //Remove by element number
                        cout << "Which element would you like to remove?: ";
                        cin >> tempInt;
                        floatList->remove(tempInt);
                    } else if ( ans == 'v'){ //Remove by searching for first instance of value
                        cout << "What value would you like to remove?\n";
                        cin >> tempFloat;
                        floatList->erase(tempFloat);
                    } else if ( ans == 'n'){
                        // Empty
                    }
                    if (ans != 'n'){
                        cout << "The new list is:\n";
                        for(ListIterator<float> n = floatList->begin(); n != floatList->end(); ++n)
                            cout << n << " ";
                        cout << endl;
                    }
                } else if (ans == 'n'){
                    // Empty
                }
                
                // Search for a user defined input
                cout << "Would you like to search for a particular value(y/n)?: ";
                cin >> ans;
                if ( ans == 'y'){
                    //Search for a value and inform if it is found
                    cout << "Which value would you like to search for?\n";
                    cin >> tempFloat;
                    floatNode_ptr = floatList->start();
                    if (search(floatNode_ptr, tempFloat) == NULL){
                        cout << "No such data exists. Try again.\n";
                    } else {
                        cout << "Data item " << tempFloat << " found!\n";
                    }
                } else if (ans == 'n'){
                    //Empty
                }
                
                // Insert a new node a location X and provide input
                cout << "Would you like to insert a new node into the list(y/n)?: ";
                cin >> ans;
                if ( ans == 'y'){
                    cout << "After which element number would you like to insert the data?: ";
                    cin >> tempInt;
                    cout << "What value would you like to insert?: ";
                    cin >> tempFloat;
                    floatList->insert(tempFloat, tempInt);
                } else if (ans == 'n'){
                    // Empty
                }
                if (ans != 'n'){
                    cout << "The new list is:\n";
                    for(ListIterator<float> n = floatList->begin(); n != floatList->end(); ++n)
                        cout << n << " ";
                    cout << endl;
                }
                
                do{
                    cout << "Would you like to make any more changes to the list(y/n)?: ";
                    cin >> ans;
                    if ( ans == 'y' || ans == 'n')
                        break;
                } while (1);
            } while (ans != 'n');
            
            cout << "The final list is:\n";
            for(ListIterator<float> n = floatList->begin(); n != floatList->end(); ++n)
                cout << n << " ";
            cout << endl;
        } else if (ans == 'i'){
            Slist<int>* intList;
            Node<int>* intNode_ptr;
            int tempInt, tempInt2;
            intList = new Slist<int>;
            
            //Populating the list
            cout << "Please enter " << num << " items:\n";
            for (int count(0); count < num; count++){
                cin >> tempInt;
                intList->insert(tempInt);
            }
            cout << "Thank you. The list you entered is:\n";
            for(ListIterator<int> n = intList->begin(); n != intList->end(); ++n)
                cout <<  n << " ";
            cout << endl;
            
            // Edit the list
            do{
                //Remove particular elements from the list
                cout << "Would you like to remove an item from the list(y/n)?: ";
                cin >> ans;
                
                if ( ans == 'y'){
                    cout << "Would you like to remove an item by element number(e), or by value(v), or (n) to exit?\n";
                    cin >> ans;
                    
                    if ( ans == 'e'){ //Remove by element number
                        cout << "Which element would you like to remove?: ";
                        cin >> tempInt;
                        intList->remove(tempInt);
                    } else if ( ans == 'v'){ //Remove by searching for first instance of value
                        cout << "What value would you like to remove?\n";
                        cin >> tempInt;
                        intList->erase(tempInt);
                    } else if ( ans == 'n'){
                        // Empty
                    }
                    if (ans != 'n'){
                        cout << "The new list is:\n";
                        for(ListIterator<int> n = intList->begin(); n != intList->end(); ++n)
                            cout << n << " ";
                        cout << endl;
                    }
                } else if (ans == 'n'){
                    // Empty
                }
                
                // Search for a user defined input
                cout << "Would you like to search for a particular value(y/n)?: ";
                cin >> ans;
                if ( ans == 'y'){
                    //Search for a value and inform if it is found
                    cout << "Which value would you like to search for?\n";
                    cin >> tempInt;
                    intNode_ptr = intList->start();
                    if (search(intNode_ptr, tempInt) == NULL){
                        cout << "No such data exists. Try again.\n";
                    } else {
                        cout << "Data item " << tempInt << " found!\n";
                    }
                } else if (ans == 'n'){
                    //Empty
                }
                
                // Insert a new node a location X and provide input
                cout << "Would you like to insert a new node into the list(y/n)?: ";
                cin >> ans;
                if ( ans == 'y'){
                    cout << "After which element number would you like to insert the data?: ";
                    cin >> tempInt;
                    cout << "What value would you like to insert?: ";
                    cin >> tempInt2;
                    intList->insert(tempInt2, tempInt);
                } else if (ans == 'n'){
                    // Empty
                }
                if (ans != 'n'){
                    cout << "The new list is:\n";
                    for(ListIterator<int> n = intList->begin(); n != intList->end(); ++n)
                        cout << n << " ";
                    cout << endl;
                }
                
                do{
                    cout << "Would you like to make any more changes to the list(y/n)?: ";
                    cin >> ans;
                    if ( ans == 'y' || ans == 'n')
                        break;
                } while (1);
            } while (ans != 'n');
            
            cout << "The final list is:\n";
            for(ListIterator<int> n = intList->begin(); n != intList->end(); ++n)
                cout << n << " ";
            cout << endl;
        } else if (ans == 'c'){
            Slist<char>* charList;
            Node<char>* charNode_ptr;
            char tempChar;
            int tempInt;
            charList = new Slist<char>;
            
            //Populating the list
            cout << "Please enter " << num << " items:\n";
            for (int count(0); count < num; count++){
                cin >> tempChar;
                charList->insert(tempChar);
            }
            cout << "Thank you. The list you entered is:\n";
            for(ListIterator<char> n = charList->begin(); n != charList->end(); ++n)
                cout <<  n << " ";
            cout << endl;
            
            // Edit the list
            do{
                //Remove particular elements from the list
                cout << "Would you like to remove an item from the list(y/n)?: ";
                cin >> ans;
                
                if ( ans == 'y'){
                    cout << "Would you like to remove an item by element number(e), or by value(v), or (n) to exit?\n";
                    cin >> ans;
                    
                    if ( ans == 'e'){ //Remove by element number
                        cout << "Which element would you like to remove?: ";
                        cin >> tempInt;
                        charList->remove(tempInt);
                    } else if ( ans == 'v'){ //Remove by searching for first instance of value
                        cout << "What value would you like to remove?\n";
                        cin >> tempChar;
                        charList->erase(tempChar);
                    } else if ( ans == 'n'){
                        // Empty
                    }
                    if (ans != 'n'){
                        cout << "The new list is:\n";
                        for(ListIterator<char> n = charList->begin(); n != charList->end(); ++n)
                            cout << n << " ";
                        cout << endl;
                    }
                } else if (ans == 'n'){
                    // Empty
                }
                
                // Search for a user defined input
                cout << "Would you like to search for a particular value(y/n)?: ";
                cin >> ans;
                if ( ans == 'y'){
                    //Search for a value and inform if it is found
                    cout << "Which value would you like to search for?\n";
                    cin >> tempChar;
                    charNode_ptr = charList->start();
                    if (search(charNode_ptr, tempChar) == NULL){
                        cout << "No such data exists. Try again.\n";
                    } else {
                        cout << "Data item " << tempChar << " found!\n";
                    }
                } else if (ans == 'n'){
                    //Empty
                }
                
                // Insert a new node a location X and provide input
                cout << "Would you like to insert a new node into the list(y/n)?: ";
                cin >> ans;
                if ( ans == 'y'){
                    cout << "After which element number would you like to insert the data?: ";
                    cin >> tempInt;
                    cout << "What value would you like to insert?: ";
                    cin >> tempChar;
                    charList->insert(tempChar, tempInt);
                } else if (ans == 'n'){
                    // Empty
                }
                if (ans != 'n'){
                    cout << "The new list is:\n";
                    for(ListIterator<char> n = charList->begin(); n != charList->end(); ++n)
                        cout << n << " ";
                    cout << endl;
                }
                
                do{
                    cout << "Would you like to make any more changes to the list(y/n)?: ";
                    cin >> ans;
                    if ( ans == 'y' || ans == 'n')
                        break;
                } while (1);
            } while (ans != 'n');
            
            cout << "The final list is:\n";
            for(ListIterator<char> n = charList->begin(); n != charList->end(); ++n)
                cout << n << " ";
            cout << endl;
        }
        
        cout << "Would you like to try again? (y/n): ";
        cin >> ans;
        
    } while (ans == 'y');
 
    cout << "Thanks for using the program! Have a great day!\n";
    
    return 0;
}
