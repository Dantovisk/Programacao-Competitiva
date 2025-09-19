#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Simon Lindholm
 * Date: 2015-03-15
 * License: CC0
 * Source: own work
 * Description: Self-explanatory methods for string hashing.
 * Status: stress-tested
 */

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

struct HashInterval {
	vector<H> ha, pw;
    int n, m;
    vector<vector<H>> psum;

	HashInterval(string& str, int nx, int mx) : ha(sz(str)+1), pw(ha) {
		n = nx;
        m = mx;
        pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;

        psum.resize(n+1, vector<H>(m+1, 0));

        rep(i, 0, n){
            rep(j, 0, m){
                H uai = H(str[i*m+j]);
                psum[i+1][j+1] = psum[i][j+1] + psum[i+1][j] - psum[i][j]
                + (uai * pw[i*m+j]);
            }
        }
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}

    H sum(int imin, int imax, int jmin, int jmax){
        return (psum[imax][jmax] - psum[imin][jmax]) - psum[imax][jmin] + psum[imin][jmin];
    }
    H fator(int i, int j){
        return pw[i*m+j];
    }
};

vector<H> getHashes(string& str, int length) {
	if (sz(str) < length) return {};
	H h = 0, pw = 1;
	rep(i,0,length)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h};
	rep(i,length,sz(str)) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n1, m1, n, m;
    cin>>n1>>m1>>n>>m;

    string b ="", a = "";
    rep(i, 0, n1){
        string x; cin>>x;
        b += x;
        int k = m - m1;
        while(k--){
            b.push_back('a');
        }
    }

    rep(i, 0, n){
        string x; cin>>x;
        a += x;
    }

    HashInterval key = HashInterval(b, n1, m), base=HashInterval(a, n, m);

    int resp = 0;
    for(int i =0; i<= n-n1; i++){
        for(int j =0; j<= m-m1; j++){
            if((key.sum(0, n1, 0, m1) * base.fator(i, j)).x == base.sum(i, i+n1, j, j+m1).x)
                resp++;
        }
    }

    cout<<resp<<"\n";
}