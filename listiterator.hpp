//  listiterator.hpp
//  adv_cpp_hw_ch17


#ifndef listiterator_hpp
#define listiterator_hpp

#include <iostream>


#include "node.hpp"

using std::ostream;
using std::endl;

using namespace KBCode;

namespace KBCode
{
    template<class T>
    class ListIterator
    {
    public:
        ListIterator() : current(NULL) {}
        
        ListIterator(Node<T>* initial) : current(initial) {}
        
        const T operator *() const { return current->getData(); }
        
        ListIterator operator++()
        {
            current = current->getLink();
            return *this;
        }
        
        ListIterator operator++(int)
        {
            ListIterator startVersion(current);
            current = current->getLink();
            return startVersion;
        }
        
        bool operator ==(const ListIterator& rightSide) const
        { return (current == rightSide.current); }
        
        bool operator !=(const ListIterator& rhs) const
        { return (current != rhs.current); }
        
        friend std::ostream& operator << (std::ostream& output, const ListIterator& obj)
        {
            Node<T>* temp = obj.current;
            output << temp->getData();
            return output;
        }
        
    private:
        Node<T>* current;
    };
    
}





#endif /* listiterator_hpp */
