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

const int maxn = 2e5+7;

vi adj[maxn];
int ct[maxn][3];

void dfs(int u, int p){
    
    int cont = 0;

    for(auto v: adj[u]){
        if(p == v) continue;
        dfs(v, u);
        cont ++;
    }
    
    ct[u][1] = 1;

    if(cont == 0){
        return;
    }

    else{
        int base = cont % 3;
        int dois = 0;
        int um = 0;

        for(auto v: adj[u]){
            if(p == v) continue;

            if(ct[v][2] > 0){
                if(um) dois++;
                else um++;
            }

            if(ct[v][0] > 0){
                if(dois) um++;
                else dois++;
            }
        }
        ct[u][base] = 1;

        if(um) ct[u][(base+1)%3] = 1;
        if(dois) ct[u][(base+2)%3] = 1;
    }
}

void solve(){
    int n; cin>>n;

    rep(i, 0, n+1) {
        adj[i].clear();
        rep(j, 0, 3) ct[i][j] = 0;
    }

    rep(i, 1, n){
        int a, b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }

    dfs(1, 0);

    if(ct[1][0]) cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}