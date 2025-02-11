#include <bits/stdc++.h> //incompleto

#define MAXN 50010

using namespace std;

vector<int> adj[MAXN];
int dp[MAXN][501];

void dfs(int u, int p){
    for(auto v: adj[u]){
        if(v == p) continue;

        dfs(v, u);

        for(int i = 0; i<500; i++){
            dp[u][i+1] += dp[v][i];
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i = 0; i<=n; i++){
        dp[i][0] = 1;
    }

    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);

    int resp;

}