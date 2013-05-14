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
    if( on_frame(x, y) ) {
        frame[x][y] = '*';
    }
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

Line::Line() : start_Xcoord(0), start_Ycoord(0), end_Xcoord(0), end_Ycoord(0) { }

Line::Line( int sx, int sy, int ex, int ey ) : start_Xcoord(sx), start_Ycoord(sy), end_Xcoord(ex), end_Ycoord(ey) { }

Line::move( int h, int v ) { 
    start_Xcoord += h; start_Ycoord += v; end_Xcoord += h; end_Ycoord += v;
}

Line::draw( Frame* f ) {
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
        std::cout << "Einige Punkte liegen ausserhalb des sichtbaren Bereiches und koennen nicht angezeigt werden." << std::endl;
    }
}

Triangle::Triangle() : xa(0), ya(0), xb(0), yb(0), xc(0), yc(0) { }

Triangle::Triangle( int u, int v, int w, int x, int y, int z ) : xa(u), ya(v), xb(w), yb(x), xc(y), yc(z) { }

Triangle::Triangle( int h, int v ) { 
    xa += h;
    xb += h;
    xc += h;
    ya += v;
    yb += v;
    yc += v;
}

Triangle::check() {
    double ab_steigung = 0.0;
    double bc_steigung = 0.0;
    
    if( xb > xa ) {
        if( yb > ya ) {
            ab_steigung = ( yb - ya ) / ( xb - xa );
        }
        else {
            ab_steigung = ( ya - yb ) / ( xb - xa );
        }
    }
    else {
        if( yb > ya ) {
            ab_steigung = ( yb - ya ) / ( xa - xb );
        }
        else {
            ab_steigung = ( ya - yb ) / ( xa - xb );
        }
    }
    
    if( xc > xb ) {
        if( yc > yb ) {
            bc_steigung = ( yc - yb ) / ( xc - xb );
        }
        else {
            bc_steigung = ( yb - yc ) / ( xc - xb );
        }
    }
    else {
        if( yc > yb ) {
            bc_steigung = ( yc - yb ) / ( xb - xc );
        }
        else {
            bc_steigung = ( yb - yc ) / ( xb - xc );
        }
    }
    
    if( ab_steigung == bc_steigung ) {
        return false;
    }
    
    return true;
}

Triangle::Triangle( Frame* f ) {
    if( check() ) {
        Line ab = Line( xa, ya, xb, yb );
        Line bc = Line( xb, yb, xc, yc );
        Line ca = Line( xc, yc, xa, ya );
        ab.draw( f );
        bc.draw( f );
        ca.draw( f );
    }
    else {
        std::cout << "Die eingegebenen Koordinaten ergeben kein gültiges Dreieck!";
    }
}

std::ostream& operator<<(std::ostream& os, const Frame* f) {
    f->show();
    return os;
};
