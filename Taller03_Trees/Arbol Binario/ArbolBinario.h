//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#ifndef __ARBOLBINARIO__H__
#define __ARBOLBINARIO__H__

#include "NodoBinario.h"

using namespace std;

template<class T>
class ArbolBinario {
  protected:
    NodoBinario<T> *raiz;
public:
	  ArbolBinario();
    NodoBinario<T>* getRaiz();
    bool esVacio();
    T& datoRaiz();
    int altura();
    int tamano();
    void insertar(T& val);
    int altura(NodoBinario<T>* nodo);
    int tamano(NodoBinario<T>* nodo);
    void insertar(NodoBinario<T>* valor, NodoBinario<T>* subarbol, char &pos);
    bool eliminar(T& val);
    NodoBinario<T>*  buscar(T& val);
    NodoBinario<T>* buscarE(T& val);
    void preOrden(NodoBinario<T>* nodo);
    void inOrden(NodoBinario<T>* nodo);
    void posOrden(NodoBinario<T>* nodo);
    void nivelOrden(NodoBinario<T>* nodo);
    void preOrden();
    void inOrden();
    void posOrden();
    void nivelOrden();
};

#include "ArbolBinario.hxx"
#endif
