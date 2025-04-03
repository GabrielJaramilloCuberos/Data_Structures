//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include "ArbolBinario.h"

#include <iostream>
using namespace std;

int main(){
    ArbolBinario<int> arbol;
    int data = 1;
    //insercion de datos
    while(true){
        cout<<"Ingrese el valor del nodo que quiere insertar: ";
        cin>>data;
        if(data == 0){
            break;
        }
        arbol.insertar(data);
    }
    // Impresion de recorrido
    cout<<"\nEl recorrido inOrdene es: \n";
    arbol.inOrden(arbol.getRaiz());
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden(arbol.getRaiz());
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.preOrden(arbol.getRaiz());
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelOrden(arbol.getRaiz());
    
    return 0;
}
