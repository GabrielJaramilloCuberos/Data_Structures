#include "./TADS/NODO.h"
#include <bits/stdc++.h>

using namespace std;


int main(){
    Node<int> root = Node<int>();
    Node<int> *temp = new Node<int>();
    temp->setBit(1);
    temp->setData('a');
    temp->addLeft(nullptr);
    temp->addRight(nullptr);
    root.addLeft(temp);
    cout << root.getLeftNode()->getCharacter() << endl;
    

}