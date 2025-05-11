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
