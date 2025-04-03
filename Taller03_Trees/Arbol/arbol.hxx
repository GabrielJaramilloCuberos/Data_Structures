//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include <iostream>
#include <queue>
#include "arbol.h"

using namespace std;
/**
 * Constructor por defecto
 */
template<class T>
Arbol<T>::Arbol() {
    this->raiz = nullptr;
}

/**
 * Constructor por valor
 */
template<class T>
Arbol<T>::Arbol(T val) {
    this->raiz = new Nodo<T>(val);
}

/**
 * Destructor por defecto
 */
template<class T>
Arbol<T>::~Arbol() {
    delete this->raiz;
}

/**
 * En caso que el arbol esté vacio va a retornar un falso, en caso contrario verdadero
 */
template<class T>
bool Arbol<T>:: esVacio()
{
    if(this->raiz==nullptr)
        return true;
    return false;
}

/**
 * Getter de la raiz;
 */
template<class T>
Nodo<T>* Arbol<T>:: obtenerRaiz()
{
    return this->raiz;
}

/**
 * Setter de la raiz
 */
template<class T>
void Arbol<T>::fijarRaiz(Nodo<T>* root)
{
    this->raiz = root;
}

/**
 * Imprime la altura total del arbol
 */

template<class T>
int Arbol<T>:: altura()
{
    if(this->raiz == nullptr ) return -1;
    return this->raiz->altura();
}

/**
 * Imprime cuantos nodos tiene en total el arbol
 */
template<class T>
int Arbol<T>:: tamano()
{
    return this->raiz->tamano();
}

/**
 * Inserta un nodo en el arbol
 */
template<class T>
bool Arbol<T>::insertarNodo(T padre, T val) {
    if (raiz == nullptr) return false;
    Nodo<T>* aux = raiz->buscar(padre);
    if (aux == nullptr) return false;
    aux->adicionarDesc(val);
    return true;
}
/**
 * Elimina un nodo de la lista de descendientes del padre
 */
template<class T>
bool Arbol<T>::eliminar(T &val)
{
    return raiz->eliminarDesc(val);
}

/**
 * Retorna el apuntador a un nodo que contenga cierto valor
 */
template<class T>
Nodo<T>* Arbol<T>::  buscar(T val)
{
    return this->raiz->buscar(val);
}

/**
 * Imprime el recorrido preOrden
 */
template<class T>
void Arbol<T>:: preOrden()
{
    this->raiz->preOrden();
}

/**
 * Imprime el recorrido inOrden
 */
template<class T>
void Arbol<T>:: inOrden()
{
    this->raiz->inOrden();
}

/**
 * Imprime el recorrido posOrden
 */
template<class T>
void Arbol<T>:: posOrden()
{
    this->raiz->posOrden();
}

/**
 * Imprime el recorrido del arbol por niveles
 */
template<class T>
void Arbol<T>:: nivelOrden()
{   
    queue<Nodo<T>*> cola;
    cola.push(this->raiz);
    this->raiz->nivelOrden(cola);
}
