#ifndef NODE_H
#define NODE_H

class Node {
private:
    int val;
    Node *derecha;
    Node *izquierda;
public:
    void setVal(int valor);
    void setDerecha(Node* der);
    void setIzquierda(Node* izq);
    int getVal();
    Node* getDerecha();
    Node* getIzquierda();
};

Node* crearNodo(int value);
Node* insertarNodo(Node* root, int value);
void inOrder(Node* root);
Node* buscarNodo(Node* root, int valor);
Node* hojaMenor(Node* nodo);
Node* eliminarNodo(Node* root, int dato);  

#endif // NODE_H
