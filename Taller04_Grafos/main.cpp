//j
/**
 * Autores: Salomon Avila y Gabriel Jaramillo
 * Pontificia universidad javeriana
 * Estructuras de datos
 */

#include "TADS/Cita.h"
#include "TADS/Grafo.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void mensajeInicial()
{
    cout << "----------------------------------" << endl;
    cout << "| Bienvenido al sistema de citas |" << endl;
    cout << "| Realizado por:                 |" << endl;
    cout << "| 1. Salomon Avila               |" << endl;
    cout << "| 2. Gabriel Jaramillo           |" << endl;
    cout << "----------------------------------" << endl;
}

Cita anadirCita(int id)
{
    string ano, revista, citaAutor;
    int edicion;
    vector<string> autores;

    cout << "Ingrese el año de la cita: ";
    cin >> ano;

    cout << "Ingrese el nombre de la revista: ";
    cin.ignore(); // Solo aquí, porque antes hubo un cin >>
    getline(cin, revista);

    cout << "Ingrese la edición de la revista: ";
    cin >> edicion;

    cout << "Ingrese el autor principal de la cita: ";
    cin.ignore(); // Solo aquí, porque antes hubo un cin >>
    getline(cin, citaAutor);
    autores.push_back(citaAutor);

    cout << "¿Cuántos coautores tiene esta cita? ";
    int numCoautores;
    cin >> numCoautores;

    for (int i = 0; i < numCoautores; i++)
    {
        string coautor;
        cout << "Ingrese el nombre del coautor " << i + 1 << ": ";
        cin.ignore(); // Solo aquí, porque antes hubo un cin >>
        getline(cin, coautor);
        autores.push_back(coautor);
    }
    return Cita(id, autores, revista, edicion, ano);
}

void mostrarExistentes(Grafo &grafo)
{
    cout << "Las citas existentes: " << endl;
    vector<vector<Cita>> citas = grafo.getCitas();
    for (int i = 0; i < citas.size(); i++)
    {
        cout << i << ". " << citas[i][0].getCitaAutor() << " (" << citas[i][0].getAno() << ")" << endl;
    }
}

int main()
{
    Grafo grafo;
    mensajeInicial();
    int cantidadAristas;
    cout << "¿Cuántas conexiones desea ingresar? ";
    cin >> cantidadAristas;
    for (int i = 0; i < cantidadAristas; i++)
    {
        cout << "\nConexión " << i + 1 << ":" << endl;
        cout << "Seleccione la cita fuente:" << endl;
        mostrarExistentes(grafo);
        cout << "-1. Crear una nueva cita" << endl;
        int opcionFuente;
        cin >> opcionFuente;
        Cita citaFuente;
        if (opcionFuente == -1)
        {
            int nuevoId = grafo.getSiguienteId();
            grafo.setSiguienteId(nuevoId + 1);
            citaFuente = anadirCita(nuevoId);
        }
        else if (opcionFuente >= 0 && opcionFuente < grafo.getCitas().size())
        {
            citaFuente = grafo.getCitas()[opcionFuente][0];
        }
        else
        {
            cout << "Opción inválida. Intente nuevamente." << endl;
            i--;
            continue;
        }
        cout << "Seleccione la cita destino:" << endl;
        mostrarExistentes(grafo);
        cout << "-1. Crear una nueva cita" << endl;
        int opcionDestino;
        cin >> opcionDestino;
        Cita citaDestino;
        if (opcionDestino == -1)
        {
            int nuevoId = grafo.getSiguienteId();
            grafo.setSiguienteId(nuevoId + 1);
            citaDestino = anadirCita(nuevoId);
        }
        else if (opcionDestino >= 0 && opcionDestino < grafo.getCitas().size())
        {
            citaDestino = grafo.getCitas()[opcionDestino][0];
        }
        else
        {
            cout << "Opción inválida. Intente nuevamente." << endl;
            i--;
            continue;
        }
        grafo.insertar(citaFuente, citaDestino);
        cout << "Conexión añadida exitosamente entre " << citaFuente.getCitaAutor()
             << " y " << citaDestino.getCitaAutor() << "." << endl;
    }
    cout << "Operacion 1: " << endl;
    grafo.articuloConMayorCitaciones();
    cout << "Terminada la operacion 1" << endl;
    cout << "Con cual cita desea ejecutar la operacion 2? " << endl;
    mostrarExistentes(grafo);
    Cita temDos;
    int resDos;
    cin.ignore();
    cout<<"Ignorado"<<endl;
    cin >> resDos;
    if (resDos >= 0 && resDos < grafo.getCitas().size())
    {
        temDos = grafo.getCitas()[resDos][0];
        grafo.articulosAlrededorDeUnArticuloDeInteres(temDos);
    }
    else
    {
        cout << "Índice inválido o cancelado." << endl;
    }
    cout << "Terminada la operacion 2: " << endl;

    cout << "Operacion 3: " << endl;
    cout << "Con cual cita desea ejecutar la operacion 3? " << endl;
    mostrarExistentes(grafo);
    Cita temTres;
    int resTres;
    cin >> resTres;
    if (resTres >= 0 && resTres < grafo.getCitas().size())
    {
        temTres = grafo.getCitas()[resTres][0];
        grafo.indiceDeReferenciacion(temTres);
    }
    else
    {
        cout << "Índice inválido o cancelado." << endl;
    }
    cout << "Terminada la operacion 3: " << endl;

    cout << "Operacion 4: " << endl;
    cout << "Con cual cita desea ejecutar la operacion 4? " << endl;
    mostrarExistentes(grafo);
    Cita temCuatro;
    int resCuatro;
    cin >> resCuatro;
    if (resCuatro >= 0 && resCuatro < grafo.getCitas().size())
    {
        temCuatro = grafo.getCitas()[resCuatro][0];
        grafo.citacionesIndirectasDesdeUnArticulo(temCuatro);
    }
    else
    {
        cout << "Índice inválido o cancelado." << endl;
    }
    cout << "Terminada la operacion 4: " << endl;
    cout << "\nLista de adyacencia del grafo:" << endl;
    vector<vector<Cita>> listaAdyacencia = grafo.getCitas();
    for (int i = 0; i < listaAdyacencia.size(); i++)
    {
        cout << "Nodo " << listaAdyacencia[i][0].getId() << " está conectado con: ";
        for (int j = 1; j < listaAdyacencia[i].size(); j++)
        {
            cout << listaAdyacencia[i][j].getId() << " ";
        }
        cout << endl;
    }
    return 0;
}