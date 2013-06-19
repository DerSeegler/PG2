/* 
 * File:   main.cpp
 * Author: Yannik
 *
 * Created on 19. Juni 2013, 19:06
 */

#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // Dateinamen fuer Quell- und Zieldatei einlesen:
    string from="input2.txt", to="output.txt";
    // Ein- und Ausgabe-Stream erstellen:
    ifstream is( from.c_str() ); 
    ofstream os( to.c_str() ); 
    
    if(!is.good()) {
        throw runtime_error("Quelldatei konnte nicht gelesen werden.");
    }
    
    // Stream-Iterator zur Eingabe:
    istream_iterator<string> ii( is ); 
    // "end-of-stream" (wird standardmaessig auf EOF/end-of-file gesetzt):
    // genauer: auf char_traits<Ch>::eof() 
    istream_iterator<string> eos; 
    // Stream-Iterator zur Ausgabe, der jedesmal "\n" anhaengt:
    ostream_iterator<string> oo( os, "\n" ); 
    // Das vector-Objekt namens buffer wird mit dem Input initialisiert:
    vector<string> buffer( ii, eos );
    
    map<string,int> words; // Worte und ihre Haeufigkeit
    for(int i = 0; i < buffer.size(); i++) {
        ++words[buffer[i]]; 
    }
    
    typedef map<string,int>::const_iterator Iter;
    multimap<int,string> m;
    for( Iter p = words.begin(); p != words.end(); ++p ) {
        m.insert(pair<int,string>(p->second,p->first));
    }
    
    typedef multimap<int,string>::const_iterator Iter2;
    for( Iter2 p = m.begin(); p != m.end(); ++p ) {
        cout << p->second << " " << p->first << endl;
        if (os.good()) {
            os << p->second << " " << p->first << endl;
        }
        else {
            throw runtime_error("Zieldatei konnte nicht geschrieben werden.");
        }
    }
        
    return 0;
}

