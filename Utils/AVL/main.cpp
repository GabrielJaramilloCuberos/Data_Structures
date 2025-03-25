#include "../AVL/TADS/NODE.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    Node* root;
    insertarNodo(root, 10);
    insertarNodo(root, 20);
    insertarNodo(root, 30);
    insertarNodo(root, 40);
    insertarNodo(root, 50);
    insertarNodo(root, 25);

    cout<<"Inorder : \n";
    inOrder(root);

    eliminarNodo(root, 30);

    cout<<"Inorder : \n";
    inOrder(root);

    
}