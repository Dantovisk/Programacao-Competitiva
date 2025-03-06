// Codeforces Round 916 - F. Programming Competition
// Esse exercicio pode ser resolvido a partir do toposort

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, vistos = 0;  // n = número de vértices, m = número de arestas
    cin >> p;
    while(p--){
        cin >> n;
        vector<vector<int>> adj(n);
        vector<int> pesos(n, 0);
        vector<int> ordenados;  //conforme os vértices são visitados, são adicionados aqui
        queue<int> fila;        //armazena os vértices que podem ser visitados (não dependem de outros vértices)

        int a, b;
        for (int i = 2; i <= n; i++) {
            cin >> a;
            adj[a].push_back(i);
            pesos[i]++;
        }

        //adição dos elementos idependentes:
        for (int i=1; i<=n; i++){
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
    }
    
    
    return 0;
}