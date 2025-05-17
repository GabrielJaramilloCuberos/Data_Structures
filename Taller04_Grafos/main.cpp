#include "TADS/Cita.h"
#include "TADS/Grafo.h"
#include "vector"
#include "string"
#include "iostream"
using namespace std;

void mensajeInicial(){
    cout<<"----------------------------------"<<endl;
    cout<<"| Bienvenido al sistema de citas |"<<endl;
    cout<<"| Realizado por:                 |"<<endl; 
    cout<<"| 1. Salomon Avila               |"<<endl;
    cout<<"| 2. Gabriel Jaramillo           |"<<endl;
    cout<<"----------------------------------"<<endl;
}

Cita anadirCita(){

}

void mostrarExistentes(Grafo grafo){
    cout<<"Las citas existentes: "<<endl;
    for(int i = 0; i<grafo.getCitas().size(); i++){
        cout<<i<<". "<<grafo.getCitas()[i][0].getCitaAutor()<<endl;
    }
}

int main(){
    Grafo grafo;
    mensajeInicial();
    cout<<"Cuantas aristas va a ingresar?"<<endl;
    int cantidadAristas;
    cin>>cantidadAristas;
    for(int i = 0; i<cantidadAristas; i++){
        cout<<"Estas son las citas disponibles, elija -1 para crear uno nuevo"<<endl;
        mostrarExistentes(grafo);
        
    }
    
    Cita c;
    return 0;
}