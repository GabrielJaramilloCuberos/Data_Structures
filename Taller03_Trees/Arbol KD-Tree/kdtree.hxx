#include "kdtree.h"
#include "kdnodo.h"
#include <vector>
using namespace std;

/**
 * Constructor por defecto
 */
template<class T>
kdtree<T>::kdtree(){
	this->raiz=NULL;
}

/**
 * Retorna un booleano verdadero en caso que el arbol no tenga raiz o esta sea nula, en caso contrario retorna verdadero
 */
template<class T>
bool kdtree<T>::esVacio()
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
 * Getter del atributo dato de la raiz
 */
template<class T>
T& kdtree<T>::datoRaiz()
{
   return this->raiz->obtenerDato();
}

/**
 * Retorna la altura del nodo raiz
 */
template<class T>
int kdtree<T>::altura()
{
   return this->raiz->altura();
}

/**
 * Retorna la cantidad de nodos totales presentes en el arbol
 */
template<class T>
int kdtree<T>::tamano()
{
	return this->raiz->tamano() ;
}

/**
 * Inserta un nuevo nodo al arbol
 */
template<class T>
void kdtree<T>::insertar(vector<T> val)
{	
	cout<<"en la raiz hay: "<<this->raiz<<endl;
	if(this->raiz!=nullptr){
		this->raiz->insertar(val);
	}
	else{
		kdnodo<T>* nuevo= new kdnodo<T>();
		nuevo->fijarDato(val);
		this->raiz=nuevo;
	}


}

/**
 * Elimina un nodo del arbol
 */
template<class T>
bool kdtree<T>::eliminar(T& val)
{

}
/**
 * Busca dentro del arbol el nodo con el correspondiente valor
 */
template<class T>
kdnodo<T>* kdtree<T>::buscar(T& val)
{
	return this->raiz->buscar(val);
}

/**
 * Realiza el recorrido preOrden del arbol
 */
template<class T>
void kdtree<T>::preOrden()
{
	this->raiz->preOrden();
}

/**
 * Realiza el recorrido inOrden del arbol
 */
template<class T>
void kdtree<T>::inOrden()
{
	this->raiz->inOrden();
}

/**
 * Realiza el recorrido posOrden del arbol
 */
template<class T>
void kdtree<T>::posOrden()
{
	this->raiz->posOrden();
}

/**
 * Realiza el recorrido del arbol por niveles
 */
template<class T>
void kdtree<T>::nivelOrden()
{
	this->raiz->nivelOrden();
}

/**
 * Obtiene el nodo con el valor maximo entre todos
 */
template<class T>
void kdtree<T>::maximo(int &maxi)
{
	this->raiz->maximo(maxi);
}

/**
 * Obtiene el nodo con el valor minimo entre todos
 */
template<class T>
void kdtree<T>::minimo(int &mini)
{
	this->raiz->minimo(mini);
}
