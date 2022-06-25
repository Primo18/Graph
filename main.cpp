#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// Se puede asumir que no se ingresarán aristas repetidas, es decir, que el grafo es simple
class Graph
{
private:
    int n; // number of vertices
    int m; // number of edges
    vector<vector<int>> grafo;

public:
    Graph(int n)
    {
        this->n = n;
        vector<vector<int>> grafo(10);
    }
    ~Graph()
    {
    }

    // Agregar una arista dirigida desde u hacia v
    void addEdge(int u, int v)
    {
    }

    // Verificar a través de un recorrido DFS (implementado usando stack)
    // si el nodo u puede alcanzar a todos los otros nodos:
    bool checkConnectivityDFS(int u)
    {
        return false;
    }

    // Verificar a través de un recorrido BFS (implementado usando queue)
    // si el nodo u puede alcanzar a todos los otros nodos:
    bool checkConnectivityBFS(int u)
    {
        return false;
    }
};

int main(int argc, char const *argv[])
{
    int n = 0;
    int m = 0;
    Graph *graph = new Graph(n);

    cout << "Hi mom!" << endl;

    delete graph;
    return 0;
}
