/* 
 * File:   myVector.h
 * Author: Yannik
 *
 * Created on 4. Juni 2013, 20:50
 */

#ifndef MYVECTOR_H
#define	MYVECTOR_H
#include <stdexcept>

class myVector {
    int sz;
    double* elem;
public:
    myVector();
    explicit myVector(int s);
    ~myVector();
    int size() const;
    double* eleme() const;
    double& operator[](int);
};

class myVec : public myVector {
public:
    myVec();
    myVec(int, int);
    double& operator[](int i);
    double& operator[](int i) const;
    int lo() const;
    int hi() const;
private:
    int lb;
};

#endif	/* MYVECTOR_H */

