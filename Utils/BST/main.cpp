
#include "TADS/BST.h"
#include <bits/stdc++.h>

using namespace std;


int main(){
	struct Node *root = newNode(23);
	root->left = newNode(10);
	root->left->right = newNode(19);
	root->left->left = newNode(2);
	root->left->left->left = newNode(1);
    root->left->left->right = newNode(3);
    root->right = newNode(48);
    root->right->left = newNode(35);
    root->right->left->left = newNode(32);
    root->right->left->right = newNode(40);
    root->right->right = newNode(53);
    root->right->right->right = newNode(54);
    /*
	cout<<"Preorder traversal: ";
	traversePreOrder(root);
    */
	cout<<"\nInorder traversal: ";
	traverseInOrder(root);
    cout<<"\n";
    
    cout<<"Funciona el traverseInOrder2?\n";
    struct Node foundNode = traverseInOrder2(2, root);
    cout<<"Si\n";
    struct Node father = traverseInOrder3(2, root);
    cout<<"Funciona el traverseInOrder3?\n"; 
    cout<<"Si\n";
    deleteNode(&foundNode,&father);
    cout<<"\nInorder traversal: ";
	traverseInOrder(root);
    /*
	cout<<"\nPostorder traversal: ";
    
	traversePostOrder(root);
    */
    return 0;
}