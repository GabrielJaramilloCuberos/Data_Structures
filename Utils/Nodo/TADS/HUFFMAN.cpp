#include "HUFFMAN.h"
#include "NODO.h"
#include <bits/stdc++.h>

using namespace std;

template <class T> Tree<T>::Tree() {
    root = nullptr;
    Node<T> *nroot;
    
}

template <class T> void Tree<T>::setRoot(Node<T> *nRoot) {
    root = nRoot;
}

template <class T> Node<T>* Tree<T>::getRoot() {
    return root;
}

