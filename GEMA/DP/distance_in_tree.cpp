#include <bits/stdc++.h> //INCOMPLETO

using namespace std;

int dp [50010][510];
int n, m;
vector <int> adj[50010];

void dfs(int v, int parent, int k){
    int cont = 0;
    for(int x: adj[v]){
        if(x != parent){
            dfs(x, v, k);
            cont+=dp[x][k-1];
        }
    }
    dp[v][k] = cont;
}

int main(){
    cin>>n>>m;

    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        dp[i][0]=1;
    }

    for(int i=1; i<=m; i++){
        dfs(1, 0, i);
    }
    int resp = 0;
    for(int i=1; i<=n; i++){
        resp+=dp[i][m];
    }
    resp/=2;
    cout<<resp;
    return 0;
}