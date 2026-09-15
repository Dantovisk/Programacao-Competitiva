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

const int maxn = 2e5+4;
const int inf = 1e9+3;

vector<vi> adj;
int mn[maxn], mx[maxn], cor[maxn];
int da = 1;

void dfs(int u){
    if(sz(adj[u]) == 0){
        mn[u] = mx[u] = cor[u];
        return;
    }
    
    for(auto v: adj[u]){
        dfs(v);    
    }
    mn[u] = mx[u] = mn[adj[u][0]];
    
    vector<pii> fi;
    for(auto v: adj[u]){
        mn[u] = min(mn[u], mn[v]);
        mx[u] = max(mx[u], mx[v]);
        fi.pb({mn[v], mx[v]});
    }

    if(fi.size() == 1) return;
    int err = 0;

    int kk = sz(fi)-1;
    rep(i, 0, kk){
        if(fi[i].ss > fi[i+1].ff) err++;
    }
    if(fi[kk].ss > fi[0].ff) err++;

    if(err > 1) da = 0;
}

void solve(){
    int n; 
    cin>>n;
    da = 1;
    vi par(n+1, 1);

    adj.resize(n+1);

    rep(i, 0, n+1) adj[i].clear();

    rep(i, 2, n+1){
        cin>>par[i];

        adj[par[i]].push_back(i);
    }

    rep(i, 1, n+1) cin>>cor[i];
    dfs(1);

    if(da) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}