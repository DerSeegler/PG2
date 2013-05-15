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

class Shape {
public:
    Shape() : prev( 0 ) { last = 0; }  // Definition Standardkonstruktor
    virtual void draw( Frame* ptarget ) = 0;  // rein virtuelle Methode
    virtual void move( int hor, int ver ) = 0; // rein virtuelle Methode
private: 
    Shape* last; // Zeiger auf die zuletzt erzeugte Figur (d.h. Listenanfang)
    Shape* prev; // Zeiger auf die zuvor erzeugte Figur 
    // (d.h. die naechste in der Liste) 
};

class Line : public Shape {
public:
    Line(); // Standardkonstruktor 
    Line( int, int, int, int ); // ein Konstruktor 
    void set( int, int, int, int ); 
    void draw( Frame* ); // rein virtuelles shape::draw() ueberschreiben
    void move( int h, int v ); // rein virtuelles shape::move() ueberschreiben 
private:
    int start_Xcoord, start_Ycoord, end_Xcoord, end_Ycoord; 
};

class Triangle : public Shape {
public:
    Triangle(); // Standardkonstruktor 
    Triangle( int, int, int, int, int, int );
    Triangle( int, int, int, int, int );
    void set( int, int, int, int, int, int ); 
    void draw( Frame* ); // rein virtuelles shape::draw() ueberschreiben
    void move( int h, int v ); // rein virtuelles shape::move() ueberschreiben 
    bool check();
private:
    int xa, ya, xb, yb, xc, yc;
};

std::ostream& operator<<(std::ostream& os, const Frame* f);

#endif	/* FRAME_H */
