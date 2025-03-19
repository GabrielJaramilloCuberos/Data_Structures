#include "./TADS/NODO.h"
#include "./TADS/HUFFMAN.h"
#include <bits/stdc++.h>

using namespace std;


int main(){
    Node<int> root = Node<int>();
    Node<int> *temp = new Node<int>();
    Tree<int> tree = Tree<int>();
    root.setData(69);
    root.setBit(0);
    temp->setData(2);
    temp->setBit(1);
    root.addLeft(temp);
    tree.setRoot(&root);
    cout<< tree.getRoot()->getCharacter() << endl;

    

}