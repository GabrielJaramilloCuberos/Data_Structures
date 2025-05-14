#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
#include <list>
using namespace std;
// iPair ==> Par entero
#define iPair pair<int, int>;
// clase que representa un grafo dirigido utilizando la representación de listas de adyacencia
class Graph
{
    int V; // No. de vértices
    // En un grafo ponderado, necesitamos almacenar el vértice y el par de pesos de cada arista
    vector<pair<int, int>> adj;

public:
    Graph(int V); // Constructor
    // para añadir una arista al gráfico
    void addEdge(int u, int v, int w);
    // imprime el camino más corto desde s
    void shortestPath(int s);
};

void Graph::shortestPath(int src)
{
    // Crea una cola de prioridad para almacenar los vértices que están siendo preprocesados.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Crear un vector para las distancias e inicializar todas las distancias como infinitas (INF)
    vector<int> dist(V, INF);
    // Insertar la propia fuente en la cola de prioridad e inicializar su distancia como 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        /*El primer vértice del par es el vértice de distancia mínima, extráigalo de la cola de
        prioridad. la etiqueta del vértice se almacena en el segundo del par (debe hacerse así para
        mantener los vértices ordenados por distancia (la distancia debe ser el primer elemento del
        par)*/
        int u = pq.top().second;
        pq.pop();
        //'i' se utiliza para obtener todos los vértices adyacentes de un vértice
        list<pair<int, int>>::iterator i;
        for (vector<pair<int,int>>::iterator i = adj.begin(); i != adj.end(); ++i)
        {
            // Obtener etiqueta de vértice y peso del adyacente actual de u.
            int v = (*i).first;
            int weight = (*i).second;
            // Si hay un camino cortocircuitado a v a través de u.
            if (dist[v] > dist[u] + weight)
            {
                // Actualización de la distancia de v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}