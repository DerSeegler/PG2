

using namespace std;

#include "myList.h"
#include <iostream>




template<class Elem> myList<Elem>::myIterator::myIterator()
: curr(0) {
}

template<class Elem> myList<Elem>::myIterator::myIterator(myNode<Elem>* p)
: curr(p) {
}

template<class Elem>
myNode<Elem>* myList<Elem>::myIterator::_curr() const {
    return curr;
}

template<class Elem>
bool myList<Elem>::myIterator::operator==
(const myIterator& other) const {
    return curr == other.curr;
}

template<class Elem>
bool myList<Elem>::myIterator::operator!=
(const myIterator& other) const {
    return curr == other.curr;
}

template<class Elem>
typename myList<Elem>::myIterator myList<Elem>::begin() {
    return myIterator(first);
}

template<class Elem>
typename myList<Elem>::myIterator myList<Elem>::end() {
    return myIterator(last);
}

// Definition des Konstruktors:
template<class Elem> myNode<Elem>::myNode(const Elem& v, myNode<Elem>* p, myNode<Elem>* s)
{
    val = v;
    pre = p;
    suc = s;
}

template<class Elem> myList<Elem>::myList() : first(0), last(0) {
    last = new myNode<Elem>;
    first = last;
    last->suc = 0;
    last->pre = 0;
}

template<class Elem> myList<Elem>::~myList() {
    myNode<Elem>* dp = first;
    while (dp != last) {
        myNode<Elem>* tmp = dp->suc;
        delete dp;
        dp = tmp;
    }
    delete last;
}
// usw. für die uebrigen Standardoperationen 

template<class Elem> void myList<Elem>::push_back(const Elem& v) {
    myNode<Elem>* nn = new myNode<Elem>;
    nn->val = v;
    if (first == last) { // erster Knoten wird eingefuegt
        first = nn;
        last->pre = first;
        first->suc = last;
    } else {
        nn->suc = last;
        nn->pre = last->pre;
        last->pre->suc = nn;
        last->pre = nn;
    }
}

template<class Elem> void myList<Elem>::pop_back() {
    if (first == last) return; // Liste leer
    myNode<Elem>* tmp = last->pre;
    if (tmp == first) {
        last->pre = 0;
        first = last;
    }// letzter Knoten wird geloescht 
    else {
        last->pre = last->pre->pre;
        last->pre->suc = last;
    }
    delete tmp;
}
// usw.

// Konstruktoren: 

