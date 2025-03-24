#include "../BST/TADS/NODE.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    Node* root = nullptr;
    root = insertarNodo(root, 50);
    root = insertarNodo(root, 30);
    root = insertarNodo(root, 55);
    root = insertarNodo(root, 40);
    root = insertarNodo(root, 70);
    root = insertarNodo(root, 60);
    root = insertarNodo(root, 80);

    cout << "El recorrido inorder es: ";
    inOrder(root);
    cout << endl;

    return 0;

}
