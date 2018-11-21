 //  node.hpp
//  adv_cpp_hw_ch17

#ifndef node_hpp
#define node_hpp

#include <cstddef>
#include <iostream>

using std::ostream;
using std::endl;

namespace KBCode
{
    template<class T>
    class Node
    {
    public:
        Node() : data(), link(NULL){}
        Node(const T& theData, Node<T>* theLink) : data(theData), link(theLink){}
        Node<T>* getLink() const { return link; }
        const T getData() const { return data; }
        void setData(const T& theData) { data = theData; }
        void setLink(Node<T>* pointer) { link = pointer; }
        
        friend std::ostream& operator << (std::ostream& output, const Node<T>& obj)
        {
            Node<T>* temp = obj;
            output << temp->getData();
            return output;
        }
        
    private:
        T data;
        Node<T>* link;
    };
    
    template<class T>
    void headInsert(Node<T>*& head, const T& theData);
    
    template<class T>
    void insert(Node<T>* afterMe, const T& theData);
    
    template<class T>
    void deleteNode(Node<T>* before);
    
    template<class T>
    void deleteFirstNode(Node<T>*& head);
    
    template<class T>
    Node<T>* search(Node<T>* head, const T& target);
    
}


#endif /* node_hpp */
