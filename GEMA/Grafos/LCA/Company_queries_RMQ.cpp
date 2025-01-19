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

    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;

    }

    return 0;
}