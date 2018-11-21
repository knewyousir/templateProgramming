//  slist.cpp
//  adv_cpp_hw_ch17

#include <string>
#include <iostream>

#include "slist2.hpp"

using std::string;
using std::cout;
using std::endl;
using namespace KBCode;

namespace KBCode
{
    
    template<class T>
    Slist<T>::Slist() : front(NULL)
    {
        // Empty
    }
    
    template<class T>
    Slist<T>::Slist(const Slist<T>& aSlist) : Slist()
    {
        Node<T>* temp_ptr;
        temp_ptr = new Node<T>();
        temp_ptr->data = aSlist->data;
        if (aSlist->link == NULL)
            return temp_ptr;
        for (ListIterator<T> n = aSlist.begin(); n != aSlist.end(); ++n)
            temp_ptr->insert(temp_ptr, n->data);
        front = temp_ptr;
    }
    
    template<class T>
    Slist<T>& Slist<T>::operator =(const Slist<T>& rhs)
    {
        Slist<T> temp(rhs);
        this->front = temp->front;
        return *this;
    }
    
    template<class T>
    Slist<T>::~Slist()
    {
        Node<T>* tmp_ptr = front;
        while (tmp_ptr->getLink() != NULL){
            Node<T>* next = tmp_ptr->getLink();
            delete tmp_ptr;
            tmp_ptr = next;
        }
        front = NULL;
    }
    
    template<class T>
    void Slist<T>::insert(T item)
    {
        if (front == NULL){
            front = new Node<T>(item, NULL);
            cout << "Value " << item << " inserted at start of list.\n";
            return;
        }
        Node<T>* temp;
        if (front->getLink() == NULL){
            temp = new Node<T>(item, NULL);
            front->setLink(temp);
            cout << "Value " << item << " inserted at end of list.\n";
            return;
        }
        Node<T>* current = front;
        while (current->getLink() != NULL)
            current = current->getLink();
        temp = new Node<T>(item, NULL);
        current->setLink(temp);
        cout << "Value " << item << " inserted at end of list.\n";
        return;
    }
    
    template<class T>
    void Slist<T>::insert(T item, int element)
    {
        Node<T>* current;
        Node<T>* previous;
        Node<T>* temp;
        
        current = front;
        
        if (current == NULL){
            cout << "List empty" << endl;
            return;
        }
        
        if (element == 0){
            temp = new Node<T>(item, front);
            front = temp;
            cout << "Value " << item << " inserted after element " << element << ".\n";
            return;
        }
        
        // Cycle through to desired element
        for (int count(0); count < (element - 1); count++){
            previous = current;
            current = current->getLink();
            if (current == NULL){
                cout << "Error! Element out of range!\n";
                return;
            }
        }
        //Add item after desired element
        temp = new Node<T>(item, current->getLink() );
        previous = current;
        previous->setLink(temp);
        cout << "Value " << item << " inserted after element " << element << ".\n";
        return;
        
    }
    
    template<class T>
    void Slist<T>::erase(T target)
    {
        Node<T>* current;
        Node<T>* toDelete;
        Node<T>* previous;
        Node<T>* temp;
        
        current = front;
        
        if (current == NULL){
            cout << "List empty" << endl;
            return;
        }
        
        if (current->getData() == target){
            temp = current;
            front = current->getLink();
            delete temp;
            cout << "Value " << target << " removed.\n";
            return;
        }
        
        previous = search(current, target);
        if (previous == NULL){
            cout << "Target Not found!" << endl;
            return;
        } else{
            toDelete = previous->getLink();
            temp = toDelete->getLink();
            previous->setLink(temp);
            delete toDelete;
            cout << "Value " << target << " removed.\n";
            return;
        }
    }

    template<class T>
    void Slist<T>::remove(int element)
    {
        Node<T>* current;
        Node<T>* toDelete;
        Node<T>* previous(NULL);
        
        current = front;
        
        if (current == NULL){
            cout << "List empty\n";
            return;
        }
        
        if (element == 1){
            toDelete = front;
            front = front->getLink();
            delete toDelete;
            cout << "Element " << element << " removed.\n";
            return;
        }
        
        // Cycle through to desired element
        for (int count(0); count < (element - 1); count++){
            if (current == NULL){
                cout << "Error! Element out of range!\n";
                return;
            }
            previous = current;
            current = current->getLink();
        }
        //Delete element
        toDelete = current;
        previous->setLink(current->getLink());
        delete toDelete;
        cout << "Element " << element << " removed.\n";
        return;
    }
    
    //These are needed to allow separate implementation to work for templates
    
    template Slist<string>::Slist();
    template Slist<float>::Slist();
    template Slist<int>::Slist();
    template Slist<char>::Slist();
    
    template Slist<string>::~Slist();
    template Slist<float>::~Slist();
    template Slist<int>::~Slist();
    template Slist<char>::~Slist();
    
    template void Slist<string>::insert(string item);
    template void Slist<float>::insert(float item);
    template void Slist<int>::insert(int item);
    template void Slist<char>::insert(char item);
    
    template void Slist<string>::insert(string item, int element);
    template void Slist<float>::insert(float item, int element);
    template void Slist<int>::insert(int item, int element);
    template void Slist<char>::insert(char item, int element);
    
    template void Slist<string>::erase(string item);
    template void Slist<float>::erase(float item);
    template void Slist<int>::erase(int item);
    template void Slist<char>::erase(char item);
    
    template void Slist<string>::remove(int element);
    template void Slist<float>::remove(int element);
    template void Slist<int>::remove(int element);
    template void Slist<char>::remove(int element);
    
}
