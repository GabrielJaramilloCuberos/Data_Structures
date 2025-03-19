#include "BST.h"
#include <bits/stdc++.h>

using namespace std;


struct Node *newNode(int data){
	struct Node *Node = (struct Node *)malloc(sizeof(struct Node));

	Node->data = data;
	
	Node->left = NULL;
	Node->right = NULL;

	return (Node);

}

void deleteNode(struct Node *temp, struct Node *father){
    cout<<"El nodo padre tiene valor de "<<father->data<<endl;
    cout<<"El nodo a eliminar tiene valor de "<<temp->data<<endl;
    cout<<"El nodo auxiliar tiene valor de "<<temp->right->data<<endl;

    struct Node *aux = temp->right;

    father->left = aux;
    aux->left = temp->left;

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

struct Node traverseInOrder2(int val, struct Node *temp) {
    // Caso base: si el nodo actual es NULL, devuelve un nodo vacío
    if (temp == NULL) {
        return {0, NULL, NULL}; // Nodo vacío con valor 0
    }

    // Si el nodo actual tiene el valor buscado, devuélvelo
    if (temp->data == val) {
        cout << "Se encontró el nodo con valor de " << temp->data << endl;
        return *temp;
    }

    // Buscar en el subárbol izquierdo
    struct Node leftResult = traverseInOrder2(val, temp->left);
    if (leftResult.data != 0) { // Si se encontró en el subárbol izquierdo
        return leftResult;
    }

    // Buscar en el subárbol derecho
    return traverseInOrder2(val, temp->right);
}

struct Node traverseInOrder3(int val, struct Node *temp) {
    // Caso base: si el nodo actual es NULL, devuelve un nodo vacío
    if (temp == NULL) {
        return {0, NULL, NULL}; // Nodo vacío con valor 0
    }

    // Si el nodo actual tiene el valor buscado, devuélvelo
    if (temp->right->data == val || temp->left->data == val) {
        cout << "Se encontró el nodo con valor de " << temp->data << endl;
        return *temp;
    }

    // Buscar en el subárbol izquierdo
    struct Node leftResult = traverseInOrder3(val, temp->left);
    if (leftResult.data != 0) { // Si se encontró en el subárbol izquierdo
        return leftResult;
    }

    // Buscar en el subárbol derecho
    return traverseInOrder3(val, temp->right);
}

void traversePostOrder(struct Node *temp){
	if (temp != NULL){
		traversePostOrder(temp->left);
		traversePostOrder(temp->right);
		cout<<" " << temp->data;
	}
}
