//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include<iostream>
#include<set>
#include<map>
#include "kdtree.h"
#include "kdnodo.h"

using namespace std;

main(int argc, char* argv[])
{
    cout<<"Arbol-KD ORDENADO"<<endl;
    cout<<"****************************************************************"<<endl;
    kdtree<int> arbolito;
	int can;
	cout<<"Cuantos elementos desea en el arbol: \n";
	cin>>can;
	for(int i=0; i<can; i++)
	{
	    cout<<"Cuantos datos desea: ";
		int dato;
		cin>>dato;
		vector<int> datos;
		for(int j = 0; j<dato; j++){
			int te; cin>>te;
			datos.push_back(te);
		}
		arbolito.insertar(datos);
	}

	cout<<endl;
	cout<<"Pre Orden:"<<endl;
	arbolito.preOrden();
	cout<<endl;
	cout<<"Pos Orden: "<<endl;
	arbolito.posOrden();
	cout<<endl;

}
