#include <iostream>
#include <vector>

using namespace std;

class Graph
{
public:
    int n; // Número de vértices
    vector<int> *adj;
    bool is_undirected;

    bool *visited = NULL; // visited[i] = true se e somente se nós já visitámos o vértice i

    Graph(int n, bool is_undirected = true)
    {
        this->n = n;
        this->adj = new vector<int>[n];
        this->is_undirected = is_undirected;
    }

    void add_edge(int u, int v)
    {
        this->adj[u].push_back(v);
        if (this->is_undirected)
        {                        // Se o grafo não for direcionado
            this->adj[v].push_back(u); // Nós adicionamos a aresta de v para u
        }
    }

    int count_components()
    {
        delete this->visited; // Deleta o vetor anterior da memória. Isso é importante no caso que count_components é chamada múltiplas vezes
        this->visited = new bool[this->n];

        int qtd_components = 0; // Guarda a quantidade de componentes do nosso grafo

        for (int i = 0; i < n; i++)
        {
            if (!this->visited[i])
            {
                this->dfs(i); // Marca todos os vértices que estão na mesma componente o i-ésimo vértice
                qtd_components++;
            }
        }

        return qtd_components;
    }

    void dfs(int current) // depth first search
    {
        this->visited[current] = true;

        for (unsigned i = 0; i < this->adj[current].size(); i++)
        {
            int neighbour = this->adj[current][i];

            if (!this->visited[neighbour])
                this->dfs(neighbour);
        }
    }
};

int main()
{
    int n, m;

    // Lê o número de vértices e o número de arestas respectivamente
    cin >> n >> m;

    Graph graph(n);

    for (int i = 0; i < m; i++)
    {
        int U, V;

        // Lê a descrição de uma aresta
        cin >> U >> V;
        

        graph.add_edge(U, V);
    }

    cout << "Número de componentes: " << graph.count_components() << endl;
}