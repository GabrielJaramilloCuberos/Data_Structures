#include "NODE.h"
#include <bits/stdc++.h>

using namespace std;

void Node::setVal(int valor){
    val = valor;
}

void Node::setDerecha(Node* der){
    derecha = der;
}

void Node::setIzquierda(Node* izq){
    izquierda = izq;
}

int Node::getVal(){
    return val;
}

Node* Node::getDerecha(){
    return derecha;
}

Node* Node::getIzquierda(){
    return izquierda;
}


Node* crearNodo(int value){
    Node *nuevoNodo = new Node();
    nuevoNodo->setVal(value);
    nuevoNodo->setIzquierda(nullptr);
    nuevoNodo->setDerecha(nullptr);
    return nuevoNodo;
}

Node* insertarNodo(Node* root, int value){
    if(root == nullptr){
        return crearNodo(value);
    }

    if(value < root->getVal()){
        root->setIzquierda(insertarNodo(root->getIzquierda(), value)); 
    }else if(value > root->getVal()){
        root->setDerecha(insertarNodo(root->getDerecha(), value)); 
    }
    return root;
}

void inOrder(Node* root){
    if(root != nullptr){
        inOrder(root->getIzquierda());
        cout<<"\nEL valor del nodo es: "<<root->getVal();
        inOrder(root->getDerecha());
    }
}

Node* buscarNodo(Node* root, int valor){
    if(root == nullptr || root->getVal() == valor){
        return root;
    }

    if(root->getVal() < valor){
        return buscarNodo(root->getDerecha(), valor);
    }else if(root->getVal() > valor){
        return buscarNodo(root->getIzquierda(), valor);
    }

    return nullptr;
}

Node* hojaMenor(Node* root){
    Node* actual = root;
    while(root && root->getIzquierda() != nullptr){
        actual = actual->getIzquierda();
    }
    return actual;
}

Node* eliminarNodo(Node* root, int valor){
    if(root == nullptr){
        return root;
    }

    if(valor < root->getVal()){
        root->setIzquierda(eliminarNodo(root->getIzquierda(), valor)); 
    }else if(valor > root->getVal()){
        root->setDerecha(eliminarNodo(root->getDerecha(), valor)); 
    }
    else{
        if(root->getIzquierda() == nullptr){
            Node* temporal = root->getDerecha();
            delete root;
            return temporal;
        }else if(root->getDerecha() == nullptr){
            Node* temporal = root->getIzquierda();
            delete root;
            return temporal;
        }
        Node* temporal = hojaMenor(root->getDerecha());
        root->setVal(temporal->getVal()); 
        root->setDerecha(eliminarNodo(root->getDerecha(), temporal->getVal()));
    }
    return root;
}

