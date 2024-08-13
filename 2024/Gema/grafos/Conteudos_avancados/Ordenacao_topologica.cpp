#include <bits/stdc++.h>

using namespace std;

vector<int> ordenados;
queue<int> fila;

int main() {
    int n, m, vistos = 0;  // n = número de vértices, m = número de arestas
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<int> pesos(n, 0);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        pesos[b]++;
    }

    // Realização da ordenação topológica
    for (int i = 0; i < n; i++) {
        if (pesos[i] == 0) {
            fila.push(i);
        }
    }
    
    while (!fila.empty()) {
        int u = fila.front();
        fila.pop();
        ordenados.push_back(u);
        vistos++;
        
        for (int v : adj[u]) {
            pesos[v]--;
            if (pesos[v] == 0) {
                fila.push(v);
            }
        }
    }

    if (vistos < n) {
        cout << "Tem um ciclo no grafo!\n";
    } else {
        for (int i : ordenados) {
            cout << i << " ";
        }
        cout << "\n";
    }
    
    return 0;
}

/*
6 6
5 2
5 0
4 0
4 1
2 3
3 1
Output: 4 5 2 0 3 1 
*/