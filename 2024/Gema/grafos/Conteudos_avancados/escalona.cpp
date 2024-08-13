//OBI - Pratique - Escalonamento ótimo
//Esse exercício pode ser resolvido utilizando toposort

#include <bits/stdc++.h>

using namespace std;

vector<int> ordenados;  //conforme os vértices são visitados, são adicionados aqui
queue<int> fila;        //armazena os vértices que podem ser visitados (não dependem de outros vértices)

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

    //adição dos elementos idependentes:
    for (int i=0; i<n; i++){
        if(pesos[i]==0){
            fila.push(i);
        }
    }

    //realização do toposort
    while(!fila.empty()){
        int k = fila.front();
        fila.pop();
        ordenados.push_back(k);
        vistos++;

        for(int x: adj[k]){
            pesos[x]--;
            if(pesos[x]==0) fila.push(x);
        }

    }

    if (vistos < n) {   //caso haja ciclos no grafico
        cout << "*";
    } else {
        for (int i : ordenados) {
            cout << i << "\n";
        }
    }
    
    return 0;
}