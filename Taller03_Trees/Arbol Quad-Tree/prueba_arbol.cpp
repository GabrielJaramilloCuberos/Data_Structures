#include <bits/stdc++.h>
#include "quadtree.h"

using namespace std;

int main(){

    Arbol<int> arbol({-1,-1});
    cout<<"Cual quiere se sea el limite para el quadtree \n";
    int borde; cin>>borde;
    arbol.setMaximo(borde);
    arbol.insertar({3,4}, borde);
    arbol.insertar({5,1}, borde);
    arbol.insertar({4,4}, borde);
    arbol.insertar({6,4}, borde);
    

    cout<<"El recorrido preOrden es: \n";
    arbol.preOrden();
}
