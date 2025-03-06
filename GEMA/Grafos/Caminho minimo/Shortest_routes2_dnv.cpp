#include <bits/stdc++.h>

using namespace std;

#define int long long int

int adj[510][510];
int dist[510][510];

const int inf = 1e14 + 777;

int32_t main(){
    int n, m, q;
    cin>>n>>m>>q;

    memset(adj, -1, sizeof(adj));

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;

        adj[a][b] = (adj[a][b] == -1 ? c : min(adj[a][b], c));
        adj[b][a] = (adj[b][a] == -1 ? c : min(adj[b][a], c));
    }

    //preprocessamento
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j) dist[i][j] = 0;
            else if (adj[i][j] == -1) dist[i][j] = inf;
            else dist[i][j] = adj[i][j];
        }
    }

    //floyd-warshall

    //intermediario
    for(int k=1; k<=n; k++){
        //inicio
        for(int i=1; i<=n; i++){
            //destino
            for(int j=1; j<=n; j++){
                dist[i][j] = min(dist[i][j],
                dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        cout<<(dist[a][b] == inf? -1 : dist[a][b])<<"\n";
    }

    return 0;
}