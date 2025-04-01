#include "NodoExpresion.h"
#include <string>

using namespace std;
/**
 * Constructor por nodo
 */
NodoExpresion::NodoExpresion(){
	this->hijoIzq=NULL;
	this->hijoDer=NULL;
}
/**
 * Destructor por defecto
 */
NodoExpresion::~NodoExpresion(){
}
/**
 * Getter del atributo de nombre dato
 */
char NodoExpresion::getDato(){
	return this->dato;
}
/**
 * Setters del atributo de nombre dato
 */
void NodoExpresion::setDato(char val){
	this->dato=val;
	return;
}
/**
 * Getter de apuntador al hijo izquierdo del nodo
 */
NodoExpresion* NodoExpresion::getHijoIzq(){
	return this->hijoIzq;
}
/**
 * Getter de apuntador al hijo derecho del nodo
 */
NodoExpresion* NodoExpresion::getHijoDer(){
	return this->hijoDer;
}
/**
 * Setter del hijo izquierdo de un nodo
 */
void NodoExpresion::setHijoIzq(NodoExpresion* izq){
	this->hijoIzq=izq;
	return;
}
/**
 * Setter del atributo de nombre operando
 */
void NodoExpresion::setOperando(bool op){
	this->operando=op;
	return;
}
/**
 * Getter del atributo de nombre operano
 */
bool NodoExpresion::getOperando(){
	return this->operando;
}
/**
 * Setter para el hijo de derecho de un nodo
 */
void NodoExpresion::setHijoDer(NodoExpresion* der){
	this->hijoDer=der;
	return;
}
