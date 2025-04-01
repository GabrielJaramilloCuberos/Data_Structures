#include "ArbolBinario.h"
#include "NodoBinario.h"

using namespace std;

/**
 * Constructor por defecto
 */
template<class T>
ArbolBinario<T>::ArbolBinario()
{
    this->raiz=NULL;
}

/**
 * Retorna un booleano, en caso que el arbol sea nuo devuelve true, caso contrario false
 */
template<class T>
bool ArbolBinario<T>::esVacio()
{
    if(this==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
 * Getter del dato de la raiz
 */
template<class T>
T& ArbolBinario<T>::datoRaiz()
{
    return this->raiz->obtenerDato();
}
/**
 * Retorna la altura total del arbol
 */
template<class T>
int ArbolBinario<T>::altura()
{
    return this->raiz->altura();
}
/**
 * Retorna la cantidad total de nodos en el arbol
 */
template<class T>
int ArbolBinario<T>::tamano()
{
    return this->raiz->tamano() ;
}
/**
 * Inserta un nodo
 */
template<class T>
void ArbolBinario<T>::insertar(T& val)
{
    if(this->raiz!=nullptr)
    {
        this->raiz->insertar(val);
    }
    else
    {
        NodoBinario<T>* nuevo= new NodoBinario<T>();
        nuevo->fijarDato(val);
        this->raiz=nuevo;
    }


}

/**
 * Eliminacion de un nodo del arbol AVL
 */

template<class T>
bool ArbolBinario<T>::eliminar(T& val)
{ 
	//Nodo* borrar = this->buscar(val);
	NodoBinario<T>* borrar = this->buscar(val);
    if(borrar == NULL)
        return false;

    if(borrar->hijoIzq != NULL)
    {
        //Nodo* nuevo = borrar->hijoIzq->extremo_der();
		NodoBinario<T>* nuevo = borrar->hijoIzq->extremo_der();
        borrar->fijarDato(nuevo->obtenerDato());
		delete(nuevo);
    }
    else if(borrar->hijoDer != NULL)
    {
		
        //Nodo* nuevo = borrar->hijoDer->extremo_izq();
		NodoBinario<T>* nuevo = borrar->hijoDer->extremo_izq();
        borrar->fijarDato(nuevo->obtenerDato());
		delete(nuevo);
    }
    return true;
}

/**
 * Retorna un apuntador a un nodo que contenga el valor correspondiente
 */

template<class T>
NodoBinario<T>* ArbolBinario<T>::buscar(T& val)
{
    return this->raiz->buscar(val);
}
/**
 * Imprime el recorrido preOrden del arbol
 */
template<class T>
void ArbolBinario<T>::preOrden()
{
    this->raiz->preOrden();
}
/**
 * Imprime el recorrido inOrden del arbol
 */
template<class T>
void ArbolBinario<T>::inOrden()
{
    this->raiz->inOrden();
}
/**
 * Imprime el recorrido posOrden del arbol
 */
template<class T>
void ArbolBinario<T>::posOrden()
{
    this->raiz->posOrden();
}
/**
 * Imprime el recorrido por niveles del arbol AVL
 */
template<class T>
void ArbolBinario<T>::nivelOrden()
{
    this->raiz->nivelOrden();
}

