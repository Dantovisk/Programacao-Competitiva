#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define int long long int

vector <pii> adj[100010]; //peso, destino
priority_queue <pii, vector<pii>, greater <pii>> pq;
int vis [100010];
int weight [100010];
const int inf = 1e14 + 12345;

int32_t main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;

        adj[a].push_back({c, b});
    }

    for(int i=2; i<=n; i++){
        weight[i] = inf;
    }

    pq.push({0, 1});

    while(!pq.empty()){
        auto [w, a] = pq.top();
        pq.pop();
        if(vis[a]) continue;
        vis[a] = 1;

        for(auto x: adj[a]){
            auto [nw, b] = x;
            nw += w;

            if(nw < weight[b]){
                pq.push({nw, b});
                weight[b] = nw;
            }
            
        }
    }

    for(int i=1; i<=n; i++){
        cout<<weight[i]<<" ";
    }

    return 0;
}