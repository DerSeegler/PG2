/* 
 * File:   myList.h
 * Author: Niggl
 * myList Header-Datei
 * Created on 17. Juni 2013, 17:44
 */

#ifndef MYLIST_H
#define	MYLIST_H

//Struct myNode:
template<class Elem> struct myNode { // "fuer alle Typen Elem"
    Elem val; // der Wert vom Typ Elem
    myNode<Elem>* pre; // Zeiger auf vorhergehenden Knoten (predecessor)
    myNode<Elem>* suc; // Zeiger auf nachfolgenden Knoten (successor)
    explicit myNode (const Elem&, myNode<Elem>*, myNode<Elem>*);// Konstruktor
};

//Klasse myList:
template<class Elem> class myList {
    // die beiden Zeiger:
    myNode<Elem>* first; // zeigt auf den ersten Knoten 
    myNode<Elem>* last; // zeigt eins hinter den letzten Knoten

public:
    myList();
    ~myList();
    void push_back(const Elem&); // fuege als letzen Knoten ein
    void pop_back(); // loesche den letzten Knoten
    void push_front(const Elem&); // fuege als ersten Knoten ein
    void pop_front(); // loesche den ersten Knoten
    //… 
    class myIterator; // Membertyp namens myIterator, Klasse in einer Klasse
    myIterator begin(); // erstes Element
    myIterator end(); // eins hinter letztem Element
    myIterator find(myIterator, myIterator, const Elem&); // finden
    myIterator insert(myIterator, const Elem&); // einfuegen
    myIterator erase(myIterator); // entfernen
    //....
};

//Klasse myIterator für myList:
template<class Elem> class myList<Elem>::myIterator {
    myNode<Elem>* curr; // der aktuelle Knoten
public:
    myIterator();
    explicit myIterator(myNode<Elem>*);
    myIterator& operator++();
    myIterator& operator--();
    Elem& operator*();
    bool operator==(const myIterator&) const;
    bool operator!=(const myIterator&) const;
    myNode<Elem>* _curr() const;
};

#endif	/* MYLIST_H */

