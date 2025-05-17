#include "Grafo.h"
#include <vector>
#include <string>
#include "Cita.h"
#include <iostream>

using namespace std;

Grafo::Grafo(){
    citas = vector<vector<Cita>>();
}

Grafo::Grafo(vector<vector<Cita>> citasNuevas){
    citas = citasNuevas;
}

int Grafo::buscarCita(Cita u){

}

void Grafo::insertar(Cita u, Cita v){
    int indiceU = 0, indiceV = 0;

}

int Grafo::validarIndice(Cita u){
    for(int i = 0; i<citas.size(); i++){
        if(citas[i][0].getAutores() == u.getAutores()){
            return i;
        }
    }
    citas.push_back(vector<Cita>());
    siguienteID++;
    u.setId(siguienteID);
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
