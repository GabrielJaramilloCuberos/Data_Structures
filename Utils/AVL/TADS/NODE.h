#ifndef NODE_H
#define NODE_H

class Node {
private:
    int val;
    Node *derecha;
    Node *izquierda;
    int altura;
public:
    void setAltura(int alt);
    void setVal(int valor);
    void setDerecha(Node* der);
    void setIzquierda(Node* izq);
    int getAltura();
    int getVal();
    Node* getDerecha();
    Node* getIzquierda();
};

int alturaNodo(Node* root);
int factorDeBalance(Node* root);
Node* rotacionDerecha(Node* root);
Node* rotacionIzquierda(Node* root);
Node* insertarNodo(Node* root, int val);
Node* nodoMenorValor(Node* root);
Node* eliminarNodo(Node* root, int val);
void inOrder(Node* root);
bool buscarNodo(Node* root, int val);


#endif // NODE_H
