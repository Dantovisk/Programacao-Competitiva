#include <iostream>
#include <cstring> // Para usarmos a função memset

using namespace std;

int main()
{
    int n = 6, m = 5;
    int M[n + 1][n + 1];
    // Inicialmente, consideramos que não existe nenhuma aresta, por isso usamos memset para setar o valor 0 em todas as posições de M
    memset(M, 0, sizeof M);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        M[u][v] = 1;
        M[v][u] = 1; // Caso G seja não direcionado
    }
    return 0;
}