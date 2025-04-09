/**********************************************************************************************
* Pontificia Universidad Javeriana
* Fecha: Abril 2025
* Autor: J. Corredor, PhD. Modificacion Salomon Avila
* Estructura de Datos
* Tema: Construcción de Arbol (Impresión InOrden) 
* Descripción: 	A partir de vectores que tienen la impresión Pre y Post Orden se construye
*  				el árbol, es decir, se imprime la versión del árbol InOrden.
*********************************************************************************************/

#include <bits/stdc++.h>

using namespace std;

class Nodo {
public:
    int dato;
    Nodo *left;
    Nodo *right;
    Nodo(int x) {
        dato = x;
        left = right = nullptr;
    }
};

/*
	Función recursiva para construir el árbol desde los vectores PreOrden[] y PostOrden[]: 
		- Se ingresan los arreglos <impresiones> vectorPreOrden[] y vectorPostOrden[]
		- preIndice es el indicador sobre el vectorPreOrden[]
		- L_indice y H_indice son los índices del actual subtree en Post[]
*/
Nodo* constArbol_H(vector<int> &vectorPreOrden, vector<int> &vectorPostOrden, int &preIndice, 
					int L_indice, int H_indice, int cantidad) {
  
	int i;
    if (preIndice >= cantidad || L_indice > H_indice)
        return nullptr;
	/*
		El primer nodo vectorPreOrden[] es la raiz. preIndice++
	*/
    Nodo* root = new Nodo(vectorPreOrden[preIndice]);
    ++preIndice;
	/*
		Sí es sólo un elemento, no hay recursión
	*/
    if (L_indice == H_indice)
        return root;

	/*
		Se búsca el siguiente elemento de PreOrden[] en PostOrden[]	
	*/
    for (i = L_indice; i <= H_indice; ++i)
        if (vectorPreOrden[preIndice] == vectorPostOrden[i])
            break;

	/*
		Se usa el índice del elemento encontrado en PostOrden[]
		para dividir en 2 partes o subárboles: left y right.	
	*/
    if (i <= H_indice) {
        root->left = constArbol_H(vectorPreOrden, vectorPostOrden, preIndice, L_indice, i, cantidad);
        root->right = constArbol_H(vectorPreOrden, vectorPostOrden, preIndice, i + 1, H_indice - 1, cantidad);
    }

    return root;
}

/*
	Función para construir un Árbol Binario Completo, dado PreOrden y PostOrden
*/
Nodo *constructTree (vector<int> &vectorPreOrden, vector<int> &vectorPostOrden) {
    int preIndice = 0;
    int cantidad = vectorPreOrden.size();
    return constArbol_H(vectorPreOrden, vectorPostOrden, preIndice, 0, cantidad - 1, cantidad);
}

/*
	Función para impresión del arbol binario InOrden
*/
void impInOrden(Nodo *actual) {
    if (actual == nullptr)
        return;
    impInOrden(actual->left);
    printf(" %d  ", actual->dato);
    impInOrden(actual->right);
}

int main () {
  
    vector<int> vectorPreOrden = {7,3,2,5,9,11};
    vector<int> vectorPostOrden = {2,5,3,11,9,7};

    Nodo *root = constructTree(vectorPreOrden, vectorPostOrden);

	cout << "\n Impresión del Árbol Binario preOrden() Completo DADO: \n";
	for (auto i:vectorPreOrden)
		printf(" %d ", i); 	
	cout << "\n\n Impresión del Árbol Binario postOrden() Completo DADO: \n";
	for (auto i:vectorPostOrden)
		printf(" %d ", i); 	

	cout << "\n\n --------------------------------------------------\n";	
	cout << "SOLUCIÓN: Impresión del Árbol Binario InOrden(): \n\n";
    impInOrden(root);
	cout << "\n --------------------------------------------------\n";	
	cout << "\n\n";

    return 0;
}

