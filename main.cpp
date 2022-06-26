#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <stack>

using namespace std;

// Se puede asumir que no se ingresarán aristas repetidas, es decir, que el grafo es simple
class Graph
{
private:
    int n; // number of vertices
    vector<vector<int>> grafo;
    vector<int> vec;

public:
    Graph(int n)
    {
        this->n = n;
        grafo.reserve(n);

        for (int i = 0; i < n; i++)
        {
            grafo.push_back(vec);
        }
    }
    ~Graph()
    {
    }

    // Agregar una arista dirigida desde u hacia v
    void addEdge(int u, int v)
    {
        grafo.at(u).push_back(v);
    }

    // Verificar a través de un recorrido DFS (implementado usando stack)
    // si el vértice u puede alcanzar a todos los otros vértices:
    bool checkConnectivityDFS(int u)
    {
        bool check = true;
        stack<int> pila;
        map<int, bool> visited;
        // Mark all the vertices as not visited in the beginning
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        pila.push(u);
        visited[u] = true;
        while (!pila.empty())
        {
            // Pop a vertex from stack and print it
            int vertex = pila.top();
            pila.pop();

            // Get all adjacent vertices of the popped vertex v
            // If a adjacent has not been visited, then push it
            // to the stack.
            for (int v : grafo.at(vertex))
            {
                if (!visited[v])
                {
                    pila.push(v);
                    // mark that vertex v as visited
                    visited[v] = true;
                }
            }
        }

        cout << "Check if vertex was visited by vertex " << u << " in DFS:" << endl;
        for (auto vertex : visited)
        {
            if (vertex.second == false)
            {
                check = false;
            }
            cout << vertex.first << " = " << vertex.second << endl;
        }
        cout << "\"Vértice " << u << " alcanzó a todos los otros vértices? -> " << check << "\"\n"
             << endl;

        return check;
    }

    // Verificar a través de un recorrido BFS (implementado usando queue)
    // si el vértice u puede alcanzar a todos los otros vértices:
    bool checkConnectivityBFS(int u)
    {
        bool check = true;
        queue<int> cola;
        map<int, bool> visited;
        // Mark all the vertices as not visited in the beginning
        for (int i = 0; i < n; i++)
        {
            visited[i] = false;
        }

        cola.push(u);
        visited[u] = true;
        while (!cola.empty())
        {
            int vertex = cola.front();
            cola.pop();
            for (int v : grafo.at(vertex))
            {
                if (!visited[v])
                {
                    cola.push(v);
                    // mark that vertex v as visited
                    visited[v] = true;
                }
            }
        }

        cout << "Check if vertex was visited by vertex " << u << " in BFS:" << endl;
        for (auto vertex : visited)
        {
            if (vertex.second == false)
            {
                check = false;
            }
            cout << vertex.first << " = " << vertex.second << endl;
        }
        cout << "\"Vértice " << u << " alcanzó a todos los otros vértices? -> " << check << "\"\n"
             << endl;

        return check;
    }

    void print()
    {
        cout << "Graph:" << endl;
        for (int i = 0; i < grafo.size(); i++)
        {
            cout << "Vertex " << i << " -> { ";
            for (int v : grafo.at(i))
            {
                cout << v << " ";
            }
            cout << "}" << endl;
        }
        cout << endl;
    }

    void insertRandomEdges()
    {
        srand((unsigned)time(0));

        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            int random = rand() % 5 + 1;
            for (int j = 0; j < random; j++)
            {
                int vRand = rand() % n;
                if (vRand != i)
                {
                    temp.push_back(vRand);
                }
            }
            sort(temp.begin(), temp.end());
            temp.erase(unique(temp.begin(), temp.end()), temp.end());

            for (auto v : temp)
            {
                addEdge(i, v);
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    srand((unsigned)time(0));
    std::cout << std::boolalpha;

    int n = 10;
    int u = rand() % n;
    Graph *graph = new Graph(n);

    graph->insertRandomEdges();
    graph->print();
    graph->checkConnectivityDFS(u);
    graph->checkConnectivityBFS(u);

    delete graph;
    return 0;
}
