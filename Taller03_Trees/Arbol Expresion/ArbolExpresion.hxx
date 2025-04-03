//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include "ArbolExpresion.h"
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/**
 * Constructor por defecto
 */
ArbolExpresion::ArbolExpresion(){
	this->raiz=NULL;
}
/**
 * Destructor por defecto
 */
ArbolExpresion::~ArbolExpresion(){
}
/**
 * Getter a la raiz del arbol de expresion
 */
NodoExpresion* ArbolExpresion::getRaiz(){
	return this->raiz;
}
/**
 * Setter de la raiz para el arbol
 */
void ArbolExpresion::setRaiz(NodoExpresion* nod){
	this->raiz=nod;
	return;
}
/**
 * Evalua una expresion contenida en el arbol
 */
int ArbolExpresion::evaluar(NodoExpresion* nodi){
	if(nodi->getHijoIzq()==NULL&&nodi->getHijoDer()==NULL){

		return (int)(nodi->getDato()-48);
	}else{
		int resultado=0;
		int izquierda=evaluar(nodi->getHijoIzq());

		int derecha=evaluar(nodi->getHijoDer());
		char operando=nodi->getDato();
		
		switch (operando) {
			case '+':
			resultado=izquierda+derecha;
			break;
			case '-':
			resultado=izquierda-derecha;
			break;
			case '*':
			resultado=izquierda*derecha;
			break;
			case '/':
			resultado=izquierda/derecha;
			break;
			default:
			resultado=izquierda+derecha;
			break;
		}
		return resultado;
	}

}
/**
 * Llena el arbol desde notacion PreFija
 */
void ArbolExpresion::llenarDesdePrefija(string &expresion){

	char cad[expresion.size()];
	strcpy(cad,expresion.c_str());

	stack<NodoExpresion* > miCola;
	NodoExpresion* n1;
	NodoExpresion* n2;
	NodoExpresion* n3;

	for(int i=strlen(cad)-1;i>=0;i--){

		if(!siOperando(cad[i])){

			n1=new NodoExpresion();
			n1->setDato(cad[i]);
			miCola.push(n1);
		}else{
			n1=new NodoExpresion();
			n1->setDato(cad[i]);

			n2=new NodoExpresion();
			n2=miCola.top();
			miCola.pop();
			n3=new NodoExpresion();
			n3=miCola.top();
			miCola.pop();

			n1->setHijoDer(n2);
			n1->setHijoIzq(n3);

			miCola.push(n1);
		}
	}
	n1=miCola.top();
	this->setRaiz(n1);
	miCola.pop();
}
/**
 * Llena el arbol desde notacion PosFja
 */
void ArbolExpresion::llenarDesdePosfija(string &expresion){

	char cad[expresion.size()];
	strcpy(cad,expresion.c_str());

	stack<NodoExpresion* > miCola;

	NodoExpresion* n1;
	NodoExpresion* n2;
	NodoExpresion* n3;

	for(int i=0;i<strlen(cad);i++){

		if(!siOperando(cad[i])){

			n1=new NodoExpresion();
			n1->setDato(cad[i]);
			miCola.push(n1);
		}else{
			n1=new NodoExpresion();
			n1->setDato(cad[i]);

			n2=new NodoExpresion();
			n2=miCola.top();
			miCola.pop();
			n3=new NodoExpresion();
			n3=miCola.top();
			miCola.pop();

			n1->setHijoDer(n2);
			n1->setHijoIzq(n3);

			miCola.push(n1);
		}
	}
	n1=miCola.top();
	this->setRaiz(n1);
	miCola.pop();
}
/**
 * Imprime el recorrido del arbol usando la notacion PreFija
 */
void ArbolExpresion::obtenerPrefija(NodoExpresion* inicio){
	if(inicio==NULL){
		return;
	}else{
		cout<<inicio->getDato()<<" ";
		this->obtenerPrefija(inicio->getHijoIzq());
		this->obtenerPrefija(inicio->getHijoDer());
	}
}
/**
 * Imprime el recorrido del arbol usando la notacion Infija
 */
void ArbolExpresion::obtenerInfija(NodoExpresion* inicio){
	if(this->raiz!=NULL){
		if(inicio->getHijoIzq()!=NULL){
			obtenerInfija(inicio->getHijoIzq());
		}
		cout << inicio->getDato()<<" ";
		if(inicio->getHijoDer()!=NULL){
			obtenerInfija(inicio->getHijoDer());
		}
	}else{
		cout << "El arbol esta vacio" << '\n';
	}
}
/**
 * Imprime el recorrido del arobl usando la notacio Posfija
 */
void ArbolExpresion::obtenerPosfija(NodoExpresion* inicio){
	if(inicio==NULL){
		return;
	}else{
		this->obtenerPosfija(inicio->getHijoIzq());
		this->obtenerPosfija(inicio->getHijoDer());
		cout<<inicio->getDato()<<" ";
	}
}
/**
 * Retorna si uno de los operandos es aceptabl dentro el arbol
 */
bool ArbolExpresion::siOperando(char car){
	if(car=='+'||car=='-'||car=='/'||car=='*'||car=='%'){
		return true;
	}else{
		return false;
	}
}
