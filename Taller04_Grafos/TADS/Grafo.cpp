// j
/**
 * Autores: Salomon Avila y Gabriel Jaramillo
 * Pontificia universidad javeriana
 * Estructuras de datos
 */
#include "Grafo.h"
#include <vector>
#include <string>
#include "Cita.h"
#include <iostream>

using namespace std;

Grafo::Grafo()
{
    citas = vector<vector<Cita>>();
    siguienteID = 0;
}

Grafo::Grafo(vector<vector<Cita>> citasNuevas)
{
    citas = citasNuevas;
    siguienteID = citas.size();
}

vector<vector<Cita>> Grafo::getCitas()
{
    return citas;
}

int Grafo::getSiguienteId()
{
    return siguienteID;
}

void Grafo::setSiguienteId(int siguienteIdNuevo)
{
    siguienteID = siguienteIdNuevo;
}

int Grafo::buscarCita(Cita u)
{
}

void Grafo::insertar(Cita u, Cita v)
{
    int indiceU = validarIndice(u);
    validarIndice(v);
    citas[indiceU].push_back(v);
}

int Grafo::validarIndice(Cita u)
{
    for (int i = 0; i < citas.size(); i++)
    {
        if (citas[i][0].getId() == u.getId())
        {
            return i;
        }
    }
    vector<Cita> nuevoNodo;
    nuevoNodo.push_back(u);
    citas.push_back(nuevoNodo);
    return citas.size() - 1;
}

void Grafo::eliminar(vector<vector<Cita>> &citas, int idABorrar)
{
    for (int i = 0; i < citas.size(); i++)
    {

        for (int j = 1; j < citas[i].size();)
        {
            if (citas[i][j].getId() == idABorrar)
            {

                citas[i].erase(citas[i].begin() + j);
            }
            else
            {
                j++;
            }
        }
    }
}

void Grafo::articuloConMayorCitaciones()
{
    vector<int> ocurrencias(citas.size());
    for (auto l : citas)
    {
        for (auto c : l)
        {
            ocurrencias[c.getId()] += 1;
        }
    }
    vector<Cita> citasMaximas;
    int maximo = 0;
    for (int i = 0; i < ocurrencias.size(); i++)
    {
        if (ocurrencias[i] > maximo)
        {
            maximo = ocurrencias[i];
        }
    }
    for (int i = 0; i < ocurrencias.size(); i++)
    {
        if (ocurrencias[i] == maximo)
        {
            citasMaximas.push_back(citas[i][0]);
        }
    }
    if (citasMaximas.size() > 1)
    {
        cout << "Hay multiples citas con el numero maximo de citas, estas son: " << endl;
        for (int i = 0; i < citasMaximas.size(); i++)
        {
            cout << i + 1 << ". " << citasMaximas[i].getCitaAutor() << endl;
        }
    }
    else
    {
        cout << "La cita con mayor numero de citaciones es: " << endl;
        cout << citasMaximas[0].getCitaAutor() << endl;
    }
}

vector<vector<Cita>> invertirGrafo(const vector<vector<Cita>> &original)
{
    vector<vector<Cita>> invertido(original.size());
    for (int i = 0; i < original.size(); i++)
    {
        invertido[i].push_back(original[i][0]);
    }

    for (int i = 0; i < original.size(); i++)
    {
        Cita nodoFuente = original[i][0];
        for (int j = 1; j < original[i].size(); j++)
        {
            Cita nodoDestino = original[i][j];
            int indiceDelDestino = -1;
            for (int k = 0; k < invertido.size(); k++)
            {
                if (invertido[k][0].getId() == nodoDestino.getId())
                {
                    indiceDelDestino = k;
                    break;
                }
            }
            if (indiceDelDestino != -1)
            {
                invertido[indiceDelDestino].push_back(nodoFuente);
            }
        }
    }
    return invertido;
}

void dfs(int indice, vector<vector<Cita>> &citaciones, vector<bool> &visitado, vector<int> &componente)
{
    visitado[indice] = true;
    componente.push_back(citaciones[indice][0].getId());
    for (int j = 1; j < citaciones[indice].size(); j++)
    {
        int idVecino = citaciones[indice][j].getId();
        for (int k = 0; k < citaciones.size(); k++)
        {
            if (citaciones[k][0].getId() == idVecino && !visitado[k])
            {
                dfs(k, citaciones, visitado, componente);
            }
        }
    }
}

vector<vector<int>> componentesConexosDFS(vector<vector<Cita>> &citaciones)
{
    vector<vector<int>> componentes;
    vector<bool> visitado(citaciones.size(), false);

    for (int i = 0; i < citaciones.size(); i++)
    {
        if (!visitado[i])
        {
            vector<int> componente;
            dfs(i, citaciones, visitado, componente);
            componentes.push_back(componente);
        }
    }
    return componentes;
}

void Grafo::articulosAlrededorDeUnArticuloDeInteres(Cita u)
{

    vector<vector<Cita>> citasDos = citas;
    int idABorrar = u.getId();

    eliminar(citasDos, idABorrar);
    for (int i = 0; i < citasDos.size(); i++)
    {
        if (citasDos[i][0].getId() == idABorrar)
        {
            citasDos[i].resize(1);
            break;
        }
    }
    vector<vector<Cita>> citasNoDirigido = citasDos;
    vector<vector<Cita>> invertido = invertirGrafo(citasDos);
    for (int i = 0; i < citasNoDirigido.size(); i++)
    {
        for (int j = 1; j < invertido[i].size(); j++)
        {
            bool yaEsta = false;
            for (int k = 1; k < citasNoDirigido[i].size(); k++)
            {
                if (citasNoDirigido[i][k].getId() == invertido[i][j].getId())
                {
                    yaEsta = true;
                    break;
                }
            }
            if (!yaEsta)
            {
                citasNoDirigido[i].push_back(invertido[i][j]);
            }
        }
    }

    vector<vector<int>> comps = componentesConexosDFS(citasNoDirigido);
    // Aca se resta uno porque en el DFS se cuenta el que está eliminado simbolicamente
    // Por tanto toca restar
    cout << "Grupos encontrados: " << comps.size() - 1 << endl;
}

void Grafo::indiceDeReferenciacion(Cita u)
{
    int idATenerEnCuenta = u.getId();
    int numUno = 0, numDos = 0;
    for (int i = 0; i < citas.size(); i++)
    {
        if (i != idATenerEnCuenta)
        {
            for (int j = 0; j < citas[i].size(); j++)
            {
                if (citas[i][j].getId() == idATenerEnCuenta)
                {
                    numUno++;
                }
            }
        }
    }
    numDos = citas[idATenerEnCuenta].size();
    cout << "El indice de referenciacion para el articulo " << u.getCitaAutor() << " es: " << numUno / (0.5 * numDos);
}

int buscarIndicePorId(vector<vector<Cita>> &citas, int id)
{
    for (int i = 0; i < citas.size(); i++)
    {
        if (citas[i][0].getId() == id)
            return i;
    }
    return -1;
    // No se encontro y en teoria esto deberia de dar un error
    // Aunque es muy improbable por la funcion que tenemos
    // De seleccionar manualmente el id de la cita en el main
}

void Grafo::citacionesIndirectasDesdeUnArticulo(Cita u)
{
    int idReferencia = u.getId();
    int idxReferencia = buscarIndicePorId(citas, idReferencia);
    if (idxReferencia == -1)
    {
        cout << "Cita no encontrada." << endl;
        return;
    }
    vector<int> revisar;
    for (int i = 0; i < citas[idxReferencia].size(); i++)
    {
        revisar.push_back(citas[idxReferencia][i].getId());
    }
    vector<int> respuestas;
    vector<Cita> respuestasCita;
    for (int i = 0; i < revisar.size(); i++)
    {
        int idxVecino = buscarIndicePorId(citas, revisar[i]);
        if (idxVecino == -1)
            continue;
        for (int j = 0; j < citas[idxVecino].size(); j++)
        {
            Cita temCita = citas[idxVecino][j];
            int tem = temCita.getId();
            bool bandera = true;
            for (int k = 0; k < respuestas.size(); k++)
            {
                if (tem == respuestas[k])
                    bandera = false;
            }
            if (bandera)
            {
                respuestas.push_back(tem);
                respuestasCita.push_back(temCita);
            }
        }
    }
    cout << " El articulo " << u.getCitaAutor() << " tiene " << respuestas.size() << " citaciones indirectas";
}
