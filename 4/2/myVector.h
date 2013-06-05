/* 
 * File:   myVector.h
 * Author: Yannik
 *
 * Created on 4. Juni 2013, 20:59
 */

#ifndef MYVECTOR_H
#define	MYVECTOR_H

template<class T> class myVector {
    int sz; // size
    int space; // size + weiterer Platz 
    T* elem; // Zeiger auf die Elemente
public:
    myVector(); // Standardkonstruktor 
    explicit myVector(int); // ein Konstruktor
    myVector(const myVector&); // Copy-Konstruktor
    myVector& operator=(const myVector&); // Zuweisungsoperator 
    ~myVector(); // Destruktor
    T& operator[](int); // Indexoperator 
//    int size() const; // Anzahl Elemente 
    //double get(int) const; // read
    void set(int, double); // write
    void reserve(int);
    void push_back(const T&);
    void resize(int, T);

    int capacity() const {
        return space;
    }
};

#endif	/* MYVECTOR_H */

