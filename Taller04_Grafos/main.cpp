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


int main(){
    mensajeInicial();
    Grafo grafo;
    Cita c;
    return 0;
}