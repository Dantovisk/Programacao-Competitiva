#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

const int maxn = 5e5+4;
const int inf = 1e9+3;

vi adj[maxn];
int par[maxn];
int dp[maxn];
int best = inf; // 0 joga primeiro, 1 joga dps
int mx; // o primeiro cara quer garantir que tudo vá até mx

void dfs(int u){
    if(adj[u].size() == 0){
        if(mx >= u){
            dp[u] =  1;
        }
        else {
            dp[u] = -1;
        }
        return;
    }

    
    int aux = 0;
    for(auto v: adj[u]){
        dfs(v); 

        aux += dp[v];
    }

    if(aux > 0) aux = 1;
    if(aux < 0) aux = -1;
    dp[u]= aux;
}

void solve(){
    int n; 
    cin>>n;

    rep(i, 2, n+1){
        cin>>par[i];
        adj[par[i]].push_back(i);
    }

    int l = 1, r = n+1;
    while(l < r){
        // memset(dp, 0, sizeof(dp));
        int m = (l+r)/2;
        mx = m;
        // cout<<"testando "<<m<<"\n";

        dfs(1);
        if(dp[1] >= 0){
            best = m;
            r = m;
            // cout<<"da!\n";
        }
        else{
            l = m+1;
            // cout<<"nao da!\n";
        }
    }
    cout<<best<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}