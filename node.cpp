//  node.cpp
//  adv_cpp_hw_ch17

#include <iostream>
#include  <string>

#include "node.hpp"

using std::cout;
using std::endl;
using std::string;

using namespace KBCode;

namespace KBCode
{
    template<class T>
    void headInsert(Node<T>*& head, const T& theData)
    {
        head = new Node<T>(theData, head);
    }
    
    template<class T>
    void insert(Node<T>*& afterMe, const T& theData)
    {
        afterMe->setLink(new Node<T>(theData, afterMe->getLink()));
    }
    
    template<class T>
    void deleteNode(Node<T>* before)
    {
        Node<T> *discard;
        discard = before->getLink();
        before->setLink(discard->getLink());
        delete discard;
    }
    
    template<class T>
    void deleteFirstNode(Node<T>*& head)
    {
        Node<T> *discard;
        discard = head;
        head = head->getLink();
        delete discard;
    }
    
    template<class T>
    Node<T>* search(Node<T>* head, const T& target)
    {
        Node<T>* here = head;
        Node<T>* before = NULL;
        if (here == NULL)
        {
            return NULL;
        }
        else{
            if (here->getData() == target)
                return here;
            while (here->getData() != target && here->getLink() != NULL){
                before = here;
                here = here->getLink();
            }
//            cout << here->getData() << endl;
            if (here->getData() == target)
                return before;
            else
                return NULL;
        }
    }
    
    //Needed for separate implementation to work with templates
    
    template Node<string>* search(Node<string>* head, const string& target);
    template Node<float>* search(Node<float>* head, const float& target);
    template Node<int>* search(Node<int>* head, const int& target);
    template Node<char>* search(Node<char>* head, const char& target);
    
}
