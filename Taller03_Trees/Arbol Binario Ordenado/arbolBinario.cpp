#include "ArbolBinario.h"
#include "NodoBinario.h"

#include <iostream>
using namespace std;

int main(){
    ArbolBinario<int> arbol;
    int data;
    while(data){
        cin>>data;
        arbol.insertar(data);
    }

    cout<<"\nEl recorrido inOrdene es: \n";
    arbol.inOrden();
    cout<<"\nEl recorrido posOrden es: \n";
    arbol.posOrden();
    cout<<"\nEl recorrido preOrden es: \n";
    arbol.inOrden();
    cout<<"\nEl recorrido levelOrden es: \n";
    arbol.nivelOrden();
    
    return 0;
}