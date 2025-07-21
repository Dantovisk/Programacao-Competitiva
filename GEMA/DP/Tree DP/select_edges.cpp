#include <bits/stdc++.h>
#define MAXN 300010
#define int long long
#define pii pair <int,int>
using namespace std;

const int inf = 1e18+7;
int quant[MAXN];
vector<pii> adj[MAXN];
int n;
int dp[MAXN][2]; // dp[i][0] -> usa até quant[i] arestas incidentes a i
                 // dp[i][1] -> usa até quant[i]-1 arestas

void solve(int u, int p){
    vector<int> r;

    for(auto [v, w]: adj[u]){
        if(v == p) continue;
        solve(v, u);

        //adiciona as subarvores com todas as arestas
        dp[u][0] += dp[v][0];
        dp[u][1] += dp[v][0];

        //caso queira trocar uma aresta da subarvore pela aresta do pai
        r.push_back(dp[v][1] - dp[v][0] + w);

    }


    sort(r.rbegin(), r.rend());

    for(int i =0; i<(int)r.size(); i++){
        if(r[i] <=0) break;

        //vamos adicionando as arestas incidentes
        if(i < quant[u]-1) dp[u][1] += r[i];
        if(i < quant[u])   dp[u][0] += r[i];
    }

    if(quant[u] <= 0) dp[u][1] = -inf;
    
}

int32_t main(){
    
    cin>>n;

    for(int i = 1; i<=n; i++){
        cin>>quant[i];
    }

    for(int i = 1; i<n; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }

    solve(1, -1);
    cout<<max(dp[1][0], dp[1][1])<<"\n";

    return 0;
}