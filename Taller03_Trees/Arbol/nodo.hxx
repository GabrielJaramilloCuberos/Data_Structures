#include <iostream>
#include "nodo.h"
#include <queue>
using namespace std;

template<class T>
Nodo<T>::Nodo()
{
    this->dato = T();
}

template<class T>
Nodo<T>::Nodo(T valor)
{
    this->dato = valor;
}

template<class T>
Nodo<T>::~Nodo() {
    for (auto& hijo : hijos) {
        delete hijo;
    }
}

template<class T>
T& Nodo<T>::obtenerDato()
{
    return this->dato;
}

template<class T>
void Nodo<T>::fijarDato(T& val)
{
    this->dato = val;
    return;
}


template<class T>
int Nodo<T>::altura() {
    if (hijos.empty()) return 0;
    int maxAltura = 0;
    for (auto& hijo : hijos) {
        maxAltura = max(maxAltura, hijo.altura());
    }
    return maxAltura + 1;
}


template<class T>
int Nodo<T>::tamano()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	int conta = 0;
	for( int i = 0; i<hijos.size() ; ++i){
        conta+=hijos[i].tamano();
	}
	return conta+1;
}


template<class T>
void Nodo<T>::limpiarLista() {
    for (int i = 0; i < hijos.size(); i++) {
        hijos[i]->limpiarLista();
        delete hijos[i];
    }
    hijos.clear();
}



template<class T>
void Nodo<T>::adicionarDesc(T &val) {
    Nodo<T>* hijo = new Nodo<T>(val);
    hijos.push_back(hijo);
}


template<class T>
bool Nodo<T>:: eliminarDesc(T &val){
    bool correr=false;
    for(int i=0;i<hijos.size();i++){
        if(correr){
            hijos[i-1]=hijos[i];
        }
        if(hijos[i] == val)
            correr=true;
    }

    if(!correr)
        return false;
    hijos.pop_back();
    return true;
}


template<class T>
Nodo<T>* Nodo<T>:: buscar(T val){
    if(dato == val)
        return this;
    if(hijos.size() == 0)
        return nullptr;
    Nodo<T>* aux;
    for(int i = 0; i<hijos.size() ; i++){
        aux = hijos[i]->buscar(val);
        if(aux!=nullptr)
            return aux;
    }

    return nullptr;

}

template<class T>
void Nodo<T>:: preOrden()
{
	cout << "\t"<<this->obtenerDato() << endl;
	for(int i = 0; i < hijos.size() ; i++){
        hijos[i]->preOrden();
	}
	return;
}

template<class T>
void Nodo<T>:: posOrden()
{
	for(int i = 0; i < hijos.size() ; i++){
        hijos[i]->preOrden();
	}
	return;

	cout << "\t"<<this->obtenerDato() << endl;
	return;

}
template <class T>
void Nodo<T>::inOrden() {
    int mitad = hijos.size() / 2;

    for (int i = 0; i < mitad; i++) {
        hijos[i]->inOrden();
    }
    
    cout << "\t" << this->obtenerDato() << endl;

    for (int i = mitad; i < hijos.size(); i++) {
        hijos[i]->inOrden();
    }

    return;
}

template<class T>
void Nodo<T>::nivelOrden(queue<Nodo*> &cola) {
    cola.push(this);
    for (int i = 0; i < this->hijos.size(); i++) {
        cola.push(this->hijos[i]);
    }
}




