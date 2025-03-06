// CSES Problem Set - Flight Discount
// TLE em um dos casos de teste - Falta resolver
#include <bits/stdc++.h>
#define lli long long int
#define tiii tuple<lli, int, int>
using namespace std;
const lli inf = 1e17 +1234;


//int vis[100010];
priority_queue<tiii, vector <tiii>,  greater<tiii>> fila; //peso, destino
vector<vector<pair<lli,int>>> adj(100010); //adj.first -> peso da aresta e second-> destino
vector<lli> dist(100010, inf); //sem cupons
vector<lli> dist2(100010, inf); //com cupons
int n, m;

void dijkstra(){
    fila.push({0,1,0});
    dist[1] = 0;

    while(!fila.empty()){
        lli d = get<0>(fila.top());   //distancia
        int u = get<1>(fila.top());
        int cupom = get<2>(fila.top());
        fila.pop();

        if (d > dist[u] && cupom == 0) continue;
        if (d > dist2[u] && cupom == 1) continue;

        for(auto x: adj[u]){
            int v = x.second;
            lli w = x.first;

            if (dist[u] + w < dist[v]) { //preco minimo sem desconto
                dist[v] = dist[u] + w;
                fila.push({dist[v], v, 0});
            }
            
            if (dist[u] + w / 2 < dist2[v] || dist2[u] + w < dist2[v]) {  //preco minimo com desconto
                dist2[v] = min(dist[u] + w / 2, dist2[u] + w);
                fila.push({dist2[v], v, 1});
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

