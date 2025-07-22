#include <bits/stdc++.h> //CSES - School Dance
#define int long long    // Questão de bipartite matching
using namespace std;

// Solve com edmonds-karp

vector<int> adj[1010];
int n, m, k;
int par[1010];

int capacity[1010][1010];

//retorna true se tem caminho aumentador
bool bfs(int src, int sink){
    queue<int> q;
    memset(par, -1, sizeof(par));
    q.push(src);
    par[src] = -2;

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

    cin>>n>>m>>k;
    
    for(int i=0; i<k; i++){
        int a, b;
        cin>>a>>b;
        b+=n;

        adj[0].push_back(a);          // source -> menina
        adj[a].push_back(0);          // reversa

        adj[a].push_back(b);          // menina -> menino
        adj[b].push_back(a);          // reversa

        adj[b].push_back(n+m+1);      // menino -> sink
        adj[n+m+1].push_back(b);      // reversa

        capacity[a][b] += 1;
    }
    for(int i = 1; i<=n; i++)
        capacity[0][i] = 1;
    
    for(int i = 1; i<=m; i++)
        capacity[i+n][n+m+1] = 1;
    
    cout << solve(0, n+m+1)<<"\n";

    for(int i =1; i<=n; i++){
        for(int j = n+1; j<=n+m; j++){
            if(capacity[j][i]){
                cout<<i<<" "<<j-n<<"\n";
            }
        }
    }

    return 0;
}

