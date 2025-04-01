#include<iostream>
#include "ArbolBinarioAVL.h"
#include "NodoBinarioAVL.h"

using namespace std;

int main(int argc, char* argv[])
{
    ArbolBinarioAVL<int> arbolito;
	while(true)
	{
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
	
	cout << endl << "Inorden: " << endl;
	arbolito.inOrden(arbolito.getRaiz());
	cout << endl << "Preorden: " << endl;
	arbolito.preOrden(arbolito.getRaiz());
	cout << endl <<"Posorden: " << endl;
	arbolito.posOrden(arbolito.getRaiz());
}