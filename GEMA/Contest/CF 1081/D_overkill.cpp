#include <bits/stdc++.h> //Um imenso overkill
using namespace std;     //No qual eu MINIMIZEI ao invés de MAXIMIZAR :c

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
// const int inf = 1e9+7;


/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Source: own work
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 *  Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 * Status: stress-tested
 */

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};

ll prof[MAX];
ll sz[MAX];
vi adj[MAX];
ll sum[MAX];
ll v[MAX];
ll acum[MAX];
vector<Line> sla[MAX];
ll res[MAX];

void dfs(int u, int p){
    sz[u] = 1;
    sum[u] = v[u];
    acum[u] = 0;
    for(auto v: adj[u]){
        if(p == v) continue;
        prof[v] = prof[u] +1;
        dfs(v, u);
        sz[u] += sz[v];
        sum[u] += sum[v];
        acum[u] += acum[v];
    }
    acum[u]+= sum[u];
}

void dfs2(int u, int p, vector<LineContainer>& ln){
    ll best = 0;
    ll k = 0;
    ln[u].add(sum[u], -sum[u]*prof[u]);
    Line xd;
    xd.k = sum[u];
    xd.m = -sum[u]*prof[u];
    sla[u].push_back(xd);
    
    for(auto v: adj[u]){
        if(v == p) continue;
        
        dfs2(v, u, ln);
        best = max(best, ln[v].query(prof[u]-1));
        k += acum[v];
    }

    cout<<"To no "<<u<<"\n";
    cout<<"soma total = "<<k<<"\n";
    cout<<"Conseguimo abonar "<<best<<"\n";

    res[u] = k - best;

    sz[u] = 1;

    for(auto v: adj[u]){
        if(v == p) continue;

        if(sz[v] > sz[u]){
            swap(ln[u], ln[v]);
            swap(sz[u], sz[v]);
            swap(sla[u], sla[v]);
        }

        for(Line &l: sla[v]){
            ln[u].add(l.k, l.m);
            sla[u].push_back(l);
        }
        sz[u] += sz[v];
    }
}

void solve(){
    int n; 
    cin>>n;

    rep(i, 0, n+1) {
        adj[i].clear();
        sla[i].clear();
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

    int mx = *max_element(prof+1, prof+1+n);
    rep(i, 1, n+1) prof[i] = mx - prof[i];

    vector<LineContainer> ln(n+1);
    dfs2(1, 0, ln);

    for(int i =1; i<=n; i++){
        cout<<res[i]<<" ";
    }

    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}