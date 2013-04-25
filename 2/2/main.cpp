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

void drawLine( Frame &f, int start_Xcoord, int start_Ycoord, int end_Xcoord, int end_Ycoord ) {
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

    if( end_Ycoord < start_Ycoord ) { 
        switchedSign = true;
        end_Ycoord *= -1;
        start_Ycoord *= -1;
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
        if( switchedSign ) {
            if( mirrored ) {
                f.put_point( (start_Ycoord), (-start_Xcoord) );
            }
            else {
                f.put_point( ( start_Xcoord), (-start_Ycoord) );
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

        if( dXY < 0 ) {
            start_Xcoord++;
            dXY += 2 * dY;
        }
        else {
            start_Xcoord++;
            start_Ycoord++;
            dXY += 2 * (dY - dX);
        }
    }
    
    if (!(f.on_frame(start_Xcoord, start_Ycoord) && f.on_frame(end_Xcoord, end_Ycoord))) {
        cout << "Einige Punkte liegen ausserhalb des sichtbaren Bereiches und koennen nicht angezeigt werden." << endl;
    }
}

int main( ) {
    try {
        Frame f = Frame();
        drawLine(f,1, 1, 13, 100);
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
