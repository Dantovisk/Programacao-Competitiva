#include <bits/stdc++.h> // resolveremos com LCA por Binary Lifting
#define MAXN 200010

using namespace std;

vector <int> adj[MAXN];
int ances [MAXN][20];
int level[MAXN];

void dfs(int u, int p){
    ances[u][0] = p;

    for(auto v: adj[u]){
        if(v != p){
            level[v] = level[u] + 1;
            dfs(v, u);
        }
    }
}

int lca(int a, int b){
    if (level[b] > level[a]) swap(a, b);

    for(int i = 18; i>=0; i--){
        if(level[a] - (1<<i) >= level[b]) a = ances[a][i];
    }

    if(a==b) return a;

    for(int i=18; i>=0; i--){
        if(ances[a][i]!=-1 && ances[b][i]!=-1 && ances[a][i] != ances[b][i]){
            a = ances[a][i];
            b = ances[b][i];
        }
    }

    return ances[a][0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; 
    cin>>n>>q;

    for(int i=2; i<=n; i++){
        int a;
        cin>>a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    memset(ances, -1, sizeof(ances));

    level[1] = 0;

    dfs(1, -1);

    //pré processamento
    for(int i=1; i<20; i++){
        for(int j=2; j<=n; j++){
            if(ances[j][i-1] == -1) continue;
            ances[j][i] = ances[ances[j][i-1]][i-1];
        }
    }

    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        cout<<lca(a, b)<<"\n";
    }

    return 0;
}