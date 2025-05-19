//j
/**
 * Autores: Salomon Avila y Gabriel Jaramillo
 * Pontificia universidad javeriana
 * Estructuras de datos
 */
#include "Cita.h"
#include <vector>
#include <string>
#include <iostream>

Cita::Cita() {
    id = -1;
    autores = {};
    citaAutor = "";
    revista = "";
    edicion = 0;
    ano = "";
}

Cita::~Cita(){}

Cita::Cita(int idNuevo, vector<string> autoresNuevos, string revistaNueva, int edicionNueva, string anoNuevo) {
    id = idNuevo;
    autores = autoresNuevos;
    revista = revistaNueva;
    edicion = edicionNueva;
    ano = anoNuevo;

    if (autores.size() > 1) {
        string auxiliar = "";
        auxiliar += autores[0];
        auxiliar += ", et al.";
        citaAutor = auxiliar;
    } else if (!autores.empty()) { 
        citaAutor = autores[0];
        citaAutor += ".";
    } else {
        citaAutor = "Autor desconocido.";
    }
}

// Getters y Setters
int Cita::getId() { return id; }
vector<string> Cita::getAutores() { return autores; }
string Cita::getCitaAutor() { return citaAutor; }
string Cita::getRevista() { return revista; }
int Cita::getEdicion() { return edicion; }
string Cita::getAno() {return ano;}
void Cita::setId(int idNuevo) {
    id = idNuevo;
}
void Cita::setAutores(vector<string> autoresNuevos) {
    autores = autoresNuevos;
}
void Cita::setCitaAutor(string citaAutorNueva) {
    citaAutor = citaAutorNueva;
}
void Cita::setRevista(string revistaNueva) {
    revista = revistaNueva;
}
void Cita::setEdicion(int edicionNueva) {
    edicion = edicionNueva;
}