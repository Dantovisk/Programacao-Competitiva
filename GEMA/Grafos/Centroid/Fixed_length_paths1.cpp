#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;
typedef vector<int> vi;

const int inf = 1e9+3;
const int maxn = 2e5+3;

vi adj[maxn];
int sz[maxn]; // tam da subarvore
vector<vector<tii>> anc(maxn); // {ancestor, dist}
int rem[maxn]; //se o vertice foi removido
vi cont[maxn];

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

int getdist(int u, int cent, int p, int ds = 1){
    int k = ds;
    for(auto v: adj[u]){
        if(v==p || rem[v]) continue;
        k = max(getdist(v, cent, u, ds+1), k);
    }
    anc[u].push_back({cent, ds, k});
    cont[cent][ds]++;

    return k;
}

void decompose(int u){
    int cent = centroid(u, 0, getsz(u));
    int tot = sz[u]/2 + 2;

    cout<<cent<<"!\n";

    cont[cent].resize(tot, 0);
    cont[cent][0] = 1;

    for(auto v: adj[cent]){
        if(rem[v]) continue;
        getdist(v, cent, cent);
    }

    rem[cent] = 1;(mx >= k-ds? 1: 0)
    for(auto v: adj[cent]){
        if(rem[v]) continue;
        cout<<cent<<" -> ";
        decompose(v);
    }
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
    int n, k;
    cin>>n>>k;

    rep(i, 1, n){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    decompose(1);

    int res = 0;

    rep(i, 1, n+1){

        for(auto [v, ds, mx] : anc[i]){
            if(k - ds < 0 || k - ds >= cont[v].size()) continue;

            cout<<i<<" -> "<<v<<" (ds = "<<ds<<") += "<< cont[v][k-ds] - (ds >= k-ds? 1: 0) + (k-ds == 0 ? 2: 0)<<"\n";
            
            //ta errado, precisa ver a profundidade
            res += cont[v][k-ds] - (mx >= k-ds? 1: 0) + (k-ds == 0 ? 2: 0);

        }
    }

    cout<<res<<"\n";
    cout<<res/2<<"\n";
}