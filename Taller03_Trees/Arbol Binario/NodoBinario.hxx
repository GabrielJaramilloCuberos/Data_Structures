//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include "NodoBinario.h"
#include <bits/stdc++.h>

using namespace std;
/**
 * Constructor por defecto 
 */
template<class T>
NodoBinario<T>::NodoBinario()
{
    this->hijoIzq=NULL;
    this->hijoDer=NULL;
}
/**
 * Getter del atributo de nombre dato
 */
template<class T>
T& NodoBinario<T>::obtenerDato()
{
    return this->dato;
}
/**
 * Setter del atributo de nombre dato
 */
template<class T>
void NodoBinario<T>::fijarDato(T& val)
{
    this->dato = val;
}
/**
 * Getter del apuntador al hijo izquierdo
 */
template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoIzq()
{
    return this->hijoIzq;
}
/**
 * Getter del apuntador al hijo derecho
 */
template<class T>
NodoBinario<T>* NodoBinario<T>::obtenerHijoDer()
{
    return this->hijoDer;
}
/**
 * Setter del hijo izquierdo del nodo
 */
template<class T>
void NodoBinario<T>::fijarHijoIzq(NodoBinario<T> *izq)
{
    this->hijoIzq = izq;
}
/**
 * Setter del hijo derecho del nodo
 */
template<class T>
void NodoBinario<T>::fijarHijoDer(NodoBinario<T> *der)
{
    this->hijoDer = der;
}
/**
 * Rtorna un entero que representa la altura del nodo
 */
template<class T>
int NodoBinario<T>::altura()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	if(this->hijoIzq==NULL)
		return this->hijoDer->altura();
	else if(this->hijoDer==NULL)
		return this->hijoIzq->altura();


	return max(this->hijoIzq->altura() , this->hijoDer->altura());
}

/**
 * Retorna un entero con la cantidad total de nodos
 */
template<class T>
int NodoBinario<T>::tamano()
{
	if(this->hijoIzq==NULL && this->hijoDer == NULL)
	{
		return 1;
	}
	if(this->hijoIzq==NULL)
		return this->hijoDer->tamano() +1 ;
	else if(this->hijoDer==NULL)
		return this->hijoIzq->tamano() +1 ;


	return this->hijoIzq->tamano() + this->hijoDer->tamano() +1 ;
}

/**
 * Inserta un nuevo nodo al arbol
 */
template<class T>
void NodoBinario<T>:: insertar(T& val)
{

	if(val > this->obtenerDato()){
		if(this->hijoDer==NULL)
		{
			NodoBinario* nuevo= new NodoBinario();
			nuevo->fijarDato(val);
			this->fijarHijoDer(nuevo);
		}
		else
		{
			this->hijoDer->insertar(val);
		}
	}

	if(val < this->obtenerDato()){
		if(this->hijoIzq==NULL)
		{
			NodoBinario* nuevo= new NodoBinario();
			nuevo->fijarDato(val);
			this->fijarHijoIzq(nuevo);
		}
		else
		{
			this->hijoIzq->insertar(val);
		}
	}

}

/**
 * Busca en el arbol un nodo con el valor correspondiente y devuelve un apuntador hacia el
 */
template<class T>
NodoBinario<T>* NodoBinario<T>:: buscar(T& val)
{
	if(this->obtenerDato()==val){
		return this;
	}

	if(val < this-> obtenerDato()){
        if(this->hijoIzq != NULL)
            return this->hijoIzq->buscar(val);
        else
            return NULL;
	}
	else{
        if(this->hijoDer != NULL)
            return this->hijoDer->buscar(val);
        else
            return NULL;
	}
}

/**
 * Retorna un apuntador al nodo que mas se encuentra a la derecha
 */
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_der()
{
    if(this->hijoDer != NULL)
        return this->hijoDer->extremoDer();
    else
        return this;
}
/**
 * Retorna un apuntador al nodo que se encuentra mas a la izquierda
 */
template<class T>
NodoBinario<T>* NodoBinario<T>::extremo_izq()
{
    if(this->hijoIzq != NULL)
        return this->hijoIzq->extremo_izq();
    else
        return this;
}

/**
 * Imprime el recorrido preOrden del arbol
 */
template<class T>
void NodoBinario<T>:: preOrden()
{
	cout << "\t"<<this->obtenerDato() << endl;
	if(this->hijoIzq != NULL)
		this->hijoIzq->preOrden();
	if(this->hijoDer != NULL)
		this->hijoDer->preOrden();
	return;
}

/**
 * Imprime el recorrido inOrden del arbol
 */
template<class T>
void NodoBinario<T>:: inOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->inOrden();

	cout << "\t"<<this->obtenerDato() << endl;

	if(this->hijoDer != NULL)
		this->hijoDer->inOrden();
	return;

}


/**
 * Imprime el recorrido posOrden del arbol
 */
template<class T>
void NodoBinario<T>:: posOrden()
{
	if(this->hijoIzq != NULL)
		this->hijoIzq->posOrden();

	if(this->hijoDer != NULL)
		this->hijoDer->posOrden();

	cout << "\t"<<this->obtenerDato() << endl;
	return;

}

/**
 * Imprime el recorrido del arbol por niveles
 */
template<class T>
void NodoBinario<T>:: nivelOrden()
{
	queue<NodoBinario*> cola;
	cola.push(this);
	while(!cola.empty()){
		cout<<"\t"<<cola.front()->obtenerDato()<<endl;
		if(cola.front()->hijoIzq != NULL){
			cola.push(cola.front()->hijoIzq);
		}

		if(cola.front()->hijoDer != NULL){
			cola.push(cola.front()->hijoDer);
		}
		cola.pop();
	}
}




