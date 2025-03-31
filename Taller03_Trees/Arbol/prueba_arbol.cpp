#include <iostream>
#include <string>
/*#include <bits/stdc++.h>*/
#include "arbol.h"
#include "nodo.h"

using namespace std;

int main(){
    Arbol<int> arbol(1);
    arbol.insertarNodo(1,2);
    arbol.insertarNodo(1,3);
    arbol.insertarNodo(1,4);
    arbol.insertarNodo(1,5);
    arbol.insertarNodo(2,6);
    arbol.insertarNodo(2,7);
    arbol.insertarNodo(3,8);
    arbol.insertarNodo(3,9);
    arbol.insertarNodo(4,10);
    arbol.insertarNodo(5,11);
    arbol.insertarNodo(5,12);
    arbol.insertarNodo(5,13);
    cout<<"PreOrden"<<endl;
    arbol.preOrden();
    cout<<"inOrden"<<endl;
    arbol.inOrden();
    cout<<"posOrden"<<endl;
    arbol.posOrden();
    
    return 0;

}
