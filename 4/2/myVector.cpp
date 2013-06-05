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

template<class T> myVector<T>::myVector(int s) : sz(s), space(s), elem(new T[s]) {
}

template<class T> myVector<T>::~myVector() {
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

template<class T> T& myVector<T>::operator[]( int n) {
    if( 0>n || sz<=n ) {
        throw std::runtime_error( "myVector::operator[](), bad index" );
    }
    
    return elem[n]; 
}
