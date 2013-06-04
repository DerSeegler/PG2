/* 
 * File:   myVector.cpp
 * Author: Yannik
 * 
 * Created on 4. Juni 2013, 20:59
 */

#include "myVector.h"

myVector::myVector() {
}

myVector::myVector(const myVector& orig) {
}

myVector::~myVector() {
}

void myVector::reserve(int newspace) {
    if (newspace <= space) {
        return; // nie weniger Platz holen   
    }

    double* p = new double[newspace]; // mit new Speicher allokieren 
    for (int i = 0; i < sz; ++i) {
        p[i] = elem[i]; // Elemente kopieren
    }

    delete[] elem; // alten Speicher freigeben
    elem = p; // Zeiger umhaengen 
    space = newspace; // Platz korrekt setzen
}

void myVector::push_back(double d) {
    if (space == 0) { // Erstes Element
        reserve(8); // Platz aus dem Heap holen
    } else {
        if (sz == space) { // Kein Platz mehr? 
            reserve(space * 2); // Aus dem Heap holen
        }
    }

    elem[sz] = d; // Jetzt d anhaengen… 
    ++sz; // …und den Elementezaehler erhoehen
}

void myVector::resize(int newsize) {
    reserve(newsize); // Speicher im Heap reservieren 
    for (int i = sz; i < newsize; ++i) { // Initialisierung der 
        elem[i] = double(); // zusaetzlichen Elemente
    }
    
    sz = newsize;
}
