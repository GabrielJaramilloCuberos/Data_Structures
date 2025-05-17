#include "Grafo.h"
#include <vector>
#include <string>
#include "Cita.h"
#include <iostream>

using namespace std;

Grafo::Grafo(){
    citas = vector<vector<Cita>>();
    siguienteID = 0;
}

Grafo::Grafo(vector<vector<Cita>> citasNuevas) {
    citas = citasNuevas;
    siguienteID = citas.size();
}

vector<vector<Cita>> Grafo::getCitas() {
    return citas;
}

int Grafo::getSiguienteId() {
    return siguienteID;
}

void Grafo::setSiguienteId(int siguienteIdNuevo) {
    siguienteID = siguienteIdNuevo;
}



int Grafo::buscarCita(Cita u){

}

void Grafo::insertar(Cita u, Cita v) {
    int indiceU = validarIndice(u);
    int indiceV = validarIndice(v);
    citas[indiceU].push_back(v);
    citas[indiceV].push_back(u);
}

int Grafo::validarIndice(Cita u) {
    for (int i = 0; i < citas.size(); i++) {
        if (citas[i][0].getId() == u.getId()) {
            return i;
        }
    }
    vector<Cita> nuevoNodo;
    nuevoNodo.push_back(u);
    citas.push_back(nuevoNodo);
    return citas.size() - 1;
}

void Grafo::eliminar(Cita u, Cita v){

}

Cita Grafo::articuloConMayorCitaciones(){

}

int Grafo::articulosAlrededorDeUnArticuloDeInteres(Cita u){

}

int Grafo::indiceDeReferenciacion(Cita u){

}

int Grafo::citacionesIndirectasDesdeUnArticulo(Cita u){

}
