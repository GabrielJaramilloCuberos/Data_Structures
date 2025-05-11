#ifndef CITA_H
#define CITA_H

#include <vector>
#include <string>
using namespace std;

class Cita{
    private:
        int id;
        vector<string> autores;
        string citaAutor;
        string revista;
        int edicion;
        string ano;
    public:
        //Constructor
        Cita();
        Cita(int idNuevo, vector<string> autoresNuevos, string revistaNueva, int edicionNueva, string anoNuevo);
        //Destructor
        ~Cita();
        //Getters y Setters
        int getId();
        vector<string> getAutores();
        string getCitaAutor();
        string getRevista();
        int getEdicion();
        string getAno();

        void setId(int idNuevo);
        void setAutores(vector<string> autoresNuevos);
        void setCitaAutor(string citaAutorNueva);
        void setRevista(string revistaNueva);
        void setEdicion(int edicionNueva);
        void setAno(string anoNuevo);
};


#endif //CITA_H