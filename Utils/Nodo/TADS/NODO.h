#ifndef NODO_H
#define NODO_H


#include <bits/stdc++.h>
using namespace std;

class Node {
    private: 
        int character;
        int bit;
        Node *left;
        Node *right;
    public:
        Node();
        void setData(int nData);
        void addLeft(Node *leftNode);
        void addRight(Node *rightNode);
        int getCharacter();
        int getBit();
        Node* getLeftNode();
        Node* getRightNode();
};



#endif // NODO_H