#include <bits/stdc++.h> //Codeforces - E. Tree Painting
#define MAXN 200010
#define int long long
#define pii pair <int,int>
using namespace std;

const int inf = 1e6+1;

vector<int> adj[MAXN];
int n;
int resp = 0;
int sz[MAXN]; //tamanho da subarvore enraizada em i
int dp[MAXN];

//só pra calcular os tamanhos dos conjuntos a partir da raiz 1
void dfs1(int u, int p){
    sz[u] = 1;
    for(auto v: adj[u]){
        if(v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
    }
}

//só pra a dp a partir da raiz 1
void dfs2(int u = 1, int p = 0){
    dp[u] = sz[u];
    for(auto v: adj[u]){
        if(v == p) continue;
        
        dfs2(v, u);
        dp[u] += dp[v];
    }
}

//Agora iremos re-enraizar a dp
void dfs3(int u = 1, int p = 0){
    resp = max(resp, dp[u]);

    for(auto v: adj[u]){
        if(v == p) continue;
        
        //mudando a raiz para v

        //retira a subarvore de v da subarvore de u
        dp[u] -= dp[v];
        dp[u] -= sz[v];
        sz[u] -= sz[v];

        //adiciona u em v
        sz[v] += sz[u];
        dp[v] += sz[u];
        dp[v] += dp[u];

        dfs3(v, u);
        
        //raiz volta a ser u

        //retira a subarvore de u da subarvore de v
        dp[v] -= dp[u];
        dp[v] -= sz[u];
        sz[v] -= sz[u];

        //adiciona v em u
        sz[u] += sz[v];
        dp[u] += sz[v];
        dp[u] += dp[v];
    }
}

int32_t main(){
    cin>>n;

    for(int i = 1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2();
    dfs3();

    cout<<resp<<"\n";

    return 0;
}