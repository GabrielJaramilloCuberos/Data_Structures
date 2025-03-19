#include "NODO.h"
using namespace std;

template <class T> Node<T>::Node(){
    left = nullptr;
    right = nullptr;
    character = 0;
    bit = -1;
}
template <class T>  void Node<T>::setData(T nData){
    character = nData;
}

template <class T> void  Node<T>::setBit(int b){
    bit = b;
}

template <class T> void Node<T>::addLeft(Node *leftNode){
    left = leftNode;
}
template <class T>  void Node<T>::addRight(Node *rightNode){
    right = rightNode;
}
template <class T> T Node<T>::getCharacter(){
    return character;
}
template <class T> int Node<T>::getBit(){
    return bit;
}
template <class T> Node<T>* Node<T>::getLeftNode(){
    return left;
}
 
template <class T> Node<T>* Node<T>::getRightNode(){
    return right;
}    
