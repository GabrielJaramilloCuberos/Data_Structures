//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include "nodo.h"
#include <bits/stdc++.h>

using namespace std;

/**
 * Constructor por defecto
 */
template<class T>
Nodo<T>::Nodo()
{
    this->dato = {-1,-1};
    this->NW = NULL;
    this->NE = NULL;
    this->SW = NULL;
    this->SE = NULL;
}

/**
 * Constructor con valor 
 */
template<class T>
Nodo<T>::Nodo(pair<T,T> val)
{
    this->dato = val;
    this->NW = NULL;
    this->NE = NULL;
    this->SW = NULL;
    this->SE = NULL;
}

/**
 * Getter del atributo de nombre dato 
 */
template<class T>
pair<T,T> Nodo<T>::obtenerDato()
{
    return this->dato;
}
/**
 * Setter del atributo de nombre dato
 */
template<class T>
void Nodo<T>::fijarDato(pair<T,T> val)
{
    this->dato = val;
    return;
}

/**
 * Retorna un entero que indica la altura del nodo
 */
template<class T>
int Nodo<T>::altura()
{
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL )
        return 1;

    int mayor=0,actual;
    if(NW != NULL)
    {
        actual= this->NW->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
    if(NE != NULL)
    {
        actual = this->NE->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
    if(SW != NULL)
    {
        actual = this->SW->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
    if(SE != NULL)
    {
        actual = this->SE->altura()+1;
        if(actual>mayor)
            mayor=actual;
    }
}

/**
 * Retorna la cantidad total de nodos
 */
template<class T>
int Nodo<T>::tamano()
{
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL )
        return 1;

    int cont=0;
    if(NW != NULL)
    {
        cont+= this->NW->altura()+1;
    }
    if(NE != NULL)
    {
        cont+= this->NE->altura()+1;
    }
    if(SW != NULL)
    {
        cont+= this->SW->altura()+1;
    }
    if(SE != NULL)
    {
        cont+= this->SE->altura()+1;
    }
    return cont;
}

/**
 * inserta un nodo al quadtree
 */
template<class T>
void Nodo<T>:: insertar(pair<T,T> val, int ma)
{
    if(this->dato.first == -1 && this->dato.second == -1){
        this->dato.first = (val.first)/2;
        this->dato.second = (val.second)/2;
        return;
    }

    /*Norte*/
    if(this->dato.first < val.first)
    {
        if(this->dato.second < val.second)
        {
            if(this->NE!= NULL)
            {
                this->NE->insertar(val, ma);
            }
            else
            {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->NE = nuevo;
            }
        }
        else
        {
            if(this->SE!= NULL)
            {
                this->SE->insertar(val, ma);
            }
            else
            {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->SE = nuevo;
            }
        }
    }

    /*Sur*/
    if(this->dato.first > val.first )
    {
        if(this->dato.second < val.second)
        {
            if(this->NW!= NULL)
            {
                this->NW->insertar(val, ma);
            }
            else
            {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->NW = nuevo;
            }
        }
        else
        {
            if(this->SW!= NULL)
            {
                this->SW->insertar(val, ma);
            }
            else
            {
                Nodo<T>* nuevo = new Nodo();
                nuevo->fijarDato(val);
                this->SW = nuevo;
            }
        }
    }
}

/**
 * Busca un nodo determinado con base a su valor
 */
template<class T>
Nodo<T>* Nodo<T>:: buscar(pair<T,T> val)
{
    if(this->dato == val)
        return this;
    if(NW == NULL && NE == NULL && SW == NULL && SE == NULL )
        return NULL;

    if(this->dato.first < val.first)
    {
        if(this->dato.second < val.second)
        {
            if(this->NE!= NULL)
            {
                return this->NE->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            if(this->SE!= NULL)
            {
                return this->SE->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
    }

    /*Sur*/
    if(this->dato.first > val.first )
    {
        if(this->dato.second < val.second)
        {
            if(this->NW!= NULL)
            {
                return this->NW->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
        else
        {
            if(this->SW!= NULL)
            {
                return this->SW->buscar(val);
            }
            else
            {
                return NULL;
            }
        }
    }

    return NULL;

}

/**
 * Imprime el arbol usando un recorrido preOrden
 */
template<class T>
void Nodo<T>:: preOrden()
{
    cout << "("<<this->dato.first<<','<<this->dato.second <<")"<< endl;
    if(this->NW !=NULL)
        this->NW->preOrden();
    if(this->NE !=NULL)
        this->NE->preOrden();
    if(this->SW !=NULL)
        this->SW->preOrden();
    if(this->SE !=NULL)
        this->SE->preOrden();

    return;
}



/**
 * Imprime el arbol usando el recorrido posOrden
 */

template<class T>
void Nodo<T>:: posOrden()
{
    if(this->NW !=NULL)
        this->NW->preOrden();
    if(this->NE !=NULL)
        this->NE->preOrden();
    if(this->SW !=NULL)
        this->SW->preOrden();
    if(this->SE !=NULL)
        this->SE->preOrden();

    cout << "("<<this->dato.first<<','<<this->dato.second <<")"<< endl;
    return;

}




