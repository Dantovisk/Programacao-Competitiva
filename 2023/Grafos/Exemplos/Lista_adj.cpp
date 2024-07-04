#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
    int n; // Número de nodes, ou vértices
    vector<int> *adj;  //um vetor de adjescencias
    bool is_undirected; //grafo é não direcionado?

    Graph(int n, bool is_undirected = true)  //metodo construtor
    {
        this->n = n;
        this->adj = new vector<int>[n];
        this->is_undirected = is_undirected;
    }

    void add_edge(int u, int v) //adiciona uma aresta entre vértices
    {
        this->adj[u].push_back(v);
        if (this->is_undirected)
        {                        // Caso o grafo seja não direcionado
            this->adj[v].push_back(u); // Adicionamos a aresta de v para u
        }
    }
};

int main()
{
    int n = 6, m = 5;
    Graph graph(n);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v);
    }
    return 0;
}