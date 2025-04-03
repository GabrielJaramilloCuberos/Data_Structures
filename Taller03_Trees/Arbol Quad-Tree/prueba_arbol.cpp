//j

/**
 * Implementacion modular de Salomon Avila
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;

int main(){

    Arbol<int> arbol({-1,-1});
    int borde = 8;
    arbol.setMaximo(borde);
    arbol.insertar({3,4}, borde);
    arbol.insertar({5,1}, borde);
    arbol.insertar({4,4}, borde);
    arbol.insertar({6,4}, borde);
    

    cout<<"El recorrido preOrden es: \n";
    arbol.preOrden();
}
