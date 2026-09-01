#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 2e5+3;

vi base[maxn][20];
int par[maxn][20];

void add(int x, int i, int lv){
    for(auto k: base[i][lv]){
        x = min(x, (x^k));
    }

    if(x) base[i][lv].push_back(x);
}

bool add(ll x, vi & bas){
    for(auto k: bas){
        x = min(x, (x^k));
    }

    if(x) {
        bas.push_back(x);
        return true;
    }
    return false;
}

int a[maxn];
vi adj[maxn];
int prof[maxn];

void dfs(int u){
    for(auto v: adj[u]){
        if(v == par[u][0]) continue;
        par[v][0] = u;
        prof[v] = prof[u] + 1;
        dfs(v);
    }
}

vi lca(int u, int v){
    vi aux;
    add(a[u], aux);
    add(a[v], aux);

    if(prof[v] > prof[u]) swap(u, v);

    for(int i = 18; i>= 0; i--){
        if(prof[par[u][i]] >= prof[v]){
            vi dif = base[u][i];
            u = par[u][i];
            for(auto k: dif) add(k, aux);
        }
    }

    
    for(int i = 18; i>= 0; i--){
        if(par[u][i] != par[v][i]){
            vi dif = base[u][i];
            vi dif2 = base[v][i];
            u = par[u][i];
            v = par[v][i];
            for(auto k: dif) add(k, aux);
            for(auto k: dif2) add(k, aux);
        }
    }
    if(u != v) {
        for(auto xd: base[u][0])
            add(xd, aux);
    }
    return aux;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin>>n;

    rep(i, 1, n+1) cin>>a[i];
    rep(i, 0, n-1){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    par[1][0] = 0;
    prof[0] = -1;
    dfs(1);

    rep(i, 1, n+1){
        add(a[par[i][0]], i, 0);
    }

    for(int lv = 1; lv< 19; lv++){
        rep(i, 1, n+1){
            par[i][lv] = par[par[i][lv-1]][lv-1];
            base[i][lv] = base[i][lv-1];

            for(auto x: base[par[i][lv-1]][lv-1]){
                add(x, i, lv);
            }
        }
    }

    int q; cin>>q;

    rep(i, 0, q){
        int u, v;
        cin>>u>>v;

        vi bas = lca(u, v);
        int k; cin>>k;

        if(!add(k, bas)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}
