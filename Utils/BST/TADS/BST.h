#ifndef BST_H
#define BST_H

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};


struct Node findNodo(int val, struct Node *root);

struct Node findNodo2(int val, struct Node *root);

void deleteNode(struct Node *temp, struct Node *father);

void traversePreOrder(struct Node *temp);

void traverseInOrder(struct Node *temp);

struct Node traverseInOrder2(int val, struct Node *temp);

struct Node traverseInOrder3(int val, struct Node *temp);

void traversePostOrder(struct Node *temp);

#include "BST.cpp"

#endif // BST_H