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

int par[maxn];
vector<int> adj[maxn];
int n;

ll res = 0;

int dfs(int u){
    // cout<<"to em"<<u<<"\n";
    res ++;
    int p = 0;
    vi prof = {0};
    for(auto v: adj[u]){
        prof.push_back(dfs(v));
    }
    int mn = inf;

    // cout<<"voltei p/"<<u<<"\n";/

    auto ptr = max_element(all(prof));
    mn = min(mn, *ptr);
    p = max(p, mn);
    *ptr = 0;
    ptr = max_element(all(prof));
    mn = min(mn, *ptr);

    // cout<<"mn = "<<mn<<'\n';
    res += mn;

    return p+1;
}

void solve(){
    cin>>n;
    rep(i, 0, n+2) adj[i].clear();
    res = 0;

    rep(i, 2, n+1){
        cin>>par[i];
        adj[par[i]].pb(i);
    }

    dfs(1);
    cout<<res<<'\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}