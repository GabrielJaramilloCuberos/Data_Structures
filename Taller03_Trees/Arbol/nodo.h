#ifndef __NODO__H__
#define __NODO__H__

using namespace std;
#include <queue>
#include <vector>

template< class T >
class Nodo{
  protected:
    T dato;
    vector<Nodo<T>*> hijos;

  public:
  	Nodo();
  	Nodo(T valor);
    ~Nodo();
    T& obtenerDato();
    void fijarDato(T& val);
    vector<Nodo*> obtenerDesc();
    void fijarDesc(vector<Nodo*> &desc);
    void adicionarDesc(T& val);
    bool eliminarDesc(T &val);
    Nodo* buscarDesc(T val);
    void limpiarLista();
    int numDesc();
    void insertarNodo(T padre, T val);
    void eliminarNodo(T& val);
    Nodo* buscar(T val);
    int altura();
  	int tamano();
    void preOrden();
    void posOrden();
    void inOrden();
    void nivelOrden(queue<Nodo*> &cola);
};

#include "nodo.hxx"
#endif
