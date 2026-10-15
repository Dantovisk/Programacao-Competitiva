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

const int maxn = 1e5+4;
const int inf = 1e9+3;

vi adj[maxn];
int vis[maxn];

int mx = 0;

void dfs(int u){
    vis[u] = 1;

    for(auto v: adj[u]){
        if(v > mx or vis[v]) continue;
        dfs(v);
    }
}

void solve(){
    int n, m; 
    cin>>n>>m;

    rep(i, 0, m){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    int l = 2, r = n+1;
    int best = inf;
    while(l < r){
        fill(vis, vis+n+1, 0);
        int m = (l+r)/2;
        mx = m;

        dfs(1);
        if(vis[2]) {
            best = m;
            r = m;
        }
        else{
            l = m+1;
        }
    }

    cout<<(best < inf? best : -1)<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}