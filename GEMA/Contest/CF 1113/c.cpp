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

const int maxn = 2e5+4;
const int inf = 1e9+3;

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

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] = max(dif, s[pos]);
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res = max(s[pos-1],res);
		return res;
	}

};

void solve(){
    int n; 
    cin>>n;

    vi v(2*n);
    rep(i, 0, 2*n) cin>>v[i];

    vi l(n+5, -1);

    FT ft(2*n+3);

    rep(i, 0, 2*n){
        if(l[v[i]] == -1){
            l[v[i]] = i;
            ll aux2 = 0;
            if(i) aux2 = ft.query(i);
            ft.update(i, 1LL + aux2);
        }
        else{
            ll aux = i - l[v[i]] + 1;
            aux = aux*aux;
            ll sum = 0;
            if(l[v[i]] > 0) sum = ft.query(l[v[i]]);
            ft.update(i, aux + sum);

            ll aux2 = 0;
            if(i) aux2 = ft.query(i);
            ft.update(i, 1LL + aux2);
        }
    }

    cout<<ft.query(2*n+2)<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}