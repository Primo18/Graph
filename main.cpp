#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Graph;

int main(int argc, char const *argv[])
{
    int n = 0; // number of vertices
    int m = 0; // number of edges
    Graph *graph = new Graph(n);

    cout << "Hi mom!" << endl;
    return 0;
}

class Graph
{
private:
    int n; // number of vertices
    int m; // number of edges
public:
    Graph(int);
    ~Graph();
};

Graph::Graph(int n)
{
    this->n = n;
}

Graph::~Graph()
{
}
