/* 
 * File:   main.cpp
 * Author: Yannik
 *
 * Created on 2. Juli 2013, 12:22
 */

#include <iostream>
#include "bintree.h"

using namespace std;

/*
 * 
 */
int main( ) {
    Bintree<int> bt(10);
    bt.insert(4);
    bt.insert(3);
    bt.insert(11);
    bt.insert(2);
    bt.insert(16);
    bt.insert(15);
    bt.insert(13);
    bt.insert(12);
    bt.insert(14);
    
    bt.in_order(bt.getRoot());
    cout << endl;
    bt.level_order(bt.getRoot());
    cout << endl;
    cout << bt.getTreeHeight();
    cout << endl;
    
    bt.insertAsRoot(1);
    bt.insert(0);
    
    bt.in_order(bt.getRoot());
    cout << endl;
    bt.level_order(bt.getRoot());
    cout << endl;
    cout << bt.getTreeHeight();
    cout << endl;
    
    return 0;
}

