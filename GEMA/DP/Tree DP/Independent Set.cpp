#include <bits/stdc++.h>    //atcoder - Independent Set
#define MAXN 100010
#define int long long int

const int mod = 1e9+7;

using namespace std;

//nao pode pintar dois nós adjascentes de preto
vector<int> adj[MAXN];
int dp[MAXN][2];    //0 pra branco e 1 pra preto

void dfs(int u, int p){
    dp[u][0] = 1;
    dp[u][1] = 1;
    for(int v: adj[u]){
        if(v==p) continue;
        dfs(v, u);

        dp[u][0] *= (dp[v][0] + dp[v][1])%mod; 
        dp[u][1] *= dp[v][0]; 
        dp[u][0] %= mod;
        dp[u][1] %= mod;
    } 
}

int32_t main(){
    int n;
    cin>>n;

    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);

    cout<<(dp[1][0] + dp[1][1]) % mod<<"\n";

    return 0;
}