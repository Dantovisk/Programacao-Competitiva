#include <bits/stdc++.h> //CSES - Download Speed
#define int long long
#define pii pair<int, int>
using namespace std;
// Vamo ver se edmonds-karp passa
// Atualização: passou :D

vector<int> adj[510];
int n, m;
int par[510];

int capacity[510][510];

//retorna true se tem caminho aumentador
bool bfs(int src, int sink){
    queue<int> q;
    memset(par, -1, sizeof(par));
    q.push(src);

    while(!q.empty()){
        auto u = q.front();
        q.pop();

        for(auto v: adj[u]){
            int w = capacity[u][v];
            if(w <= 0 || par[v] != -1) continue;

            par[v] = u;
            q.push(v);
        }
    }
    return par[sink] != -1;
}


int solve(int src, int sink){
    int flow = 0;

    while(bfs(src, sink)){
        int curr_flow = LLONG_MAX;
        int u = sink;

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

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back(b);
        adj[b].push_back(a);
        capacity[a][b] += c;
    }

    cout << solve(1, n)<<"\n";

    return 0;
}

