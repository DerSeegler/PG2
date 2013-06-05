/* 
 * File:   main.cpp
 * Author: Yannik
 *
 * Created on 4. Juni 2013, 20:49
 */

#include <iostream>
#include "myVector.h"

using namespace std;

void tf(const myVec& rcmv, myVec& rmv) {
    //rcmv[1] = 4.2; // Fehler, wie es auch sein soll 
    double d1 = rcmv[1]; // die const-Version [] 
    rmv[1] = 0.7; // die nicht-const-Version [] 
    double d2 = rmv[1]; // die nicht-const-Version [] 
    cout << d1 << " " << d2 << endl;
}

int main() {
    try {
        myVec mV = myVec(5, 10);
        mV[5] = 5.1;
        mV[6] = 7.1;
        cout << mV[5] << " " << mV[6] << endl;
        
        myVec tf1 = myVec(1, 3);
        myVec tf2 = myVec(1, 3);
        tf(tf1, tf2);
        return 0;
    }
    catch (std::exception &e) {
        cerr << e.what() << endl;
        return -2;
    }
    catch (...) {
        cerr << "Unbekannter Fehler" << endl;
        return -1;
    }
}

