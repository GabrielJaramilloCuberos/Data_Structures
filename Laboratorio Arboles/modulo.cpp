#include "modulo.h"
#include <bits/stdc++.h>

using namespace std;


struct Node *newNode(int data){
	struct Node *Node = (struct Node *)malloc(sizeof(struct Node));

	Node->data = data;
	
	Node->left = NULL;
	Node->right = NULL;

	return (Node);

}

void traversePreOrder(struct Node *temp){
	if (temp != NULL){
		cout<<" " << temp->data;
		traversePreOrder(temp->left);
		traversePreOrder(temp->right);
	}
}

void traverseInOrder(struct Node *temp){
	if (temp != NULL){
		traverseInOrder(temp->left);
		cout<<" " << temp->data;
		traverseInOrder(temp->right);
	}
}


void traversePostOrder(struct Node *temp){
	if (temp != NULL){
		traversePostOrder(temp->left);
		traversePostOrder(temp->right);
		cout<<" " << temp->data;
	}
}
