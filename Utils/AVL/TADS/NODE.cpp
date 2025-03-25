#include "NODE.h"
#include <bits/stdc++.h>

using namespace std;

void Node::setAltura(int alt){
    altura = alt;
}

void Node::setVal(int valor){
    val = valor;
}

void Node::setDerecha(Node* der){
    derecha = der;
}

void Node::setIzquierda(Node* izq){
    izquierda = izq;
}

int Node::getAltura(){
    return altura;
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

int alturaNodo(Node* root){
    if(root == nullptr){
        return -1;
    }else{
        return root->getAltura();
    }
}

int factorDeBalance(Node* root){
    if(root == nullptr){
        return 0;
    }else{
        return (root->getIzquierda()->getAltura() - root->getDerecha()->getAltura());
    }
}

Node* rotacionDerecha(Node* root){
    Node* x = root->getIzquierda();
    Node* z = x->getDerecha();

    x->setDerecha(root);
    root->setDerecha(z);

    root->setAltura(max(root->getDerecha()->getAltura(),root->getIzquierda()->getAltura()) + 1);
    x->setAltura(max(x->getDerecha()->getAltura(), x->getDerecha()->getAltura()) + 1);

    return x;
}

Node* rotacionIzquierda(Node* root){
    Node* y = root->getDerecha();
    Node* z = y->getIzquierda();

    y->setIzquierda(root);
    root->setDerecha(z);

    root->setAltura(max(root->getDerecha()->getAltura(), root->getDerecha()->getAltura()) + 1);
    y->setAltura(max(y->getDerecha()->getAltura(),y->getIzquierda()->getAltura()));

    return y;
}

Node* insertarNodo(Node* root, int val){
    if(root == nullptr){
        Node* nuevo;
        nuevo->setAltura(root->getAltura() + 1);
        nuevo->setDerecha(nullptr);
        nuevo->setIzquierda(nullptr);
        nuevo->setVal(val);
        return nuevo;
    }
    
    if(val < root->getVal()){
        insertarNodo(root->getDerecha(), val);
    }else if(val > root->getVal()){
        insertarNodo(root->getIzquierda(), val);
    }else{
        return root;
    }

    root->setAltura(max(root->getDerecha()->getAltura(),root->getIzquierda()->getAltura()) + 1);
    int balance = factorDeBalance(root);

    if(balance > 1 && val < root->getIzquierda()->getAltura()){
        return rotacionDerecha(root);
    }else if(balance < -1 && val > root->getDerecha()->getAltura()){
        return rotacionIzquierda(root);
    }else if(balance > 1 && val > root->getIzquierda()->getAltura()){
        root->setIzquierda(rotacionIzquierda(root->getIzquierda()));
        return rotacionDerecha(root);
    }else if(balance < -1 && val < root->getDerecha()->getVal()){
        root->setDerecha(rotacionDerecha(root->getDerecha()));
        return rotacionIzquierda(root);
    }

    return root;
}

Node* nodoMenorValor(Node* root){
    Node* actual = root;
    while(actual->getIzquierda() != nullptr){
        actual = actual->getIzquierda();
    }
    return actual;
}

Node* eliminarNodo(Node* root, int val){
    if(root == nullptr){
        return root;
    }else if(val < root->getVal()){
        root->setIzquierda(eliminarNodo(root->getIzquierda(),val));
    }else if(val > root->getVal()){
        root->setDerecha(eliminarNodo(root->getDerecha(), val));
    }else{
        if((root->getIzquierda() == nullptr) || (root->getDerecha() == nullptr)){
            Node* temp = root->getIzquierda() ? root->getIzquierda() : root->getDerecha();
            if(temp == nullptr){
                temp = root;
                root = nullptr;
            }else{
                *root = *temp;
            }
            delete temp;
        }else{
            Node* temp = nodoMenorValor(root->getDerecha());
            root->setVal(temp->getVal());
            root->setDerecha(eliminarNodo(root->getDerecha(), temp->getVal()));
        }
    }
    if(root == nullptr){
        return root;
    }
    root->setAltura(max(root->getDerecha()->getAltura(), root->getIzquierda()->getAltura()) + 1);
    int balance = factorDeBalance(root);

    if(balance > 1 && factorDeBalance(root->getIzquierda()) >= 0){
        return rotacionDerecha(root);
    }else if(balance > 1 && factorDeBalance(root->getIzquierda()) < 0){
        root->setIzquierda(rotacionIzquierda(root->getIzquierda()));
    }else if(balance < -1 && factorDeBalance(root->getIzquierda()) <= 0){
        return rotacionIzquierda(root);
    }else if(balance < -1 && factorDeBalance(root->getDerecha()) > 0){
        root->setDerecha(rotacionDerecha(root->getDerecha()));
        return rotacionIzquierda(root);
    }
    return root;

}

void inOrder(Node* root){
    if(root != nullptr){
        inOrder(root->getIzquierda());
        cout<<root->getVal()<<"\n";
        inOrder(root->getDerecha());
    }

}

bool buscarNodo(Node* root, int val){
    if(root == nullptr){
        return false;
    }
    if(root->getVal() == val){
        return true;
    }
    if(val < root->getVal()){
        return buscarNodo(root->getIzquierda(), val);
    }
    return buscarNodo(root->getDerecha(), val);
}