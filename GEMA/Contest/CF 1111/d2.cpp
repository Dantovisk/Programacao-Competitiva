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

const int MAX = 1050000;
const int inf = 1e9+3;

// SegTree
// Recursiva com Lazy Propagation
namespace seg {
    //seg é o mínimo pra poder ordenar o intervalo
	ll seg[4*MAX], mn[4*MAX], mx[4*MAX];
	int n, *v;

	void build(int p=1, int l=0, int r=n-1) {
		if (l == r) {
            seg[p] = 0;
            mn[p] = mx[p] = v[l];
            return;
        }
		int m = (l+r)/2;
		build(2*p, l, m); 
        build(2*p+1, m+1, r);

        mn[p] = min(mn[2*p], mn[2*p+1]);
        mx[p] = max(mx[2*p], mx[2*p+1]);
        seg[p] = max(seg[2*p], seg[2*p+1]);
        if(mx[2*p] > mn[2*p+1]) seg[p] = (r-l+1)/2;

	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}

	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	void update(int a, int x, int p=1, int l=0, int r=n-1) {
		if (a == l and r == a) {
			mn[p] = mx[p] = x;
            seg[p] = 0;
            return;
		}
		if (a < l or r < a) return;
		int m = (l+r)/2;
		update(a, x, 2*p, l, m);
		update(a, x, 2*p+1, m+1, r);

        mn[p] = min(mn[2*p], mn[2*p+1]);
        mx[p] = max(mx[2*p], mx[2*p+1]);
        seg[p] = max(seg[2*p], seg[2*p+1]);
        if(mx[2*p] > mn[2*p+1] ) seg[p] = (r-l+1)/2;
	}
};

int v[MAX];

void solve(){
    int n, q; 
    cin>>n>>q;

    int n2 = 1;
    while(n2 < n) n2 *= 2;

    rep(i, n, n2) v[i] = inf;

    rep(i, 0, n){
        cin>>v[i];
    }

    seg::build(n2, v);
    cout<<seg::query(0, n2-1)<<'\n';

    while(q--){
        int a, x;
        cin>>a>>x;
        seg::update(a, x);
        cout<<seg::query(0, n2-1)<<'\n';
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}