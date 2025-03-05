// Source: https://usaco.guide/general/io
#include "modulo.cpp"
#include <bits/stdc++.h>

using namespace std;


int main(){
	struct Node *root = newNode(7);
	root->left = newNode(3);
	root->left->left = newNode(0);
	root->left->left->left = newNode(-3);
	root->left->left->right = newNode(1);
	root->left->right = newNode(5);
	root->left->right->left = newNode(4);
	root->left->right->right = newNode(6);
	root->right = newNode(20);
	root->right->left = newNode(15);
	root->right->right = newNode(25);
	root->right->right->right = newNode(30);
	cout<<"Preorder traversal: ";
	traversePreOrder(root);
	cout<<"\nInorder traversal: ";
	traverseInOrder(root);
	cout<<"\nPostorder traversal: ";
	traversePostOrder(root);
}