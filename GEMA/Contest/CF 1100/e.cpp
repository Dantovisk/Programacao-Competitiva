#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

const int maxn = 2e5+4;
const int inf = 1e9+3;
const ll mod = 998244353;

vi adj[maxn];
ll dp[maxn];
ll pref[maxn];
int mxsub[maxn];
int mxleaf = 0;

void dfs(int u, int p){
    for(auto v: adj[u]){
        if(v == p) continue;

        dfs(v, u);
        mxsub[u] = max({mxsub[u], mxsub[v], v});
    }

    if(sz(adj[u]) == 1) mxleaf = max(mxleaf, u);
}

ll dfs2(int u, int p, int mx){
    ll res = (u > mx ? dp[u] : 0);
    for(auto v: adj[u]){
        if(v == p) continue;

        res = (res + dfs2(v, u, mx))%mod;
    }
    return res;
}

void solve(){
    int n; cin>>n;

    mxleaf = 0;
    rep(i, 0, n+1){
        adj[i].clear();
        mxsub[i] = 0;
        dp[i] = 0;
        pref[i] = 0;
    }

    rep(i, 0, n-1){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(n, 0);
    dp[mxleaf] = pref[mxleaf] = 1;

    rep(i, 1, n){
        ll inc = 0;
        if(mxsub[i] < i){
            inc = (pref[i-1] - pref[mxsub[i]] + mod)%mod;
        }
        dp[i] = (dp[i] + inc + mod) %mod;
        pref[i] = (pref[i-1] + dp[i])%mod;
    }
    vector<pii> qtd;
    for(auto v: adj[n]){
        qtd.push_back({max(mxsub[v], v), v});
    }
    if(sz(qtd) == 1){
        cout<<"1\n";
        return;
    }
    sort(all(qtd));
    reverse(all(qtd));

    dp[n] = dfs2(qtd[0].ss, n, qtd[1].ff);

    cout<<dp[n]<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}