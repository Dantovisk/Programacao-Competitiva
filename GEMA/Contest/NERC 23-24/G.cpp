#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef int ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

const int MAX = 5e5+7;

//range [a, b]
namespace seg {
	ll seg[4*MAX] = {}, lazy[4*MAX] = {};
	int n;

	void build(int n2) {
		n = n2;
	}
	void prop(int p, int l, int r) {
        if(lazy[p] == 0) return;
		seg[p] = lazy[p];
		if (l != r) lazy[2*p] = lazy[p], lazy[2*p+1] = lazy[p];
		lazy[p] = 0;
	}
    // query de max
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}
    // update de set
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = max(x, seg[p]);
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = max(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};


void solve(){
    int n; cin>>n;

    vi v(n);
    vector<tiii> ev;
    rep(i, 0, n){
        cin>>v[i];

        if(v[i] > i) ev.push_back({i+1, 1, -(v[i]-(i+1))});
        if(v[i] >= n-i) ev.push_back({v[i] -(n-i), 2, (n-i)});
    }

    seg::build(n+1);
    sort(all(ev));

    for(auto[x, t, y]: ev){
        int aux;
        if(t == 1) {
            y = -y;
            aux= seg::query(0, y);
            // cout<<x<<", "<<y<<" = "<<aux<<"\n";
        }
        else{
            aux= seg::query(0, y-1);
        }
        seg::update(y, y, aux+1);
    }

    cout<<n - seg::query(0, n)<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;
    while(t--){
        solve();

    }
}