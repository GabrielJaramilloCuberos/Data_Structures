#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H
#include "NodoBinario.h"

template <class T>

class ArbolBinario{
	protected:
		NodoBinario<T> *raiz;
	public:
		ArbolBinario();
		~ArbolBinario();
		NodoBinario<T>* getRaiz();
		bool esVacio();
		T& datoRaiz();
		int altura();
		int tamano();
		void insertar(T& val);
		int altura(NodoBinario<T> *inicio);
		int tamano(NodoBinario<T> *inicio);
		bool insertar(T& val,NodoBinario<T> *nodo);
		bool eliminar(T& val);
		bool buscar(T& val);
		void preOrden(NodoBinario<T> *inicio);
		void inOrden(NodoBinario<T> *inicio);
		void posOrden(NodoBinario<T> *inicio);
		void nivelOrden(NodoBinario<T> *inicio);
		void preOrden();
		void inOrden();
		void posOrden();
		void nivelOrden();
};

#include "ArbolBinario.hxx"

#endif //ARBOLBINARIO_H
