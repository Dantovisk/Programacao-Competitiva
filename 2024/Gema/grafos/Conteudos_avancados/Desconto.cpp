// CSES Problem Set - Flight Discount
// TLE em um dos casos de teste - Falta resolver
#include <bits/stdc++.h>

using namespace std;

//int vis[100010];
priority_queue<pair<long long int,int>, vector <pair<long long int, int>>,  greater<pair<long long int,int>>> fila; //peso, destino
vector<vector<pair<long long int,int>>> adj(100010); //adj.first -> peso da aresta e second-> destino
vector<long long int> dist(100010, 100000000000000000);
vector<long long int> dist2(100010, 100000000000000000); 
int n, m;

void dijkstra(){
    fila.push({0,1});
    dist[1] = 0;

    while(!fila.empty()){
        long long int d = fila.top().first;
        long long int u = fila.top().second;
        fila.pop();

        if (d > dist[u]) continue;

        for(auto x: adj[u]){
            long long int v = x.second;
            long long int w = x.first;

            if (dist[u] + w < dist[v]) { //preco minimo sem desconto
                dist[v] = dist[u] + w;
                fila.push({dist[v], v});
            }
            
            if (dist[u] + w / 2 < dist2[v]) {  //preco minimo com desconto
                dist2[v] = dist[u] + w / 2;
                fila.push({dist2[v], v});
            }
            
            if (dist2[u] + w < dist2[v]) {  //preco minimo com desconto
                dist2[v] = dist2[u] + w;
                fila.push({dist2[v], v});
            }
        }
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {   //esse grafo eh direcionado
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
    }
    
    //neste exercicio consideraremos o caminho entre os vertices 1 e n
    dijkstra();

    cout<< min(dist[n], dist2[n]);
    return 0;
}

