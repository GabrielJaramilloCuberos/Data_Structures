#ifndef __ARBOL__H__
#define __ARBOL__H__

#include "nodo.h"

using namespace std;

template<class T>
class Arbol {
	protected:
    	Nodo<T> *raiz;
	public:
		Arbol();
		Arbol(T val);
		~Arbol();
	    bool esVacio();
   	 	T obtenerRaiz();
   	 	void fijarRaiz(Nodo<T>* root);
   	 	bool insertarNodo(T padre, T val);
		bool eliminar(T& val);
		Nodo<T>*  buscar(T val);
    	int altura();
	    int tamano();
    	void preOrden();
		void posOrden();
    	void inOrden();
    	void nivelOrden();
};

#include "arbol.hxx"
#endif
