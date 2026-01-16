#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9+3;
const int maxn = 2e5+3;

vi adj[maxn];
int sz[maxn]; // tam da subarvore
int res[maxn]; // dist minima pra um nó pintado
vector<vector<pii>> anc(maxn); // {ancestor, dist}
int rem[maxn]; //se o vertice foi removido


int getsz(int u, int p = 0){
    int a = 1;
    for(auto v: adj[u]){
        if(v == p || rem[v]) continue;
        a += getsz(v, u);
    }
    return sz[u] = a;
}

int centroid(int u, int p, int n){
    for(auto v: adj[u]){
        if(v == p || rem[v]) continue;
        if(sz[v] > n/2) return centroid(v, u, n);
    }
    return u;
}

void getdist(int u, int cent, int p, int ds = 1){
    for(auto v: adj[u]){
        if(v==p || rem[v]) continue;
        getdist(v, cent, u, ds+1);
    }
    anc[u].push_back({cent, ds});
}

void decompose(int u){
    int cent = centroid(u, 0, getsz(u));

    for(auto v: adj[cent]){
        if(rem[v]) continue;
        getdist(v, cent, cent);
    }

    rem[cent] = 1;
    for(auto v: adj[cent]){
        if(rem[v]) continue;
        decompose(v);
    }
}

void paint(int u){
    res[u] = 0;
    for(auto &[v, d] : anc[u]){
        res[v] = min(d, res[v]);
    }
}

int query(int u){
    int k = res[u];
    for(auto &[v, d] : anc[u]){
        k = min(d + res[v], k);
    }
    return k;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n, q;
    cin>>n>>q;

    rep(i, 0, n+1) res[i] = inf;

    rep(i, 1, n){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    decompose(1);
    paint(1);
    
    rep(i, 0, q){
        int t, u;
        cin>>t>>u;

        if(t == 1){
            paint(u);
        }
        else{
            cout<<query(u)<<"\n";
        }
    }
}