/* 
 * File:   Frame.cpp
 * Author: Yannik
 * 
 * Created on 23. April 2013, 21:32
 */

#include <iostream>

#include "Frame.h"

Frame::Frame() {
    for( int i = 0; i < yMax; i++ ) {
       for( int j = 0; j < xMax; j++ ) {
           frame[j][i] = ' ';
       } 
    }
}

void Frame::put_point( int x, int y ) {
    frame[x][y] = '*';
}

void Frame::reset( ) {
    for( int i = 0; i < yMax; i++ ) {
       for( int j = 0; j < xMax; j++ ) {
           frame[j][i] = ' ';
       } 
    }
}

void Frame::show( ) const {
    for( int i = (yMax - 1); i >= 0; i-- ) {
       for( int j = 0; j < xMax; j++ ) {
           std::cout << frame[j][i];
       }
       
       std::cout << std::endl;
    }
}

bool Frame::on_frame( int x, int y ) const {
    if( x < xMax && x > -1 && y < yMax && y > -1 ) {
        return true;
    }
    
    return false;
}
