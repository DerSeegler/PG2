/* 
 * File:   Classes.h
 * Author: Yannik
 *
 * Created on 10. April 2013, 10:26
 */

#ifndef CLASSES_H
#define	CLASSES_H

#include <vector>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using std::runtime_error;

class NPV {
public:
    NPV();
    NPV( double, double);
    NPV( double, double, double, double);
    double calc( int );
private:
    std::vector<long int> inv;
    double irate;
};

#endif	/* CLASSES_H */

