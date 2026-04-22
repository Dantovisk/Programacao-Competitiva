#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+7;

//INFORMAÇÕES PARA O DIJKSTRA
int n, m;
long long dist[MAX]; //distancia mínima para a cidade
int qtd[MAX]; //quantidade de formas mínimas de chegar na cidade
int maxct[MAX]; // quantidade máxima de arestas no caminho mínimo
int minct[MAX]; // quantidade mínima de arestas no caminho mínimo
vector<pair<int, int>> adj[MAX];

const long long mod = 1e9+7, inf = 1e14+3;

//pares que representam {distancia total até a cidade, cidade destino}
typedef pair<long long, int> dkpair;

//Minheap de pares
priority_queue <dkpair, vector<dkpair>, greater<dkpair>> pq;

// Faremos um dijkstra modificado para resolver a questão
void dijkstra(){
    //INICIALIZAÇÃO
    for(int i = 2; i<=n; i++){
        dist[i] = inf;
    }
    dist[1] = 0;
    pq.push({0, 1});
    qtd[1] = 1;

    while(!pq.empty()){
        auto[ds, u] = pq.top();
        pq.pop();

        // já visitei o nó atual
        if(ds > dist[u]) continue;

        for(auto[v, w]: adj[u]){
            //achei um caminho melhor
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                qtd[v] = qtd[u];
                minct[v] = minct[u] + 1;
                maxct[v] = maxct[u] + 1;
                pq.push({dist[v], v});
            }
            //achei um outro caminho que satisfaz as condições
            else if(dist[u] + w == dist[v]){
                qtd[v] = (qtd[u] + qtd[v])%mod;
                minct[v] = min(minct[u] + 1, minct[v]);
                maxct[v] = max(maxct[u] + 1, maxct[v]);
            }
        }
    }
    cout<<dist[n]<<" "<<qtd[n]<<" "<<minct[n]<<" "<<maxct[n]<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    
    // Lê a entrada
    // Permite várias arestas entre um mesmo par de nós
    for(int i = 0; i< m; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj[a].push_back({b, w});
    }


    dijkstra();
}