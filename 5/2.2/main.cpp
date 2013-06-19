/* 
 * File:   main.cpp
 * Author: Yannik
 *
 * Created on 19. Juni 2013, 21:55
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
    string from="../2/output.txt";
    // Ein- und Ausgabe-Stream erstellen:
    ifstream is( from.c_str() ); 
    
    if(!is.good()) {
        throw runtime_error("Quelldatei konnte nicht gelesen werden.");
    }
    
    // Stream-Iterator zur Eingabe:
    istream_iterator<string> ii( is ); 
    // "end-of-stream" (wird standardmaessig auf EOF/end-of-file gesetzt):
    // genauer: auf char_traits<Ch>::eof() 
    istream_iterator<string> eos; 

    // Das vector-Objekt namens buffer wird mit dem Input initialisiert:
    vector<string> buffer( ii, eos );
    
    multimap<int,string> words; // Worte und ihre Haeufigkeit
    cout << words.max_size() << " " << buffer.size();
    for(int i = 0; i < buffer.size(); i+=2) {
        int key = atoi(buffer[i+1].c_str());
        words.insert(pair<int,string>(key,buffer[i]));
        //cout << buffer[i+1] << " " << buffer[i];
    }
    
    typedef multimap<int,string>::const_iterator Iter;
    for( Iter p = words.begin(); p != words.end(); ++p ) {
        cout << p->second << " " << p->first << endl;
    }
    
//    Iter p = words.begin();
//    while(true) {
//        cout << p->second << " " << p->first << endl;
//        p++;
//    }
    
    return 0;
}

