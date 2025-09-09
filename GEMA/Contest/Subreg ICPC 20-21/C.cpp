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
#define tii tuple<int, int, int>

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
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
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

int visa[100010], visb[100010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin>>m>>n;

    vector<string> A(m), B(n);
	unordered_map <ull, pair<string, int>> hasha, hashb;
	unordered_map <ull, string> ida, idb;

	//set<ull> ra, rb;

    for(int i = 0; i<m; i++) {
		cin>>A[i];
		ull x = hashString(A[i]).x;
		hasha[x] = {A[i], i};
		//ra.insert(x);
	}

	for(int i = 0; i<n; i++) {
		cin>>B[i];
		ull x = hashString(B[i]).x;
		hashb[x] = {B[i], i};
		//rb.insert(x);
	}

	// Tuplas (S, x, x')
	vector<tuple <ull, int, int>> moga;
	unordered_map <ull, vector<pair<int, int>>> mogb;

	for(int i = 0; i< A.size(); i++){
		string s = A[i]; int id1 = i;

		HashInterval hs = HashInterval(s);

		// Tuplas em A
		for(int i =1; i<sz(s); i++){
			H x = hs.hashInterval(0, i);
			if(hasha.find(x.x) != hasha.end()){
				int id = hasha[x.x].second;

				H y = hs.hashInterval(i, sz(s));
				moga.push_back({y.x, id, id1});
			}	
		}
	}
	
	for(int i = 0; i< B.size(); i++){
		string s = B[i]; int id1 = i;

		HashInterval hs = HashInterval(s);

		// Tuplas em B
		for(int i =1; i<sz(s); i++){
			H x = hs.hashInterval(i, sz(s));
			if(hashb.find(x.x) != hashb.end()){
				int id = hashb[x.x].second;

				H y = hs.hashInterval(0, i);

				mogb[y.x].push_back({id, id1});  
			}	
		}
	}
	sort(all(moga));
	
	ull last = ULLONG_MAX;

	for(auto [a, b, c]: moga){
		if(a == last){
			visa[b] = 1;
			visa[c] = 1;
			continue;
		}
		auto it = mogb.find(a);
		if(it != mogb.end()){
			for(auto [d, e] : it->second){
				visb[d] = 1;
				visb[e] = 1;
			}
			visa[b] = 1;
			visa[c] = 1;

			last = a;
		}
		
	}

	cout<<count(visa, visa+m, 0)<<" "<<count(visb, visb+n, 0)<<"\n";
	
}