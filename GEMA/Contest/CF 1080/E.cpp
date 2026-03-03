#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

vector<vi> adj;
int n; 
vi dp;

int mod = 1e9+7;

int dfs(int u){
    if(adj[u].size() == 0){
        return dp[u] = 1;
    }
    else{
        dp[u] = 3LL + dfs(adj[u][0]) + dfs(adj[u][1]); 
        dp[u] %= mod;
        return dp[u];
    }
}

void dfs2(int u, int acum){
    if(adj[u].size() == 0){
        dp[u] = (dp[u] + acum)%mod;
        return;
    }
    else{
        dp[u] = (dp[u] + acum)%mod;
        dfs2(adj[u][0], dp[u]);
        dfs2(adj[u][1], dp[u]);
    }
}

void solve(){
    cin>>n;


    adj.resize(n+1);
    rep(i, 0, n+1) adj[i].clear();
    dp.resize(n+1, 0);


    rep(i, 1, n+1){
        int a, b; cin>>a>>b;
        if(a==0) continue;
        adj[i].push_back(a);
        adj[i].push_back(b);
    }
    dfs(1);
    dfs2(1, 0);

    rep(i, 1, n+1)cout<<dp[i]<<" ";
    cout<<"\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}