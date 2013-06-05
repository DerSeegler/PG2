/* 
 * File:   myVector.cpp
 * Author: Yannik
 * 
 * Created on 4. Juni 2013, 20:50
 */

#include "myVector.h"

myVector::myVector() : sz(0), elem(0) {
}

myVector::myVector(int s) : sz(s), elem(new double[s]) {
    for (int i = 0; i < s; ++i) {
        elem[i] = 0.0;
    }
}

myVector::~myVector() {
    delete[] elem;
    elem = 0;
}

double& myVector::operator[](int index) {
    if (index < 0 || sz <= index) throw std::runtime_error("myVector::operator[](), bad index");
    return elem[index];
}

int myVector::size() const {
    return sz;
}

double* myVector::eleme() const {
    return elem;
}

myVec::myVec() : myVector(), lb(0) {
}

myVec::myVec(int low, int high) : myVector(high - low + 1), lb(low) {
}

double& myVec::operator[](int i) {
    if (i < lb || hi() <= i) {
        throw std::runtime_error("myVector::operator[](), bad index");
    }
    
    return myVector::operator[](i - lb);
}

double& myVec::operator[](int i) const {
    if (i < lb || hi() <= i) {
        throw std::runtime_error("myVector::operator[](), bad index");
    }
    
    double d = myVector::operator[](i - lb);
    return d;
}

int myVec::lo() const {
    return lb;
}

int myVec::hi() const {
    return lb + myVector::size() - 1;
}
