#include "NodoBinario.h"
#include <iostream>
using namespace std;
template <class T>
/**
 * Constructor por defecto
 */
NodoBinario<T>::NodoBinario(){
	this->hijoIzq=NULL;
	this->hijoDer=NULL;
}

/**
 * Destructor por defecto
 */
template <class T>
NodoBinario<T>::~NodoBinario(){
}

/**
 * Getter del atributo de nombre dato
 */
template <class T>
T& NodoBinario<T>::getDato(){
	return this->dato;
}

/**
 * Getter del atributo de nombre dato
 */
template <class T>
void NodoBinario<T>::setDato(T& val){
	this->dato = val;
	return;
}
/**
 * Getter del apuntador al hijo izquierdo del nodo
 */
template <class T>
NodoBinario<T>* NodoBinario<T>::getHijoIzq(){
	return this->hijoIzq;
}
/**
 * Getter del apuntador al hijo derecho del nodo
 */
template <class T>
NodoBinario<T>* NodoBinario<T>::getHijoDer(){
	return this->hijoDer;
}
/**
 * Setter del hijo izquierdo del nodo
 */
template <class T>
void NodoBinario<T>::setHijoIzq(NodoBinario<T>* izq){
	this->hijoIzq=izq;
	return;
}
/**
 * Setter del hijo derecho del nodo
 */
template <class T>
void NodoBinario<T>::setHijoDer(NodoBinario<T>* der){
	this->hijoDer=der;
	return;
}
