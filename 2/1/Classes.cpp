/* 
 * File:   Classes.cpp
 * Author: Yannik
 * 
 * Created on 23. April 2013, 20:45
 */

#include <iostream>

#include "Classes.h"

Bas::Bas() : next(0), prev(0) { }

Pro::Pro() : name(""), value(-1) { }

Pro::Pro(std::string name_input, int value_input) : name(name_input), value(value_input) { }

void Pro::set(int setValue) {
    value = setValue;
}

void Pro::increase() {
    value++;
}

void Pro::print() const {
    std::cout << name << " - " << value << std::endl;
}

Roo::Roo() : name(""), value(-1) { }

Roo::Roo(std::string name_input, int value_input) : name(name_input), value(value_input) { }

void Roo::set(int setValue) {
    value = setValue;
}

void Roo::increase() {
    value++;
}

void Roo::print() const {
    std::cout << name << " - " << value << std::endl;
}