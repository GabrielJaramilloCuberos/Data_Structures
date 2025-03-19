#ifndef NODO_H
#define NODO_H
#include <bits/stdc++.h>

using namespace std;

template <class T> class Node {
    private: 
        T character;
        int bit;
        Node *left = nullptr;
        Node *right = nullptr;
    public:
        Node();
        void setData(T nData);
        void setBit(int  b);
        void addLeft(Node *leftNode);
        void addRight(Node *rightNode);
        T getCharacter();
        int getBit();
        Node* getLeftNode();
        Node* getRightNode();
};

#include "NODO.cpp"

#endif // NODO_H