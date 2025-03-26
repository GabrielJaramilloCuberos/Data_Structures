#include "../AVL/TADS/NODE.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    Node* root = new Node();
    root->setVal(0);
    cout<<"Root: "<<root->getVal()<<endl;
    root = insertarNodo(root, 10);
    root = insertarNodo(root, 10);
    root = insertarNodo(root, 20);
    root = insertarNodo(root, 30);
    root = insertarNodo(root, 40);
    root = insertarNodo(root, 50);
    root = insertarNodo(root, 60);
    root = insertarNodo(root, 80);
    root = insertarNodo(root, 80);
    root = insertarNodo(root, 90);

    inOrder(root);
}