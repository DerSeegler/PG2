/* 
 * File:   Classes.h
 * Author: Yannik
 *
 * Created on 23. April 2013, 20:45
 */

#ifndef CLASSES_H
#define	CLASSES_H

class Bas {
public:
    Bas();
private:
    Bas* next;
    Bas* prev;
};

class Pro : Bas {
public:
    Pro();
    Pro( std::string, int );
    void set( int );
    void increase();
    void print() const;
private:
    std::string name;
    int value;
};

class Roo : Bas {
public:
    Roo();
    Roo( std::string, int );
    void set( int );
    void increase();
    void print() const;
private:
    std::string name;
    int value;
};

#endif	/* CLASSES_H */

