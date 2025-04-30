// j

/**********************************************************************************************************************
 * Implementación de grafos por Salomón Ávila y Gabriel Jaramillo                                                     *
 * Contiene implementaciones para caminos de Hamilton y Euler, y en caso de encontrar cualquiera (o ambos) se imprime *
 * Pontificia Universidad Javeriana                                                                                   *
 * Bogotá, Colombia                                                                                                   *
 **********************************************************************************************************************/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
#include <stdio.h>

int n; // Número de vértices
using namespace std;

// TAD para representar un recorrido de Euler en un grafo
class Euler
{
  int V;          // Número de vértices
  list<int> *adj; // Lista de adyacencia para representar el grafo

public:
  Euler(int V)
  {
    this->V = V;
    adj = new list<int>[V];
  } // Constructor

  ~Euler() { delete[] adj; } // Destructor

  // Agrega una arista no dirigida entre u y v
  void addEdge(int u, int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  // Elimina una arista entre u y v
  void rmvEdge(int u, int v);

  // Imprime el recorrido de Euler si existe
  void printEulerTour();

  // Método auxiliar para printEulerTour()
  void printEulerUtil(int s);

  // Realiza DFS para contar nodos alcanzables desde v
  int DFSCount(int v, bool visited[]);

  // Verifica si una arista es válida para continuar el camino
  bool isValidNextEdge(int u, int v);

  // Determina si el grafo tiene un camino/circuito de Euler
  int iseuler(int[]);
};

// Imprime el recorrido de Euler empezando desde un vértice impar
void Euler::printEulerTour()
{
  int u = 0;
  for (int i = 0; i < V; i++)
    if (adj[i].size() & 1)
    { // Si tiene grado impar
      u = i;
      break;
    }
  printEulerUtil(u);
  cout << endl;
}

// Recorrido recursivo para imprimir el camino de Euler
void Euler::printEulerUtil(int u)
{
  for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
  {
    int v = *i;
    if (v != -1 && isValidNextEdge(u, v))
    {
      cout << u << "-" << v << " ";
      rmvEdge(u, v);     // Elimina arista usada
      printEulerUtil(v); // Recursión para el siguiente vértice
    }
  }
}

// Verifica si la arista u-v es válida para el recorrido actual
bool Euler::isValidNextEdge(int u, int v)
{
  int count = 0;

  for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
    if (*i != -1)
      count++;

  // Si solo hay una arista, debe ser válida (no hay más opciones)
  if (count == 1)
    return true;

  // Verificar puentes: si eliminar u-v reduce la conectividad
  bool visited[V];
  memset(visited, false, V);
  int count1 = DFSCount(u, visited);

  rmvEdge(u, v); // Elimina temporalmente la arista
  memset(visited, false, V);
  int count2 = DFSCount(u, visited);

  addEdge(u, v); // Restaura arista

  return (count1 > count2) ? false : true;
}

// Elimina una arista u-v de ambas listas de adyacencia
void Euler::rmvEdge(int u, int v)
{
  auto iv = find(adj[u].begin(), adj[u].end(), v);
  *iv = -1;

  auto iu = find(adj[v].begin(), adj[v].end(), u);
  *iu = -1;
}

// DFS para contar cuántos nodos se alcanzan desde v
int Euler::DFSCount(int v, bool visited[])
{
  visited[v] = true;
  int count = 1;

  for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
    if (*i != -1 && !visited[*i])
      count += DFSCount(*i, visited);

  return count;
}

// Determina si el grafo tiene camino o ciclo Euleriano
int Euler::iseuler(int a[])
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] % 2 != 0)
      count++;
  }

  if (count == 0)
  {
    cout << "Euler's circuit exists:\n";
    return 1;
  }
  else if (count == 2)
  {
    cout << "Euler's path exists:\n";
    return 1;
  }
  else
  {
    cout << "No Euler's path or circuit exists:\n\n";
    return -1;
  }
}

// Clase para representar un camino/ciclo Hamiltoniano
class Hamiltonian
{
  int *path, v, x;

public:
  Hamiltonian(int n)
  {
    v = 0;
    x = 0;
    path = new int[n];
  }

  bool isSafe(bool graph[][10], int pos);              // Verifica si se puede agregar el vértice v al camino
  bool hamCycleUtil(bool graph[][10], int pos, int i); // Construye camino Hamiltoniano recursivamente
  bool hamCycle(bool graph[][10]);                     // Inicia la búsqueda de ciclo o camino Hamiltoniano
  void printSolution();                                // Imprime el resultado encontrado
};

// Verifica si el vértice v se puede colocar en la posición
bool Hamiltonian::isSafe(bool graph[][10], int pos)
{
  if (graph[path[pos - 1]][v] == 0)
    return false;

  for (int i = 0; i < pos; i++)
    if (path[i] == v)
      return false;

  return true;
}

// Función recursiva para construir camino/ciclo Hamiltoniano
bool Hamiltonian::hamCycleUtil(bool graph[][10], int pos, int i)
{
  if (pos == n)
  {
    if (graph[path[pos - 1]][path[0]] == 1)
    {
      cout << "Hamiltonian cycle exists\n";
      x = 1;
    }
    else
    {
      cout << "Hamiltonian path exists\n";
    }
    return true;
  }

  for (v = 0; v < n; v++)
  {
    if (v == i)
      continue;
    if (isSafe(graph, pos))
    {
      path[pos] = v;

      if (hamCycleUtil(graph, pos + 1, i))
        return true;

      path[pos] = -1;
    }
  }

  return false;
}

// Inicia la búsqueda de ciclo o camino Hamiltoniano
bool Hamiltonian::hamCycle(bool graph[][10])
{
  for (int i = 0; i < n; i++)
    path[i] = -1;
  // Inicia con cada vértice
  for (int i = 0; i < n; i++)
  {
    path[0] = i;
    if (hamCycleUtil(graph, 1, i))
    {
      printSolution();
      return true;
    }
  }

  cout << "\nNo Hamiltonian path or cycle exists"; // Imprime si no se encuentra ningún camino/ciclo
  return false;
}

// Imprime el camino o ciclo Hamiltoniano
void Hamiltonian::printSolution()
{
  for (int i = 0; i < n - 1; i++)
    cout << path[i] << "-" << path[i + 1] << " ";

  if (x == 1)
    cout << path[n - 1] << "-" << path[0]; // Cierra ciclo si existe
  cout << "\n";
}

int main()
{
  int i, j, v1, v2, Edges; // Variables para entrada de datos

  cout << "\n Enter the number of vertices of graph: ";
  cin >> n;

  Euler g1(n);       // Grafo para Euler
  Hamiltonian g2(n); // Grafo para Hamilton
  int a[n];          // Arreglo para contar grado de cada vértice
  memset(a, 0, sizeof(a));

  bool graph1[10][10]; // Grafo para Hamilton (matriz)
  for (i = 0; i < 10; i++)
    for (j = 0; j < 10; j++)
      graph1[i][j] = 0;

  cout << "\n Enter the total number of edges: ";
  cin >> Edges;

  // Ingresa los vértices en el grafo
  for (i = 1; i <= Edges; i++)
  {
    cout << "\n Enter the edge: ";
    cin >> v1 >> v2;

    graph1[v1][v2] = 1;
    graph1[v2][v1] = 1;
    g1.addEdge(v1, v2);

    a[v1]++;
    a[v2]++;
  }

  cout << "\n";
  g2.hamCycle(graph1); // Buscar camino/ciclo de Hamilton

  cout << "\n";
  if (g1.iseuler(a) == 1)
  {
    g1.printEulerTour(); // Imprimir recorrido Euler si existe
  }

  return 0;
}
