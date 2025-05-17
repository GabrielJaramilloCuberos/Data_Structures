#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <vector>
#include "Cita.h"

using namespace std;

class Grafo{
    private:
        vector<vector<Cita>> citas;
        int siguienteID = 0;
    public:
        Grafo();
        Grafo(vector<vector<Cita>> citasNuevas);
        vector<vector<Cita>> getCitas();
        int getSiguienteId();
        void setCitas(vector<vector<Cita>> citasNuevas);
        void setSiguienteId(int siguienteIdNuevo);
        int buscarCita(Cita u);
        void insertar(Cita u, Cita v);
        int validarIndice(Cita u);
        void eliminar(Cita u, Cita v);
        Cita articuloConMayorCitaciones();
        int articulosAlrededorDeUnArticuloDeInteres(Cita u);
        int indiceDeReferenciacion(Cita u);
        int citacionesIndirectasDesdeUnArticulo(Cita u);
};


#endif //GRAFO_H