//j
/**
 * Autores: Salomon Avila y Gabriel Jaramillo
 * Pontificia universidad javeriana
 * Estructuras de datos
 */

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
        void eliminar(vector<vector<Cita>> &citas, int idABorrar);
        void articuloConMayorCitaciones();
        void articulosAlrededorDeUnArticuloDeInteres(Cita u);
        void indiceDeReferenciacion(Cita u);
        void citacionesIndirectasDesdeUnArticulo(Cita u);
};


#endif //GRAFO_H