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

const int MAX = 2e5+7;

int prof[MAX];
int mprof[MAX];
vi adj[MAX];
ll dp[MAX][2];

ll sum[MAX];
ll v[MAX];
ll acum[MAX];
ll res[MAX];

void dfs(int u, int p){
    sum[u] = v[u];
    acum[u] = 0;
    mprof[u] = prof[u];

    priority_queue<pii> mxprof;
    priority_queue<pii> mxdp;

    for(auto v: adj[u]){
        if(p == v) continue;
        prof[v] = prof[u] +1;
        dfs(v, u);
        sum[u] += sum[v];
        acum[u] += acum[v];
        mprof[u] = max(mprof[u], mprof[v]);
    }
    // cout<<"To no "<<u<<"\n";
    dp[u][0] = acum[u];

    dp[u][1] = 0;
    for(auto v: adj[u]){
        if(p == v) continue;
        dp[u][1] = max(dp[u][1], acum[u] +dp[v][1] -acum[v]);
        mxprof.push({mprof[v], v});
        mxdp.push({sum[v], v});
    }

    acum[u]+= sum[u];
    res[u] = max({res[u], dp[u][0], dp[u][1]});

    if(sz(mxprof) <= 1) {
        dp[u][0] += sum[u];
        dp[u][1] += sum[u];
        return;
    }

    int a1 = mxprof.top().ss; mxprof.pop();
    int a2 = mxprof.top().ss; mxprof.pop();

    int b1 = mxdp.top().ss; mxdp.pop();
    int b2 = mxdp.top().ss; mxdp.pop();

    if(a1 != b1){
        ll aux = 0;

        aux = dp[u][0] + (sum[b1]*(mprof[a1]-prof[b1]+1));

        dp[u][1] = max(dp[u][1], aux);
    }
    else{
        ll aux = 0;

        aux = dp[u][0] + (sum[b1]*(mprof[a2]-prof[b1]+1));

        dp[u][1] = max(dp[u][1], aux);

        aux = dp[u][0] + (sum[b2]*(mprof[a1]-prof[b2]+1));

        dp[u][1] = max(dp[u][1], aux);
    }

    res[u] = max({res[u], dp[u][0], dp[u][1]});

    dp[u][0] += sum[u];
    dp[u][1] += sum[u];

}


void solve(){
    int n; 
    cin>>n;

    memset(dp, 0, sizeof(int)*(2*n+1));
    fill(res, res+n+1, 0);

    rep(i, 0, n+1) {
        adj[i].clear();
    }

    rep(i,1, n+1) cin>>v[i];
    prof[1] = 0;

    rep(i, 0, n-1){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, -1);

    for(int i =1; i<=n; i++){
        cout<<res[i]<<" ";
    }

    cout<<"\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}