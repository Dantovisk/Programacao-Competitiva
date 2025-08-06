#include <bits/stdc++.h> // Resolvendo E. The Fair Nut and Rectangles
using namespace std;     // Com Line Container (NlogN) do kactl

#define ll long long

// Description: Container where you can add lines of the form kx+m, 
// and query maximum values at points x.
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


int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n; cin>>n;

    vector<tuple<ll,ll,ll>> l;
    

    for(int i =0; i<n; i++){
        ll x, y, a;
        cin>>x>> y>> a;
        l.push_back({x, y, a});
    }
    sort(l.begin(), l.end());

    LineContainer lc;
    ll resp = 0;

    for(int i =0; i<n; i++){
        auto [x, y, a] = l[i];

        ll dp = x * y - a;
        if(!lc.empty()){
            dp += max(lc.query(y), 0LL);
        }
        lc.add(-x, dp);
        resp = max(resp, dp);
    }

    cout<<resp<<"\n";

    return 0;
}