#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

// edmonds-karp
vector<ll> adj[510];
ll n, m;
ll par[510];

ll capacity[510][510];

//retorna true se tem caminho aumentador
bool bfs(ll src, ll sink){
    queue<ll> q;
    memset(par, -1, sizeof(par));
    q.push(src);

    while(!q.empty()){
        auto u = q.front();
        q.pop();

        for(auto v: adj[u]){
            ll w = capacity[u][v];
            if(w <= 0 || par[v] != -1) continue;

            par[v] = u;
            q.push(v);
        }
    }
    return par[sink] != -1;
}


ll solve(ll src, ll sink){
    ll flow = 0;

    while(bfs(src, sink)){
        ll curr_flow = 2e16+7;
        ll u = sink;

        //pega a aresta minima do caminho aumentador
        while(u != src){
            curr_flow = min(curr_flow, capacity[par[u]][u]);
            u = par[u];
        }

        u = sink;

        while(u != src){
            capacity[par[u]][u] -= curr_flow;
            capacity[u][par[u]] += curr_flow;
            u = par[u];
        }

        flow+= curr_flow;
    }
    return flow;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    
    for(ll i=0; i<m; i++){
        ll a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] += c;
    }

    cout << solve(1, n)<<"\n";

    return 0;
}

