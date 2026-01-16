#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

// SegTree
//
// Recursiva com Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
// Pode usar a seguinte funcao para indexar os nohs:
// f(l, r) = (l+r)|(l!=r), usando 2N de memoria
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))

const int MAX = 2e5+4;
const int inf = 1e9+3;

int ve[MAX];

namespace seg {
	ll seg[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}

    ll query2(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return inf;
		int m = (l+r)/2;
		return min(query2(a, b, 2*p, l, m), query2(a, b, 2*p+1, m+1, r));
	}

	int query(int a, int b, int p=1, int l=0, int r=n-1, ll mn = inf) {
        int d = l-a;
		if (b < l or r < a) return 0; // nao acontece prob
		if (l == r) return (min(seg[p], mn) == d? 1: 0);
		int m = (l+r)/2;

        
        ll aux = query2(a, m, p, l, r);

        if(m < a) {
            return query(a, b, 2*p+1, m+1, r, min(mn, aux));
        }

        if(min(mn, aux) <= m-a) return query(a, b, 2*p, l, m, mn);

		return query(a, b, 2*p+1, m+1, r, min(mn, aux));
	}

	ll update(int id, int x, int p=1, int l=0, int r=n-1) {
		if (id == l and id == r) {
			return seg[p] = x;
		}
		if (id < l or r < id) return seg[p];
		int m = (l+r)/2;
		return seg[p] = min(update(id, x, 2*p, l, m),
			update(id, x, 2*p+1, m+1, r));
	}

};


void solve(){
    int n, q;
    cin>>n>>q;

    rep(i, 0, n) {
        cin>>ve[i];
    }
    seg::build(n, ve);

    rep(xd, 0, q){
        int t, a, b;
        cin>>t>>a>>b;

        if(t==1){
            seg::update(a-1, b);
        }
        else{
            cout<<seg::query(a-1, b-1)<<"\n";
        }
    }


}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}