/* 
 * File:   Frame.h
 * Author: Yannik
 *
 * Created on 23. April 2013, 21:32
 */

#ifndef FRAME_H
#define	FRAME_H

const int xMax = 55; // Zeichen pro Frame-Zeile 
const int yMax = 34; // Zeilen pro Frame

class Frame {
public:
    enum color { black = ' ', white = '*' };
    Frame( );
    void put_point( int, int );  // Punkt im Frame speichern 
    void reset( );  // Frame leeren
    void show( ) const;  // Frame auf die Konsole ausgeben 
    bool on_frame( int, int ) const; // "Clipping"
private:
    char frame[xMax][yMax];
};

std::ostream& operator<<(std::ostream& os, const Frame* f);

#endif	/* FRAME_H */
