//j

/**
 * Implementacion modular
 * Pontificia Universidad Javeriana
 * Bogota, Colombia
 */

#include<iostream>
#include "ArbolBinarioAVL.h"
#include "NodoBinarioAVL.h"

using namespace std;

int main(int argc, char* argv[])
{	
	//Se usa el constructor por defecto para crear el arbol
    ArbolBinarioAVL<int> arbolito;
	while(true)
	{
		//ingreso de datos
		int dato;
		char op;
		cin>>op>>dato;
		
		if(op == 'A')
			arbolito.insertar(dato);
		else if(op == 'E')
			arbolito.eliminar(dato);
		else
			break;
	}
	//Impresion de recorridos
	cout << endl << "Inorden: " << endl;
	arbolito.inOrden(arbolito.getRaiz());
	cout << endl << "Preorden: " << endl;
	arbolito.preOrden(arbolito.getRaiz());
	cout << endl <<"Posorden: " << endl;
	arbolito.posOrden(arbolito.getRaiz());
}
