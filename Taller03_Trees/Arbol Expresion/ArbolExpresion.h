#ifndef ARBOLEXPRESION_H
#define  ARBOLEXPRESION_H
#include "NodoExpresion.h"
#include <string>
#include <vector>

using namespace std;

class ArbolExpresion {
  protected:
    NodoExpresion* raiz;
public:
    ArbolExpresion();
    ~ArbolExpresion();
    NodoExpresion* getRaiz();
    void setRaiz(NodoExpresion* nod);

    void llenarDesdePrefija(string &expresion);
    void llenarDesdePosfija (string &expresion);

    void  obtenerPrefija(NodoExpresion* inicio);
    void  obtenerInfija(NodoExpresion* inicio);
    void  obtenerPosfija(NodoExpresion* inicio);
    string Prefija(NodoExpresion* inicio);
    string Infija(NodoExpresion* inicio);
    string Posfija(NodoExpresion* inicio);
    int evaluar();
    bool esOp(char ope);
    int evaluar(NodoExpresion* nodi);
    void tokenizar(string &expresion, vector<string> &tokens);
    bool siOperando(char car);
};
#include "ArbolExpresion.hxx"

#endif

