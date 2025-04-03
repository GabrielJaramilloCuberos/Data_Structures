//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include "NodoBinarioAVL.h"

using namespace std;

/**
 * Constructor por defecto del nodo
 */
template <class T>
NodoBinarioAVL<T>::NodoBinarioAVL(){
	this->hijoIzq=NULL;
	this->hijoDer=NULL;
}

/**
 * Destructor por defeto del nodo
 */
template <class T>
NodoBinarioAVL<T>::~NodoBinarioAVL(){
}

/**
 * Getter del atributo dato
 */
template <class T>
T& NodoBinarioAVL<T>::getDato(){
	return this->dato;
}

/**
 * Setter del atributo dato
 */
template <class T>
void NodoBinarioAVL<T>::setDato(T& val){
	this->dato=val;
	return;
}
/**
 * Getter del hijo izquierdo del nodo
 */
template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoIzq(){
	return this->hijoIzq;
}

/**
 * Getter del hijo derecho del nodo
 */
template <class T>
NodoBinarioAVL<T>* NodoBinarioAVL<T>::getHijoDer(){
	return this->hijoDer;
}

/**
 * Setter para el hijo izquierdo
 */
template <class T>
void NodoBinarioAVL<T>::setHijoIzq(NodoBinarioAVL<T>* izq){
	this->hijoIzq=izq;
	return;
}

/**
 * Setter para el hijo derecho
 */
template <class T>
void NodoBinarioAVL<T>::setHijoDer(NodoBinarioAVL<T>* der){
	this->hijoDer=der;
	return;
}
