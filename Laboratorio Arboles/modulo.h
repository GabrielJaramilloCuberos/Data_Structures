#ifndef MODULO_H
#define MODULO_H

struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *newNode(int data);

void traversePreOrder(struct Node *temp);

void traverseInOrder(struct Node *temp);

void traversePostOrder(struct Node *temp);
#endif // MODULO_H