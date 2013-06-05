/* 
 * File:   myVector.cpp
 * Author: Yannik
 * 
 * Created on 4. Juni 2013, 20:59
 */

#include <stdexcept>

#include "myVector.h"

template<class T> myVector<T>::myVector() : sz(0), space(0), elem(0) {
}

template<class T> myVector<T>::myVector(int s, T val = T()) : sz(s), space(s), elem(new T[s]) {
    for (int i = 0; i < sz; ++i) { // Initialisierung der 
        elem[i] = val; // zusaetzlichen Elemente
    }
}

template<class T> myVector<T>::myVector(const myVector& a) {  
    T* p = new T[a.sz]; // copy & swap, Platz aus dem Heap holen 
    for (int i = 0; i < a.sz; ++i) {
        p[i] = a.elem[i]; // Elemente kopieren
    }
    
    elem = p; // Zeiger umhaengen 
    space = sz = a.sz; // Groesse richtig setzen 
}

template<class T> myVector<T>::~myVector() {
    delete[] elem;
    elem = 0;
}

template<class T> void myVector<T>::reserve(int newspace) {
    if (newspace <= space) {
        return; // nie weniger Platz holen   
    }

    T* p = new T[newspace]; // mit new Speicher allokieren 
    for (int i = 0; i < sz; ++i) {
        p[i] = elem[i]; // Elemente kopieren
    }

    delete[] elem; // alten Speicher freigeben
    elem = p; // Zeiger umhaengen 
    space = newspace; // Platz korrekt setzen
}

template<class T> void myVector<T>::push_back(const T& val) {
    if (space == 0) { // Erstes Element
        reserve(8); // Platz aus dem Heap holen
    } else {
        if (sz == space) { // Kein Platz mehr? 
            reserve(space * 2); // Aus dem Heap holen
        }
    }

    elem[sz] = val; // Jetzt d anhaengen… 
    ++sz; // …und den Elementezaehler erhoehen
}

template<class T> void myVector<T>::resize(int newsize, T val = T()) {
    reserve(newsize); // Speicher im Heap reservieren 
    for (int i = sz; i < newsize; ++i) { // Initialisierung der 
        elem[i] = val; // zusaetzlichen Elemente
    }

    sz = newsize;
}

template<class T> int myVector<T>::size() const {
    return sz;
}

template<class T> int myVector<T>::capacity() const {
    return space;
}

template<class T> T myVector<T>::get(int i) const {
    return elem[i];
}

template<class T> void myVector<T>::set(int i, T val) {
    elem[i] = val;
}

template<class T> T& myVector<T>::operator[](int n) {
    if (0 > n || sz <= n) {
        throw std::runtime_error("myVector::operator[](), bad index");
    }

    return elem[n];
}

template<class T> T& myVector<T>::operator[](int n) const {
    if (0 > n || sz <= n) {
        throw std::runtime_error("myVector::operator[](), bad index");
    }

    return elem[n];
}

template<class T> myVector<T>& myVector<T>::operator=(const myVector& a) {
    if (this == &a) {
        return *this;
    }
    
    if (a.sz <= space) { // genug Platz, d.h. keine weitere Allokation 
        for (int i = 0; i < a.sz; ++i) {
            elem[i] = a.elem[i]; // Elemente kopieren 
        }
        // Bem.: die beiden myVector Objekte sind 
        // bzgl. space nicht mehr unbedingt identisch 
        
        sz = a.sz;
        return *this;
    }
    
    T* p = new T[a.sz]; // copy & swap, Platz aus dem Heap holen 
    for (int i = 0; i < a.sz; ++i) {
        p[i] = a.elem[i]; // Elemente kopieren
    }
    
    delete[] elem; // alten Speicherplatz feigeben
    elem = p; // Zeiger umhaengen 
    space = sz = a.sz; // Groesse richtig setzen 
    return *this; // die (eigene) Adresse zurueckgeben 
}

template<class T> myVec<T>::myVec() : myVector<T>(), lb(0) {
}

template<class T> myVec<T>::myVec(int low, int high) : myVector<T>(high - low + 1, T()), lb(low) {
}

template<class T> T& myVec<T>::operator[](int i) {
        if (i < lb || hi() <= i) {
            throw std::runtime_error("myVector::operator[](), bad index");
        }
        
        return myVector<T>::operator[](i - lb);
}

template<class T> T& myVec<T>::operator[](int i) const {
        if (i < lb || hi() <= i) {
            throw std::runtime_error("myVector::operator[](), bad index");
        }
        
        T d = myVector<T>::operator[](i - lb);
        return d;
}

template<class T> int myVec<T>::lo() const {
    return lb;
}

template<class T> int myVec<T>::hi() const {
    return lb + myVector<T>::size() - 1;
}
