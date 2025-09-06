#include <bits/stdc++.h> // Path Queries II - Para acostumar com a lib
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
#define MAX 200010
 
namespace seg {
	int seg[2*MAX];
	int n, *v;
 
    void build() {
        for (int i = 0; i < n; i++) seg[n + i] = v[i];
        for (int i = n - 1; i; i--) seg[i] = max(seg[2*i], seg[2*i+1]);
    }
 
    void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
 
    int query(int a, int b) {
        int ret = 0;
        for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
            if (a % 2 == 1) ret = max(ret, seg[a]);
            if (b % 2 == 0) ret = max(ret, seg[b]);
        }
        return ret;
    }
 
    void update(int p, int x) {
        seg[p += n] = x;
        while (p /= 2) seg[p] = max(seg[2*p], seg[2*p+1]);
    }
};
 
// HLD - vertice
//
// SegTree de soma
// query / update de soma dos vertices
//
// Complexidades:
// build - O(n)
// query_path - O(log^2 (n))
// update_path - O(log^2 (n))
// query_subtree - O(log(n))
// update_subtree - O(log(n))
 
// namespace seg { ... }
 
namespace hld {
	vector<int> g[MAX];
	int pos[MAX], sz[MAX];
	int peso[MAX], pai[MAX];
	int h[MAX], v[MAX], t;
 
	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = peso[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i != p) {
			pai[i] = k;
			h[i] = (i == g[k][0] ? h[k] : i);
			build_hld(i, k, f); sz[k] += sz[i];
 
			if (sz[i] > sz[g[k][0]] or g[k][0] == p) swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		seg::build(t, v);
	}
	int query_path(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
 
		if (h[a] == h[b]) return seg::query(pos[b], pos[a]);
		return max(seg::query(pos[h[a]], pos[a]), query_path(pai[h[a]], b));
	}
 
    void update_node(int a, int x){
        seg::update(pos[a], x);
    }
 
	ll query_subtree(int a) {
		return seg::query(pos[a], pos[a]+sz[a]-1);
	}
 
	int lca(int a, int b) {
		if (pos[a] < pos[b]) swap(a, b);
		return h[a] == h[b] ? b : lca(pai[h[a]], b);
	}
}
 
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, q;
    cin>>n>>q;
 
    for(int i = 0; i<n; i++){
        cin>> hld::peso[i];
    }
 
    for(int i = 1; i<n; i++){
        int u, v;
        cin>>u>>v;
        hld::g[(--u)].push_back((--v));
        hld::g[v].push_back(u);
    }
 
    hld::build(0);
 
    while(q--){
        int t, a, b;
        cin>>t>>a>>b;
 
        if(t==1){
            hld::update_node(--a, b);
        }else{
            cout<<hld::query_path(--a, --b)<<" ";
        }
    }
 
}