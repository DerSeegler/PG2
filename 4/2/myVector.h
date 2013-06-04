/* 
 * File:   myVector.h
 * Author: Yannik
 *
 * Created on 4. Juni 2013, 20:59
 */

#ifndef MYVECTOR_H
#define	MYVECTOR_H

class myVector {
    int sz; // size
    int space; // size + weiterer Platz 
    double* elem; // Zeiger auf die Elemente
public:
    myVector(); // Standardkonstruktor 
    explicit myVector(int); // ein Konstruktor
    myVector(const myVector&); // Copy-Konstruktor
    myVector& operator=(const myVector&); // Zuweisungsoperator 
    ~myVector(); // Destruktor
    double& operator[](int); // Indexoperator 
    int size() const; // Anzahl Elemente 
    double get(int) const; // read
    void set(int, double); // write
    void reserve(int);
    void push_back(double);
    void resize(int);

    int capacity() const {
        return space;
    }
};

#endif	/* MYVECTOR_H */

