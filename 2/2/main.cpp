/* 
 * File:   main.cpp
 * Author: Yannik
 *
 * Created on 23. April 2013, 21:32
 */

#include <iostream>
#include "Frame.h"

using namespace std;

void drawLine( Frame* f, int start_Xcoord, int start_Ycoord, int end_Xcoord, int end_Ycoord ) {
    bool switchedSign = false;
    bool mirrored = false;
    int dY = -1;
    int dX = -1;
    int dXY = -1;
    
    if( end_Xcoord < start_Xcoord ) { 
        int temp = end_Xcoord;
        end_Xcoord = start_Xcoord;
        start_Xcoord = temp;
        temp = end_Ycoord;
        end_Ycoord = start_Ycoord;
        start_Ycoord = temp;
    }
    
    f->put_point( start_Xcoord, start_Ycoord );
    
    if( end_Ycoord < start_Ycoord ) { 
        switchedSign = true;
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
    
    dY = end_Ycoord - start_Ycoord;
    dX = end_Xcoord - start_Xcoord;
    dXY = 2 * dY -dX;
        
    for (int i = 0; i <= dX; ++i) {
        if( dXY < 0 ) {
            start_Xcoord++;
            dXY += 2 * dY;
        }
        else {
            start_Xcoord++;
            start_Ycoord++;
            dXY += 2 * (dY - dX);
        }

        if( switchedSign ) {
            if( mirrored ) {
                f->put_point( (0 - start_Ycoord), (0 - start_Xcoord) );
            }
            else {
                f->put_point( (0 - start_Xcoord), (0 - start_Ycoord) );
            }
        }
        else {
            if( mirrored ) {
                f->put_point( start_Ycoord, start_Xcoord );
            }
            else {
                f->put_point( start_Xcoord, start_Ycoord );
            }
        }
    }
}

int main( ) {
    Frame* f = new Frame();
    drawLine(f,50, 20, 5, 3);
    f->show();
    return 0;
}
