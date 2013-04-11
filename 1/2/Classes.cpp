/* 
 * File:   Classes.cpp
 * Author: Yannik
 * 
 * Created on 10. April 2013, 10:26
 */

#include <iostream>

#include "Classes.h"

NPV::NPV() : irate(0) { }

NPV::NPV( double capital, double interest_rate ) {
    if (capital > 0 || interest_rate < 0) {
        throw runtime_error( "Investition muss negativ eingegeben werden und Zinssatz darf nicht negativ sein");
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
    
    long int cap = (long int)(capital);
    
    if (inv.size() > 0) {
        inv.clear();
        inv.push_back(cap);                                                    // Verwendung von inv.clear() ?
    }
    else {
        inv.push_back(cap);
    }
    
    populateInv();
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
        int min = (int)(irateMin);
        
        t=irateMin-floor(irateMax);
        if (t>=0.5) {
            irateMax *= 10000.0;
            irateMax = ceil(irateMax);
        }
        else {
            irateMax *= 10000.0;
            irateMax = floor(irateMax);
        }
        int max = (int)(irateMax);
        
        srand (time(0));
        irate = (rand() % max + min) / 10000.0;
        
        populateInvRand();
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
        long int min = (long int)(capMin);
        
        t=capMax-floor(capMax);
        if (t>=0.5) {
            capMax *= 1000.0;
            capMax = ceil(capMax);
        }
        else {
            capMax *= 1000.0;
            capMax = floor(capMax);
        }
        long int max = (long int)(capMax);
        
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

double NPV::calc() const {
    double result = inv.at(0) / 1000.0;
    for ( int i = 1; i < inv.size(); i++ ) {
        double value = inv.at(i) / 1000.0;
        value *= pow((1 + irate), -i);   

        result += value;
    }
    
    // runden
    double t = 0.0;
    t=result-floor(result);
    if (t>=0.5) {
        result *= 1000.0;
        result = ceil(result);
    }
    else {
        result *= 1000.0;
        result = floor(result);
    }
    
    return result / 1000.0;
}

void NPV::populateInv() {
    char temp = ' ';
    double zahl = -1;
    std::cout << "Bitte geben Sie Ihre jaehrliche Investition ein: (q zum abbrechen)" << std::endl << ">";
    while (std::cin >> temp && temp != 'q') {
        std::cin.putback(temp);
        std::cin >> zahl;
        if (std::cin.fail()) {
            throw runtime_error("Falsche Eingabe");
        }
        
        double t;
        t=zahl-floor(zahl);
        if (t>=0.5) {
            zahl *= 1000.0;
            zahl = ceil(zahl);
        }
        else {
            zahl *= 1000.0;
            zahl = floor(zahl);
        }
        long int temp = (long int)(zahl);
        
        inv.push_back(temp);
    }
}

void NPV::populateInvRand() {
    //srand(time(0));
    int zahl = (rand() % 999 + 111);
    for (int i = 0; i < 4; i++) {
        inv.push_back(zahl);
    }
}