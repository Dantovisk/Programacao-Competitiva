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

const int MAX = 5e5+7;
const int inf = 1e9+7;
vi adj[MAX];
int n, k, vv;

int dfs(int u, int p){
    if(adj[u].size() <= 1) return k;

    vi f;
    
    for(auto v: adj[u]){
        if(p == v) continue;
        f.pb(dfs(v, u));
    }
    
    sort(f.rbegin(), f.rend());
    if(u == vv){
        if(f[0] + f[1] > k) return k;
        return 0;
    }
    
    if(sz(f) > 1){
        if(f[0] + f[1] > k) return k;
        return max(f[0] - 1, 0);
    }
    return max(f[0] - 1, 0);
}

void solve(){
    cin>>n>>k>>vv;

    rep(i, 0, n+1) adj[i].clear();

    rep(i, 0, n-1){
        int a, b; cin>>a>>b;

        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    int kk = dfs(vv, 0);
    if(kk== 0) cout<<"NO\n";
    else cout<<"YES\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}