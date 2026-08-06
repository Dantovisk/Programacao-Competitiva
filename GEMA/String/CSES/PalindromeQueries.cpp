#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Arithmetic mod 2^64-1. 2x slower than mod 2^64 and more
// code, but works on evil test data (e.g. Thue-Morse, where
// ABBA... and BAAB... of length 2^10 hash the same mod 2^64).
// "typedef ull H;" instead if you think test data is random,
// or work mod 10^9+7 if the Birthday paradox is not a problem.
typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)


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
	vector<H> ha;
	FT(int n) : ha(n) {}
	void update(int pos, H dif) { // a[pos] += dif
		for (; pos < sz(ha); pos |= pos + 1) ha[pos] = ha[pos] + dif;
	}
	H query(int pos) { // sum of values in [0, pos)
		H res(0);
		for (; pos > 0; pos &= pos - 1) res = res + ha[pos-1];
		return res;
	}

    //sum of values int [a, b]
    H query(int a, int b){
        return query(b+1) - query(a);
    }
};


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, q;
    cin>>n>>q;

    string s, si; cin>>s;
    si = s;
    vector<H> pw(n+1);
    FT hs(n+1), hi(n+1);
    pw[0].x = 1;

    H curr;
    rep(i, 0, n){
        pw[i+1] = pw[i]*C;
        curr.x = s[i];
        hs.update(i+1, pw[i]*curr);

        // cout<<"hash de"<<i<<" = "<<hs.query(i+1, i+1).x<<"\n";
    }

    reverse(all(si));
    rep(i, 0, n){
        curr.x = si[i];
        hi.update(i+1, pw[i]*curr);
    }

    rep(i, 0, q){
        int t, a;
        cin>>t>>a;

        if(t == 1){
            char c; cin>>c;

            H base = hs.query(a, a);
            curr.x = c;
            H novo = pw[a-1] * curr;
            hs.update(a, novo-base);

            a = n + 1 - a;

            base = hi.query(a, a);
            curr.x = c;
            novo = pw[a-1] * curr;
            hi.update(a, novo-base);
        }
        else{
            int b; cin>>b;
            int mid1 = (a+b)/2, mid2=(a+b+1)/2;

            //inverte o indice
            mid2 = n + 1 - mid2;
            b = n + 1 - b;

            int diff = a-b;

            H h1 = hs.query(a, mid1);
            if(diff < 0) h1 = h1 * pw[-diff];

            H h2 = hi.query(b, mid2);
            if(diff > 0) h2 = h2 * pw[diff];

            // cout<<"["<<a<<", "<<mid1<<"]  vs ["<<b<<", "<<mid2<<"]\n";
            // cout<<(h1).x << " =? " << h2.x<<"\n";
            if(h1 == h2){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }

}