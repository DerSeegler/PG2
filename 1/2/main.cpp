/* 
 * File:   main.cpp
 * Author: Yannik
 *
 * Created on 10. April 2013, 10:25
 */

#include <iostream>
#include "Classes.h"

using namespace std;

int main( ) {
    try {
        cout << "Moechten Sie sich zufaellige Werte generieren lassen? (y/n)" << endl << ">";
        char answer = ' ';
        if ( !(cin >> answer) ) {
            throw runtime_error( "Fehler bei der Eingabe");
        }
        
        if (answer == 'y') {
            NPV npv = NPV( 0.0, 0.05, 500.0, 10000.0 );
            
            int years = 0;
        
            cout << "Bitte geben Sie die Anzahl der Jahre ein:" << endl << ">";
            if ( !(cin >> years) ) {
                throw runtime_error( "Fehler bei der Eingabe");
            }

            cout << "Berechnetes Ergebnis: " << npv.calc( years ) << endl;
        }
        else {
            if (answer == 'n') {
                double capital = -1.0;
                double interest_rate = -1.0;
                cout << "Bitte geben Sie das Startkapital ein:" << endl << ">";
                if ( !(cin >> capital) ) {
                    throw runtime_error( "Fehler bei der Eingabe");
                }
                cout << "Bitte geben Sie den Zinssatz ein:" << endl << ">";
                if ( !(cin >> interest_rate) ) {
                    throw runtime_error( "Fehler bei der Eingabe");
                }
                NPV npv = NPV( capital, interest_rate );
                
                int years = 0;
        
                cout << "Bitte geben Sie die Anzahl der Jahre ein:" << endl << ">";
                if ( !(cin >> years) ) {
                    throw runtime_error( "Fehler bei der Eingabe");
                }

                cout << "Berechnetes Ergebnis: " << npv.calc( years ) << endl;
            }
            else {
                throw runtime_error( "Fehler bei der Eingabe");
            }
        }
        
        return 0;
    }
    catch( exception &e ) {
        cerr << e.what() << endl;
        return -1;
    }
    catch( ... ) {
        cerr << "Unbekannter Fehler";
        return -2;
    }
}
