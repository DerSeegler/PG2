/* 
 * File:   main.cpp
 * Author: Yannik
 *
 * Created on 23. April 2013, 21:32
 */

#include <iostream>
#include <stdexcept>
#include "Frame.h"

using namespace std;

int main( ) {
    try {
        Frame f = Frame();
        Triangle t = Triangle(1,1,20,10,15);
        t.draw( &f );
        cout << &f;
        return 0;
    }
    catch (std::exception &e) {
        cerr << e.what() << endl;
        return -2;
    } catch (...) {
        cerr << "Unbekannter Fehler" << endl;
        return -1;
    }
}
