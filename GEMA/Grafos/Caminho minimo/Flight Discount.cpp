#include <bits/stdc++.h>

#define int long long int
#define pii pair<int, int>
#define tiii tuple<int, int, int>

using namespace std;

vector <pii> adj[100010];   //peso, destino
int dist[100010][2];    // 0->sem cupom, 1-> com cupom
const int inf = 1e15 + 12345;

// {dist , destino, 0 -> sem cupom e 1-> com cupom}
priority_queue <tiii, vector<tiii>, greater<tiii>> pq;

int32_t main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;

        adj[a].push_back({c, b});
    }

    for(int i=2; i<=n; i++)
        dist[i][0] = dist[i][1] = inf;

    pq.push({0, 1, 0});

    while(!pq.empty()){
        auto [w0, u, cp] = pq.top();
        pq.pop();

        if(w0 > (cp == 0 ? dist[u][0] : dist[u][1])) continue;

        for(auto [w, v] : adj[u]){
            if(cp == 0){
                if(w0 + w  < dist[v][0]){
                    dist[v][0] = w0 + w;
                    pq.push({dist[v][0], v, 0});
                }
                if(w0 + (w/2) < dist[v][1]){
                    dist[v][1] = w0 + (w/2);
                    pq.push({dist[v][1], v, 1});
                }
            }
            else if (w0 + w < dist[v][1]){
                dist[v][1] = w0 + w;
                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout<<dist[n][1]<<"\n";

    return 0;
}