#include <bits/stdc++.h>    //OBI 2023 - Terceira fase
#define pii pair<int,int>   //Provavelmente nao vai passar em todos :c
#define tiii tuple<int,int,int>
#define MAXN 1000010
using namespace std;

const int inf = 1e9 + 77;

//dinheiro gasto até o ponto, ponto de destino, linha utilizada
priority_queue <tiii, vector<tiii>, greater <tiii>> pq;
vector<pii> adj[MAXN]; //destino, linha
vector <int> dist (MAXN, inf);
int linhas[MAXN];
int vis[MAXN];

void dijkstra(int s, int ed){
    pq.push({0, s, 0});
    while(!pq.empty()){
        //int w = get<0>(pq.top());
        int u = get<1>(pq.top());
        int l = get<2>(pq.top());
        pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(auto x: adj[u]){
            int nu = get<0>(x);
            int nl = get<1>(x);

            int peso = dist[u];
            if(l != nl){
                peso += linhas[nl];
            }

            if(peso < dist[nu]){
                dist[nu] = peso;
                pq.push({peso, nu, nl});
            }
        }
    }
}

int main() {
    int n, m, k;
    cin>>n>>m>>k;

    for(int i=1; i<=k; i++){
        cin>>linhas[i];
    }

    for(int i=1; i<=m; i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    int s, ed;
    cin>>s>>ed;
    dist[s] = 0;
    dijkstra(s,ed);

    cout<<(dist[ed] == inf? -1: dist[ed]);
    return 0;
}