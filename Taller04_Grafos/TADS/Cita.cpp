#include "Cita.h"
#include <vector>
#include <string>
#include <iostream>

Cita::Cita() {
    id = 0;
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
    } else if (!autores.empty()) { // Verifica si el vector no está vacío
        citaAutor = autores[0];
        citaAutor += ".";
    } else {
        citaAutor = "Autor desconocido."; // Valor predeterminado si el vector está vacío
    }
}

// Getters y Setters
int Cita::getId() { return id; }
vector<string> Cita::getAutores() { return autores; }
string Cita::getCitaAutor() { return citaAutor; }
string Cita::getRevista() { return revista; }
int Cita::getEdicion() { return edicion; }

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