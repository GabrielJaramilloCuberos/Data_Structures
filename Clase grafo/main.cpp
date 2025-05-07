#include <bits/stdc++.h>

using namespace std;

class Grafo{
    private:
        int V;
        list<list<int>> adj;
    public:
        Grafo();
        void EulerGrafo();
        void impEulerGrafo(int u);
        bool isValidNextEdge(int u, int v);
        void borrarEdge(int u, int v);
};

void Grafo::EulerGrafo(){
    int u = 0;
    for(int i = 0; i<V; i++){
        if(adj[i].size() & 1{
            u = 1;
            break;
        }
    }
    
}

void Grafo::impEulerGrafo(int u){
    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); ++i){
        int v = *i;
        if(v!= -1 && isValidNextEdge(u,v)){
            cout<<u<<"-"<<v<<" ";
            borrarEdge(u,v);
            impEulerGrafo(v);
        }
    }
}

bool Grafo::isValidNextEdge(int u, int v){
    int count = 0;
    list<int>::iterator i;
    for(i = adj[u].begin(); i != adj[u].end(); ++i){
        if(*i != -1){
            count++;
        }
    }
    if(count == 1){
        return true;
    }
}

void Grafo::borrarEdge(int u, int v){
    
}