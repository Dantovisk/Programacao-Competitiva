#include <bits/stdc++.h>
using namespace std;

const int MAX = 505;

// EDMONDS KARP
int n, m;
int s, t;
vector<int> adj[MAX];
long long cap[MAX][MAX]; // mantem a capacidade da aresta (a, b)
int par[MAX]; // Define o pai de cada vertice em um caminho aumentador
const long long inf = 1e13 + 5;

bool reach(int u){
    if(u == t) return true; // cheguei no destino
    bool res = false;

    for(auto v: adj[u]){
        if(par[v] != -1) continue; // já visitei
        if(cap[u][v] <= 0) continue; // aresta sem capacidade

        par[v] = u;
        res = (res or reach(v)); //verifica se algum dos filhos leva ao destino
    }
    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0); // para facilitar a visualização
    cin >> n >> m;
    cin >> s >> t;

    //Lê o grafo
    for(int i = 0; i<m; i++){
        int a, b, w;
        cin>>a>>b>>w;

        adj[a].push_back(b);
        adj[b].push_back(a);

        cap[a][b] += w;
    }

    memset(par, -1, sizeof(par));
    par[s] = 0;
    long long flow = 0; // mantem o fluxo total da rede;
    
    while(reach(s)){
        //sabe que existe um caminho, então traça de trás para frente
        int u = t;
        long long currCap = inf;
        while(u != s){ //encontra a capacidade minima do caminho
            currCap = min(currCap, cap[par[u]][u]);
            u = par[u];
        }

        u = t;
        while(u != s){ //altera as capacidades
            cap[par[u]][u] -= currCap;
            cap[u][par[u]] += currCap;
            u = par[u]; 
        }

        //Atualiza o fluxo da rede
        flow += currCap;
        //Reseta o vetor de pais
        memset(par, -1, sizeof(par));
        par[s] = 0;
    }

    cout<<flow<<"\n";
}
