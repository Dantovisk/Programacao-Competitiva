#include <bits/stdc++.h> // CSES - Distinct Routes
#define int long long    
using namespace std;

// Solve com edmonds-karp

vector<int> adj[510];
int n, m;
int par[510];

vector<int> adj2[510];
int orig[510][510];

int capacity[510][510];
vector<vector<int>> paths;

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
        // cout<<"caminho: ";
        //pega a aresta minima do caminho aumentador
        while(u != src){
            curr_flow = min(curr_flow, capacity[par[u]][u]);
            // cout<<u<<" ";
            u = par[u];
        }
        // cout<<u<<"\n";
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

vector<int> curr;
bool dfs(int u, int sink){
    // cout<<"estamos em "<<u<<"\n";

    if(u == sink){ //achou
        curr.push_back(u);
        return true;
    }

    curr.push_back(u);
    for(auto v : adj2[u]){
        if(capacity[u][v] < orig[u][v]){
            capacity[u][v] ++;
            if(dfs(v, sink)) return true; // achou um caminho

            //não achou, volta como estava
            capacity[u][v] --;
        }
    }

    //Não achou o caminho por aqui, desfaz 
    curr.pop_back();
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);

        capacity[a][b] = 1;
        orig[a][b] = 1;

        adj2[a].push_back(b); //para facilitar a reconstrução
    }
    
    int total = solve(1, n);
    cout << total << "\n";

    for (int i = 0; i < total; i++) {
        curr.clear();
        dfs(1, n);
        cout << curr.size() << "\n";
        for(auto x : curr) cout << x << " ";
        cout << "\n";
    }

    return 0;
}

