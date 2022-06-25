#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int n; // number of vertices
    int m; // number of edges
public:
    Graph(int n)
    {
        this->n = n;
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
    }

    // Verificar a través de un recorrido BFS (implementado usando queue)
    // si el nodo u puede alcanzar a todos los otros nodos:
    bool checkConnectivityBFS(int u)
    {
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
