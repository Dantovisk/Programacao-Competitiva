#include <bits/stdc++.h>

#define int long long int
#define pii pair<int, int>

using namespace std;

vector <pii> adj[100010];   //peso, destino
multiset <int> dist[100010];    // 0->sem cupom, 1-> com cupom
const int inf = 1e15 + 12345;

// {dist , destino}
priority_queue <pii, vector<pii>, greater<pii>> pq;

int32_t main(){
    int n, m, k;
    cin>>n>>m>>k;

    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;

        adj[a].push_back({c, b});
    }

    for(int i=2; i<=n; i++)
        dist[i].insert(inf);

    pq.push({0, 1});

    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();

        if(dist[u].size() >= (unsigned)k){
            if(w > *(dist[u].rbegin())) continue;
        }

        for(auto x: adj[u]){
            auto [nw, v] = x;
            if(dist[v].size() >= (unsigned)k){
                if(w + nw >= *(dist[v].rbegin())) continue;

                dist[v].erase(prev(dist[v].end()));
            }
                
            pq.push({nw+w, v});
            dist[v].insert(nw + w);
        }
    }

    for(auto x : dist[n]) cout<<x<<" ";

    return 0;
}