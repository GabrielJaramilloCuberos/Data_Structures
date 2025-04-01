#include <iostream>
#include <queue>
#include "arbol.h"

using namespace std;

template<class T>
Arbol<T>::Arbol() {
    this->raiz = nullptr;
}

template<class T>
Arbol<T>::Arbol(T val) {
    this->raiz = new Nodo<T>(val);
}

template<class T>
Arbol<T>::~Arbol() {
    delete this->raiz;
}

template<class T>
bool Arbol<T>:: esVacio()
{
    if(this->raiz==nullptr)
        return true;
    return false;
}

template<class T>
Nodo<T>* Arbol<T>:: obtenerRaiz()
{
    return this->raiz;
}

template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root)
{
    this->raiz = root;
}

template<class T>
int Arbol<T>:: altura()
{
    if(this->raiz == nullptr ) return -1;
    return this->raiz->altura();
}

template<class T>
int Arbol<T>:: tamano()
{
    return this->raiz->tamano();
}

template<class T>
bool Arbol<T>::insertarNodo(T padre, T val) {
    if (raiz == nullptr) return false;
    Nodo<T>* aux = raiz->buscar(padre);
    if (aux == nullptr) return false;
    aux->adicionarDesc(val);
    return true;
}

template<class T>
bool Arbol<T>::eliminar(T &val)
{
    return raiz->eliminarDesc(val);
}

template<class T>
Nodo<T>* Arbol<T>::  buscar(T val)
{
    return this->raiz->buscar(val);
}

template<class T>
void Arbol<T>:: preOrden()
{
    this->raiz->preOrden();
}

template<class T>
void Arbol<T>:: inOrden()
{
    this->raiz->inOrden();
}

template<class T>
void Arbol<T>:: posOrden()
{
    this->raiz->posOrden();
}

template<class T>
void Arbol<T>:: nivelOrden()
{   
    queue<Nodo<T>*> cola;
    cola.push(this->raiz);
    this->raiz->nivelOrden(cola);
}
