//  slist.hpp
//  adv_cpp_hw_ch17

#ifndef slist_hpp
#define slist_hpp

#include "listiterator.hpp"

namespace KBCode
{
    template<class T>
    class Slist
    {
    public:
        Slist();
        Slist(const Slist<T>& aSlist);
        Slist<T>& operator =(const Slist<T>& rhs);
        virtual ~Slist();

        void insert(T item);
        void insert(T item, int element); //overload of existing insert
        void erase(T target);
        void remove(int element);
        
        Node<T>* start() const {return front; }
        
        ListIterator<T> begin() const {return ListIterator<T>(front); }
        ListIterator<T> end() const {return ListIterator<T>(); }

    private:
        Node<T>* front;
    };
    
//    #include "slist2.cpp"

}

#endif /* slist_hpp */
