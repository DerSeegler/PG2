/* 
 * File:   Classes.cpp
 * Author: Yannik
 * 
 * Created on 10. April 2013, 10:26
 */

#include "Classes.h"

NPV::NPV() : irate(0) { }

NPV::NPV( double capital, double interest_rate ) {
    if (capital < 0 || interest_rate < 0) {
        throw runtime_error( "Startkapital und Zinssatz koennen nicht negativ sein");
    }
    
    double t;
    t=interest_rate-floor(interest_rate);
    if (t>=0.5) {
        interest_rate *= 10000.0;
        interest_rate = ceil(interest_rate);
        interest_rate /= 10000.0;
    }
    else {
        interest_rate *= 10000.0;
        interest_rate = floor(interest_rate);
        interest_rate /= 10000.0;
    }
    
    irate = interest_rate;
    
    t=capital-floor(capital);
    if (t>=0.5) {
        capital *= 1000.0;
        capital = ceil(capital);
    }
    else {
        capital *= 1000.0;
        capital = floor(capital);
    }
    
    long int cap = static_cast<long int>(capital);
    
    if (inv.size() > 0) {
        inv.clear();
        inv.push_back(cap);                                                    // Verwendung von inv.clear() ?
    }
    else {
        inv.push_back(cap);
    }
}

NPV::NPV( double irateMin, double irateMax, double capMin, double capMax) {
    if (irateMin >= 0 && irateMax >= 0 && irateMin < irateMax) {
        double t;
        t=irateMin-floor(irateMin);
        if (t>=0.5) {
            irateMin *= 10000.0;
            irateMin = ceil(irateMin);
        }
        else {
            irateMin *= 10000.0;
            irateMin = floor(irateMin);
        }
        int min = static_cast<int>(irateMin);
        
        t=irateMin-floor(irateMax);
        if (t>=0.5) {
            irateMax *= 10000.0;
            irateMax = ceil(irateMax);
        }
        else {
            irateMax *= 10000.0;
            irateMax = floor(irateMax);
        }
        int max = static_cast<int>(irateMax);
        
        srand (time(0));
        irate = (rand() % max + min) / 10000.0;
    }
    else {
        throw runtime_error( "Rahmenbedingungen zum erstellen von Zufallszahlen nicht korrekt");
    }
    
    if (capMin >= 0 && capMax >= 0 && capMin < capMax) {
        double t;
        t=capMin-floor(capMin);
        if (t>=0.5) {
            capMin *= 1000.0;
            capMin = ceil(capMin);
        }
        else {
            capMin *= 1000.0;
            capMin = floor(capMin);
        }
        long int min = static_cast<long int>(capMin);
        
        t=capMax-floor(capMax);
        if (t>=0.5) {
            capMax *= 1000.0;
            capMax = ceil(capMax);
        }
        else {
            capMax *= 1000.0;
            capMax = floor(capMax);
        }
        long int max = static_cast<long int>(capMax);
        
        srand (time(NULL));
        long int temp = rand() % min + max;
        if (inv.size() > 0) {
            inv.clear();
            inv.push_back(temp);                                                    // Verwendung von inv.clear() ?
        }
        else {
            inv.push_back(temp);
        }
    }
    else {
        throw runtime_error( "Rahmenbedingungen zum erstellen von Zufallszahlen nicht korrekt");
    }
}

double NPV::calc(int years) {
    if( inv.size() > 1 ) {
        long int temp = inv.at(0);
        inv.clear();
        inv.push_back(temp);
    }
    
    for ( int i = 1; i <= years; i++ ) {
        double value = inv.at(i - 1) / 1000.0;
        value *= pow((1 + irate), -i);   
        
        // runden
        double t;
        t=value-floor(value);
        if (t>=0.5) {
            value *= 1000.0;
            value = ceil(value);
        }
        else {
            value *= 1000.0;
            value = floor(value);
        }
        long int temp = static_cast<long int>(value);
        inv.push_back(temp);
    }
    
    return inv.at(years) / 1000.0;
}
