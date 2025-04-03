//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include <iostream>
#include "nodo.h"
#include <queue>
using namespace std;


/**
 * Constructor por defecto
 */
template<class T>
Nodo<T>::Nodo()
{
    this->dato = T();
}

/**
 * Constructor con valor
 */
template<class T>
Nodo<T>::Nodo(T valor)
{
    this->dato = valor;
}

/**
 * * Destructor por defecto
 */
template<class T>
Nodo<T>::~Nodo() {
    for (auto& hijo : hijos) {
        delete hijo;
    }
}

/**
 * Getter de atributo dato
 */
template<class T>
T& Nodo<T>::obtenerDato()
{
    return this->dato;
}

/**
 * Setter de atrbuto dato
 */
template<class T>
void Nodo<T>::fijarDato(T& val)
{
    this->dato = val;
    return;
}

/**
 * Retorna la altura del arbol
 */
template<class T>
int Nodo<T>::altura() {
    if (hijos.empty()) return 0;
    int maxAltura = 0;
    for (auto& hijo : hijos) {
        maxAltura = max(maxAltura, hijo.altura());
    }
    return maxAltura + 1;
}

/**
 * Retorna la cantidad de nodos que poseen los subarboles
 */
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

/**
 * Elimina todos los nodos descendientes
 */
template<class T>
void Nodo<T>::limpiarLista() {
    for (int i = 0; i < hijos.size(); i++) {
        hijos[i]->limpiarLista();
        delete hijos[i];
    }
    hijos.clear();
}

/**
 * Añade un nodo a los descendientes 
 */
template<class T>
void Nodo<T>::adicionarDesc(T &val) {
    Nodo<T>* hijo = new Nodo<T>(val);
    hijos.push_back(hijo);
}

/**
 * Elimina un nodo especifico en los descendientes
 */
template<class T>
bool Nodo<T>::eliminarDesc(T &val) {
    for (int i = 0; i < hijos.size(); i++) {
        // Si encontramos el nodo a eliminar
        if (hijos[i]->obtenerDato() == val) {
            Nodo<T>* nodoAEliminar = hijos[i];
            hijos.erase(hijos.begin() + i);
            for(int j = 0; j<nodoAEliminar->hijos.size(); j++){
                hijos.insert(hijos.begin()+i, nodoAEliminar->hijos[j]);
            }
            
        }
    }


    return false;
}

/**
 * Retorna el apuntar al nodo con cierto valor
 */
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
/**
 * Imprime el recorrido preOrden
 */
template<class T>
void Nodo<T>:: preOrden()
{
	cout << "\t"<<this->obtenerDato() << endl;
	for(int i = 0; i < hijos.size() ; i++){
        hijos[i]->preOrden();
	}
	return;
}
/**
 * Imprime el recorrido posOrden
 */
template<class T>
void Nodo<T>::posOrden() {
    for (int i = 0; i < hijos.size(); i++) {
        hijos[i]->posOrden();
    }
    cout << "\t" << this->obtenerDato() << endl;
}
/**
 * Imprime el recorrido inOrden
 */
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

/**
 * Imprime el recorrido el arbol por niveles
 */
template<class T>
void Nodo<T>::nivelOrden(queue<Nodo*> &cola) {
    cola.push(this);
    for (int i = 0; i < this->hijos.size(); i++) {
        cola.push(this->hijos[i]);
    }
}




