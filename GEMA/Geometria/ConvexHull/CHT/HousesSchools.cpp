#include <bits/stdc++.h> // Resolvendo Houses and Schools (CSES)
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

// sum é o somatorio de Ci
// pref é somatorio de Ci * i
// suf é somatorio de (n - i + 1) * Ci
ll sum[3100], pref[3100], suf[3100];
ll v[3100];

// dp0 -> distancia minima usando até ci usando m escolar terminando em um vale
// dp1 -> distancia minima usando até ci usando m escolar terminando em uma montanha

ll dp0[3100], dp1[3100];

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    // dp0 -> distancia minima usando m elementos terminando em um vale
    int n, k; cin>>n>>k;

    for(int i =1; i<=n; i++){
        cin>>v[i];

        sum[i] = sum[i-1] + v[i];
        pref[i] = pref[i-1] + v[i] * i;
        suf[i] = suf[i-1] + v[i] * (n-i+1);
    }

    for(int j = 1; j<=k; j++){
        LineContainer l0, l1;
        for(int i =0; j< k; j++){
            
        }
    }

    return 0;
}