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

    myVector() : sz(0), elem(0) {
    }

    explicit myVector(int s) : sz(s), elem(new double[s]) {
        for (int i = 0; i < s; ++i) elem[i] = 0.0;
    }

    ~myVector() {
        delete[] elem;
        elem = 0;
    }
    
    int size() const {
        return sz;
    }
    
    double* eleme() const {
        return elem;
    }
    
    double& operator[](int);
};

double& myVector::operator[](int index) {
    if (index < 0 || sz <= index) throw std::runtime_error("myVector::operator[](), bad index");
    return elem[index];
};

class myVec : public myVector {
public:

    myVec() : myVector(), lb(0) {
    }

    myVec(int low, int high) : myVector(high - low + 1), lb(low) {
    }

    double& operator[](int i) {
        return myVector::operator[](i - lb);
    }

    int lo() const {
        return lb;
    }

    int hi() const {
        return lb + size() - 1;
    }
private:
    int lb;
};

double& myVec::operator[](int index) {
    if (index < lb || hi() <= index) throw std::runtime_error("myVector::operator[](), bad index");
    return eleme()[index];
};

#endif	/* MYVECTOR_H */

