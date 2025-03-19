#ifndef NODO_H
#define NODO_H
#include "NODO.h"
using namespace std;

template <class T> class Tree{

    private:

        Node<T> *root = nullptr;

    public:
        
        Tree();

        void setRoot(Node<T> *nRoot);

        Node<T>* getRoot();

};

#include "HUFFMAN.cpp"

#endif // NODO_H