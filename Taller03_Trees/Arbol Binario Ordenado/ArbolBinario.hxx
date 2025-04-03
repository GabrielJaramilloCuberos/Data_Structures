//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include "ArbolBinario.h"
#include <iostream>
#include <queue>
using namespace std;
/**
 * Constructor por defecto
 */
template <class T>
ArbolBinario<T>::ArbolBinario(){
	this->raiz=new NodoBinario<T>;
}
/**
 * Destructor por defecto
 */
template <class T>
ArbolBinario<T>::~ArbolBinario(){
}

/**
 * Retorna un booleano verdadero en caso de ser nula la raiz, falso si contiene valor
 */
template <class T>
bool ArbolBinario<T>::esVacio(){
	if(this->raiz==NULL){
		return true;
	}
	return false;
}
/**
 * Getter del dato de la raiz
 */
template <class T>
T& ArbolBinario<T>::datoRaiz(){
	return (this->raiz).getDato();
}
/**
 * Retorna un entero co la altura total del arbol
 */
template <class T>
int ArbolBinario<T>::altura(NodoBinario<T> *inicio){
	int alturaIzq=0;
	int alturaDer=0;
	if(inicio==NULL){
		return -1;
	}
	if(inicio->getHijoIzq()==NULL && inicio->getHijoDer()==NULL){
		return 0;
	}
	if(inicio->getHijoIzq()!=NULL){
		alturaIzq+=altura(inicio->gethijoIzq())+1;
	}
	if(inicio->getHijoDer()!=NULL){
		alturaDer+=altura(inicio->gethijoDer())+1;
	}
	if(alturaIzq > alturaDer){
		return (alturaIzq);
	}else{
		return (alturaDer);
	}
}

/**
 * Retorna un entero que representa la cantidad total de nodos
 */
template <class T>
int ArbolBinario<T>::tamano(NodoBinario<T> *inicio){
	int nodosIzq=0;
	int nodosDer=0;
	if(inicio==NULL){
		return 0;
	}
	if(inicio->getHijoIzq()==NULL && inicio->getHijoDer()==NULL){
		return 1;
	}
	if(inicio->getHijoIzq()!=NULL){
		nodosIzq+=tamano(inicio->gethijoIzq());
	}
	if(inicio->getHijoDer()!=NULL){
		nodosDer+=tamano(inicio->gethijoDer());
	}
	return nodosIzq+nodosDer+1;
}
/**
 * Inserta un nuevo nodo al arbol AVL
 */
template <class T>
bool ArbolBinario<T>::insertar(T& val, NodoBinario<T> *nod){

	//crea nodo a insertar
	NodoBinario<T> *nodito = new NodoBinario<T>();
	nodito->setDato(val);

	// inserta en la raiz si no existia antes
	if(this->raiz== NULL)
		{
			this->raiz=nodito;
			return true;
		}
	// empieza recorrer por la izquiera si el valor es menor
	else if(val<nod->getDato())
	{
		//recorre los hijos de los hijos del hijo izquerdo
		if(nod->getHijoIzq!=NULL)
		{
			insertar(val,nod->getHijoIzq);
		}
		// cuando ya no exite un hijo izquierdo inserta
		else
		{
			nod->setHijoDer(nodito);
			return true;
		}
	}
	else if(val>nod->getDato())
	{
		//recorre los hijos de los hijos del hijo derecho
		if(nod->getHijoDer()!=NULL)
		{
			insertar(val,nod->getHijoDer());
		}
		// cuando ya no exite un hijo izquierdo inserta
		else
		{
			nod->setHijoDer(nodito);
			return true;
		}
	}
	// si nunca inserto en hijo izquierdo o derecho , es porque ya existe
	else
	{
		return false;
	}
}

/**
 * Imprime el recorrido inOrden del arbol
 */
template <class T>
void ArbolBinario<T>::inOrden(NodoBinario<T> *inicio){
	if(inicio->getHijoIzq() != nullptr){
		inOrden(inicio->getHijoIzq());
	}

	cout << "\t" << inicio->getDato() << endl;

	if(inicio->getHijoDer() != nullptr){
		inOrden(inicio->getHijoDer());
	}
	return;
}
/**
 * Imprime el recorrido preOrden del arbol
 */
template <class T>
void ArbolBinario<T>::preOrden(NodoBinario<T> *inicio){

	cout << "\t" << inicio->getDato() << endl;

	if(inicio->getHijoIzq() != nullptr){
		preOrden(inicio->getHijoIzq());
	}


	if(inicio->getHijoDer() != nullptr){
		preOrden(inicio->getHijoDer());
	}
	return;
}
/**
 * Imprime el recorrido posOrden del arbol
 */
template <class T>
void ArbolBinario<T>::posOrden(NodoBinario<T> *inicio){

	

	if(inicio->getHijoIzq() != nullptr){
		inOrden(inicio->getHijoIzq());
	}


	if(inicio->getHijoDer() != nullptr){
		inOrden(inicio->getHijoDer());
	}

	cout << "\t" << inicio->getDato() << endl;
	return;
}
/**
 * Getter de la raiz
 */
template <class T>
NodoBinario<T>* ArbolBinario<T>::getRaiz(){
	return this->raiz;
}
/**
 * Inserta un nuevo nodo con un valor al arbol
 */
template <class T>
void ArbolBinario<T>::insertar(T& val){
	NodoBinario<T> *raiz = getRaiz();
	NodoBinario<T> *aux = new NodoBinario<T>;
	aux->setDato(val);
	#pragma warning
	if(raiz->getDato() == NULL){
		raiz->setDato(val);
		return;
	}
	while(true){
		if(val < raiz->getDato()){
			if( raiz->getHijoIzq() == nullptr){
				raiz->setHijoIzq(aux);
				return;
			}else{
				raiz = raiz->getHijoIzq();
			}
		}else{
			if(raiz->getHijoDer() == nullptr){
				raiz->setHijoDer(aux);
				return;
			}else{
				raiz = raiz->getHijoDer();
			}
		}
	}
}

/**
 * Imprime el recorrido del arbol por niveles
 */
template <class T>
void ArbolBinario<T>::nivelOrden(NodoBinario<T>* inicio) {
    if (inicio == nullptr) {
        return;
    }

    queue<NodoBinario<T>*> cola;
    cola.push(inicio);

    while (!cola.empty()) {
        NodoBinario<T>* actual = cola.front();
        cola.pop();

		cout << "\t" << actual->getDato() << endl;

        if (actual->getHijoIzq() != nullptr) {
            cola.push(actual->getHijoIzq());
        }
        if (actual->getHijoDer() != nullptr) {
            cola.push(actual->getHijoDer());
        }
    }
}
