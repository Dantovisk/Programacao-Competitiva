#include <bits/stdc++.h>    //INCOMPLETO, nao sei pq nao ta rodando todos os casos
#define pii pair<int,int>   //distancia, destino

using namespace std;

priority_queue <pii, vector <pii>, greater <pii>> pq; 
vector<pii> adj[10010];
queue <pii> q;

const int inf = 1e9 + 77;
int bfsDist[10010];
int bfsArest[10010];
int dijArest[10010];
int dijDist[10010];
int vis[10010];
int parent[10010];

void dijkstra(){
    while(!pq.empty()){
        int v = pq.top().second;
        pq.pop();

        if(vis[v]) continue;
        vis[v] = 1;

        for(auto x: adj[v]){
            int u = x.second;
            int w = x.first;
            
            if(!vis[u]){
                if (dijDist[u] > dijDist[v] + w) {
                    parent[u] = v;
                    dijDist[u] = dijDist[v] + w;
                    dijArest[u] = dijArest[v] + 1;
                    pq.push({dijDist[u], u});
                } else if (dijDist[u] == dijDist[v] + w){
                    dijArest[u] = min(dijArest[u], dijDist[v] + w);
                }
            }
        }
    }
}

void bfs(){
    while(!q.empty()){
        int v = q.front().second; 
        q.pop();

        if(vis[v]) continue;
        vis[v] = 1;

        for(auto x: adj[v]){
            int u = x.second;
            int w = x.first;

            if(bfsDist[u] > bfsDist[v] + w && !vis[u]){  // Se encontrar um caminho mais curto
                bfsDist[u] = min(bfsDist[v] + w, bfsDist[u]);
                bfsArest[u] = bfsArest[v] + 1;
                q.push({v, u}); // Adiciona o próximo nó para ser processado
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        adj[b].push_back({c, a});
    }

    for(int i = 2; i <= n; i++){
        bfsDist[i] = inf;
        dijDist[i] = inf;
    }

    bfsDist[1] = 0;
    q.push({0, 1});
    bfs();

    memset(vis, 0, sizeof(vis)); // Reset vis para Dijkstra
    dijDist[1] = 0;
    dijArest[1] = 0;
    pq.push({0, 1});
    dijkstra();

    int maxSum = 0;

    for(int i = 2; i <= n; i++){
        if(bfsDist[i] == inf){
            maxSum = -1;
            break;
        }
        int cont = 0;
        int difDist = bfsDist[i] - dijDist[i];
        int difSum = dijArest[i] - bfsArest[i];
        if(difDist == 0) cont = 0;
        else cont = (difDist % difSum == 0? 0:1) + difDist/ difSum;
        maxSum = max(maxSum, cont);
    }

    cout << maxSum;

    return 0;
}
