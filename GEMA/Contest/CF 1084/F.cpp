#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

const int MAX = 1e5+7;
const int inf = 1e9+7;

/**
 * Author: Lukas Polacek
 * Date: 2009-10-30
 * License: CC0
 * Source: folklore/TopCoder
 * Description: Computes partial sums a[0] + a[1] + ... + a[pos - 1], and updates single elements a[i],
 * taking the difference between the old and new value.
 * Time: Both operations are $O(\log N)$.
 * Status: Stress-tested
 */
#pragma once

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

void solve(){
    int n, m; 
    cin>>n >> m;

    FT ft1(n+m+1), ftsum(n+m+1);

    vector <tii> v(n);
    vector<tii> coord;
    vector<tii> shop;
    vi res(n);

    map <tii, int> ids; 

    rep(i,0, n){
        int x, y;
        cin>>y>>x;
        v[i] = {x, y, i};
        coord.pb({x, y, -1});
    }

    rep(i,0, m){
        int x, y;
        cin>>y>>x;
        coord.pb({y, x, n+i});
        shop.pb({x, y, n+i});
    }

    sort(all(coord));
    reverse(all(coord));

    rep(i, 0, n+m){
        ids[coord[i]] = i;
    }

    sort(all(shop));
    reverse(all(shop));
    sort(all(v));
    reverse(all(v));

    int id = 0;
    for(int i = n; i >= 0; i--){
        while(get<0>(v[id]) >= i){
            auto [x, y, j] = v[id];
            if(j <= n){
                ft1.update(j, 1);

            }
        }
        
    }

    vector <pii> aux(n);
    rep(i, 0, m){
        
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}