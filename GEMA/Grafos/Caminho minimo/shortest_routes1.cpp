#include <bits/stdc++.h>    //Shortest routes I - CSES
//exercicio simples de dijkstra

using namespace std;

#define ll long long int 
#define pii pair<ll,int> 
const ll inf = 1e17+9;

int vis[200010];
vector <pii> adj[200010]; //peso, destino
priority_queue <pii, vector<pii>, greater<pii>> pq; //peso, destino
vector <ll> pesos (200010, inf);
int n, m;

void dijkstra(){
    pesos[1] = 0;
    pq.push({0,1});

    while(!pq.empty()){
        ll w = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if(vis[v]) continue;
        vis[v] = 1;

        for(auto x: adj[v]){
            ll u = x.second, nw = w+x.first;

            if(nw < pesos[u]){
                pesos[u] = nw;
                pq.push({nw, u});
            }
            
        }
    }
}

int main() {
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {   //esse grafo eh direcionado
        cin >> a >> b >> c;
        adj[a].push_back({c,b});
    }

    dijkstra();

    for(int i=1; i<=n; i++) cout<<pesos[i]<<" ";
    
}

