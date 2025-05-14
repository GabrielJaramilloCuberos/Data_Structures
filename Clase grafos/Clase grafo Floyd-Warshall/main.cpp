#include <bits/stdc++.h>
using namespace std;
void floyds(vector<vector<int>> &b)
{
    int i, j, k;
    for (k = 0; k < b.size(); k++)
    {
        for (i = 0; i < b.size(); i++)
        {
            for (j = 0; j < b.size(); j++)
            {
                if ((b[i][k] * b[k][j] != 0) && (i != j))
                {
                    if ((b[i][k] + b[k][j] < b[i][j]) || (b[i][j] == 0))
                    {
                        b[i][j] = b[i][k] + b[k][j];
                    }
                }
            }
        }
    }
    for (i = 0; i < b.size(); i++)
    {
        cout << "Minimum Cost With Respect to Node:" << i << endl;
        for (j = 0; j < b.size(); j++)
        {
            cout << b[i][j] << "\t";
        }
    }
}
int main()
{   
    int numeroVertices = 0;
    cout<<"Con cuantos vertices desea trabajar?"<<endl;
    cin>>numeroVertices;

    vector<vector<int>> b(numeroVertices, vector<int>(numeroVertices));
    for (int i = 0; i < numeroVertices; i++)
    {
        for (int j = 0; j < numeroVertices; j++)
        {
            b[i][j] = 1e9;
        }
    }
    int opc = -1;
    while(opc != 0){
        cout<<"Si desea salir ingrese 0, si desea agregar una arista ingrese 1"<<endl;
        cin>>opc;
        if(opc == 1){
            int origen, destino, costo;
            cout<<"Ingrese el nodo de origen"<<endl;
            cin>>origen;
            cout<<"Ingrese el nodo de destino"<<endl;
            cin>>destino;
            cout<<"Ingrese el costo de la arista"<<endl;
            cin>>costo;
            b[origen][destino] = costo;
        }
    }
    floyds(b);
    return 0;
}