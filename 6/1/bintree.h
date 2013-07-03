/* 
 * File:   bintree.h
 * Author: Yannik
 *
 * Created on 2. Juli 2013, 12:23
 */

#ifndef BINTREE_H
#define	BINTREE_H

#include <queue>
#include <iostream>

template<class T>
class Bintree {

    struct node {
        T val;
        int count;
        node* left;
        node* right;
        node* pre;
        node( T v = T(), node* l = 0, node* r = 0, node* p = 0 ) : val(v), left(l), right(r), pre(p), count(1) {}
    };

    private:
        node* root;
    public:
        Bintree();
        Bintree(node*);
        Bintree(T);
        typedef node* nodep;
        node* getRoot();
        int countTreePart(node*);
        int getTreeHeight();
        node* find(T);
        void insert(T);
        void in_order(node*);
        void level_order(node*);
        void insertAsRoot(T);
        void rotateR(nodep&);
        void rotateL(nodep&);
};


template<class T>
Bintree<T>::Bintree() {
    root = new node();
}

template<class T>
Bintree<T>::Bintree(node* r) {
    root = r;
}

template<class T>
Bintree<T>::Bintree(T r) {
    root = new node(r);
}

template<class T> typename
Bintree<T>::node* Bintree<T>::getRoot() {
    return root;
}

template<class T>
int Bintree<T>::countTreePart(node* n) {
    int counter = 1;
    
    counter += countTreePart(n->left);
    counter += countTreePart(n->right);
    
    return counter;
}

template<class T>
int Bintree<T>::getTreeHeight() {
    int counter = 0;
    node* n = root;
    
    if( n==0 ) {
        return 0;
    }
    
    std::queue<node*> q;
    q.push( n );
    while( !q.empty() ) {
        n = q.front();
        q.pop();
        if( n->left != 0 ) q.push( n->left );
        if( n->right != 0 ) q.push( n->right );
    }
    
    while(n != 0) {
        ++counter;
        n = n->pre;
    }
    
    return counter;
}

template<class T> typename
Bintree<T>::node* Bintree<T>::find(T v) {
    node* r = root;
    
    while(r!=0) {
        if(v > r->val) {
            r = r->right;
        }

        if(v < r->val) {
            r = r->left;
        }

        if(v == r->val) {
            return r;
        }
    }
    
    return 0;
}

template<class T>
void Bintree<T>::insert(T v) {
    node* r = root;
    bool run = true;
    
    while(run) {
        if(v == r->val) {
            r->count++;
            return;
        }
        
        if(v > r->val) {
            if(r->right == 0) {
                run = false;
            }
            else {
                r = r->right;
            }
        }

        if(v < r->val) {
            if(r->left == 0) {
                run = false;
            }
            else {
                r = r->left;
            }
        }
    }
    
    node* newNode = new node(v, 0, 0, r);
    
    if(newNode->val > r->val) {
        r->right = newNode;
    }

    if(newNode->val < r->val) {
        r->left = newNode;
    }
}

template<class T>
void Bintree<T>::in_order(node* n) {
    if( n==0 ) return;
    if( n->left != 0 ) {
        in_order( n->left );
    }
    
    std::cout << n->val << " ";
    if( n->right != 0 ) {
        in_order( n->right );
    }
}

template<class T>
void Bintree<T>::level_order(node* n) {
    if( n==0 ) return;
    std::queue<node*> q;
    q.push( n );
    while( !q.empty() ) {
        n = q.front();
        q.pop();
        std::cout << n->val << " ";
        if( n->left != 0 ) q.push( n->left );
        if( n->right != 0 ) q.push( n->right );
    }
}

template<class T>
void Bintree<T>::insertAsRoot(T v) {
    node* r = root;
    bool run = true;
    int counter = 0;
    
    while(run) {
        if(v == r->val) {
            r->count++;
            return;
        }
        
        if(v > r->val) {
            if(r->right == 0) {
                run = false;
            }
            else {
                r = r->right;
            }
        }

        if(v < r->val) {
            if(r->left == 0) {
                run = false;
            }
            else {
                r = r->left;
            }
        }
        
        ++counter;
    }
    
    node* newNode = new node(v, 0, 0, r);
    
    if(newNode->val > r->val) {
        r->right = newNode;
    }

    if(newNode->val < r->val) {
        r->left = newNode;
    }
    
    level_order(root);
    std::cout << std::endl;
    
        if(newNode->val < r->val) {
            rotateR(r);
        }
        else {
            rotateL(r);
        }
    
    root = r;
}

template<class T>
void Bintree<T>::rotateR( nodep& w ) {
    if( w==0 || w->left==0 ) {
       return;
    }
    
    nodep x = w->left; 
    x->pre = w->pre;
    w->pre = x; 
    w->left = x->right;
    x->right = w; 
    if( w->left ) {
        w->left->pre = w; 
    }
    
    w = x;
    
    if(w->pre != 0) {
        if(w->val < w->pre->val) {
            rotateR( w->pre );
        }
        else {
            rotateL( w->pre );
        }
    }
}

template<class T>
void Bintree<T>::rotateL( nodep& w ) {
    if( w==0 || w->right==0 ) {
       return;
    }
    
    nodep x = w->right; 
    x->pre = w->pre;
    w->pre = x; 
    w->right = x->left;
    x->left = w; 
    if( w->right ) {
        w->right->pre = w; 
    }
    
    w = x;
    
    if(w->pre != 0) {
        if(w->val < w->pre->val) {
            rotateR( w->pre );
        }
        else {
            rotateL( w->pre );
        }
    }
}

#endif	/* BINTREE_H */

