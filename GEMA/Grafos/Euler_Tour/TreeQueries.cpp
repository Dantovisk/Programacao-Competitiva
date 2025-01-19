#include <bits/stdc++.h> //Tree Queries - Codeforces
#define MAXN 200010

using namespace std;

vector <int> adj[MAXN];
int parent[MAXN];
int tempo = 0;
int tin[MAXN], tout[MAXN];

void dfs(int u, int p){
    tin[u] = ++tempo;
    parent[u] = p;

    for(int x: adj[u]){
        if(x!=p) dfs(x, u);
    }

    tout[u] = ++tempo;
}

void solve(){
    int a; cin>>a;
    vector <pair<int, int>> query;
    for(int k=0; k<a; k++){
        int b; cin>>b;
        query.push_back({tin[parent[b]], tout[parent[b]]});
    }
    sort(query.begin(), query.end());

    int u= -1, v = 2 * MAXN;
    for(auto x: query){
        int in = x.first;
        int out = x.second;
        if(in<u || out>v){
            cout<<"NO\n";
            return;
        }
        u = in;
        v = out;
    }
    cout<<"YES\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    cin>>n>>m;

    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    parent[1] = 1;

    dfs(1, 1);

    for(int i=0; i<m; i++){
        solve();
    }
    
    return 0;
}