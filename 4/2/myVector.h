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
    explicit myVector(int, T); // ein Konstruktor
    myVector(const myVector&); // Copy-Konstruktor
    myVector<T>& operator=(const myVector&); // Zuweisungsoperator 
    ~myVector(); // Destruktor
    T& operator[](int); // Indexoperator 
    T& operator[](int) const;
    T get(int) const; // read
    void set(int, T); // write
    void reserve(int);
    void push_back(const T&);
    void resize(int, T);
    int size() const;// Anzahl Elemente 
    int capacity() const;
};

template<class T> class myVec : public myVector<T> {
public:
    myVec();
    myVec(int, int);
    T& operator[](int i);
    T& operator[](int i) const;
    int lo() const;
    int hi() const;
private:
    int lb;
};

#endif	/* MYVECTOR_H */

