/* 
 * File:   main.cpp
 * Author: Yannik
 *
 * Created on 23. April 2013, 21:32
 */

#include <cstdlib>
#include "Frame.h"

using namespace std;

void drawLine( Frame f, int start_Xcoord, int start_Ycoord, int end_Xcoord, int end_Ycoord ) {
    bool switchedSign = false;
    bool mirrored = false;
    int dY = 0;
    int dX = 0;
    f.put_point( start_Xcoord, start_Ycoord );
    
    if( end_Xcoord < start_Xcoord ) { 
        int temp = end_Xcoord;
        end_Xcoord = start_Xcoord;
        start_Xcoord = temp;
    }
    
    if( end_Ycoord < start_Ycoord ) { 
        bool switchedSign = true;
        end_Ycoord = 0 - end_Ycoord;
        start_Ycoord = 0 - start_Ycoord;
    }
    
    if( (end_Xcoord - start_Xcoord) < (end_Ycoord - start_Ycoord) ) { 
        mirrored = true;
        int temp = start_Xcoord;
        start_Xcoord = start_Ycoord;
        start_Ycoord = temp;
        temp = end_Xcoord;
        end_Xcoord = end_Ycoord;
        end_Ycoord = temp;
    }

    dY = start_Ycoord - end_Ycoord;
    dX = start_Xcoord - end_Xcoord;
    
    if( 2* dY < dX ) {
        start_Xcoord++;
    }
    else {
        start_Xcoord++;
        start_Ycoord++;
    }
    
    if( switchedSign ) {
        if( mirrored ) {
            f.put_point( (0 - start_Ycoord), (0 - start_Xcoord) );
        }
        else {
            f.put_point( (0 - start_Xcoord), (0 - start_Ycoord) );
        }
    }
    else {
        if( mirrored ) {
            f.put_point( start_Ycoord, start_Xcoord );
        }
        else {
            f.put_point( start_Xcoord, start_Ycoord );
        }
    }
}

int main( ) {
    
    return 0;
}

