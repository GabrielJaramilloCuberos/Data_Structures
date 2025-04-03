//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include "quadtree.h"

using namespace std;

template<class T>
Arbol<T>::Arbol()
{
    Nodo<T>* root = new Nodo<T>();
}

template<class T>
Arbol<T>::Arbol(pair<T,T> val)
{
    Nodo<T>* root =new  Nodo<T>(val);
    this->raiz=root;
}


template <class T>
void Arbol<T>::setMaximo(int ma){
    this->maximo = ma;
}

template <class T>
int Arbol<T>::getMaximo(){
    return this->maximo;
}

/*
template<class T>
Arbol<T>::~Arbol()
{
    delete(this->raiz);
}
*/
template<class T>
bool Arbol<T>:: esVacio()
{
    if(this->raiz==NULL)
        return true;
    return false;
}

template<class T>
pair<T,T> Arbol<T>:: obtenerRaiz()
{
    return this->raiz->obtenerDato();
}

template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root)
{
    this->raiz = root;
}

template<class T>
int Arbol<T>:: altura()
{
    return this->raiz->altura();
}

template<class T>
int Arbol<T>:: tamano()
{
    return this->raiz->tamano();
}

template<class T>
void Arbol<T>:: insertar(pair<T,T> val, int ma)
{
    this->raiz->insertar(val, ma);
}

/*
template<class T>
bool Arbol<T>:: eliminar(T val)
{
    return this->raiz->eliminar(val);
}
*/
template<class T>
Nodo<T>* Arbol<T>::  buscar(pair<T,T> val)
{
    return this->raiz->buscar(val);
}

template<class T>
void Arbol<T>:: preOrden()
{
    this->raiz->preOrden();
}


template<class T>
void Arbol<T>:: posOrden()
{
    this->raiz->posOrden();
}

