#include <bits/stdc++.h>
using namespace std;

// #define int long long
typedef long long ll;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<ll> vi;

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
static const H C = (ull)1e11+3; // (order ~ 3e9; random also ok)

vector<H> getHashes(vi& str, int length = 0) {
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
H hashString(vi& s){H h{}; for(ll c:s) h=h*C+c;return h;}

const int MAX = 1e5+5;

ll v[MAX];

set<ull> bases[35];

vector<pair<int, ll>> base(32);

void prop(ll x, int id, int st = 31){
    // cout<<"mudando "<<x<<" "<<id<<", st = "<<st<<"\n";
    for(int j = st; j>= 0 ; j--){
        if((x & (1LL<<j))){
            if(base[j].first < id){
                swap(base[j].first, id);
                swap(base[j].second, x);
            }
            x ^= base[j].second;
        }
    }
}

void solve(){
    int n; cin>>n;

    rep(i, 0, 34)  bases[i].clear();

    ll res = 0;
    rep(i, 0, n){
        cin>>v[i];
    }
    
    if(*min_element(v, v+n) == 0) res++;
    rep(i, 0, 32) base[i] = {-1, 0};
    
    rep(i, 0, n){
        prop(v[i], i);
        // cout<<"to em "<<i<<"\n";
        // rep(j, 0, 3){
        //     cout<<"bit "<<j<<": "<<base[j].first<<", "<<base[j].second<<"\n";
        // }
        // cout<<"\n";

        vi ind;
        vector<pair<int, ll>> aux;
        for(int j = 31; j>= 0; j--){
            if(base[j].first != -1) aux.push_back(base[j]);
        }
        sort(all(aux));

        for(int j = sz(aux) - 1; j>= 0; j--){
            ind.push_back(aux[j].second);
        }

        ll b[32] = {0};
        rep(j, 0, sz(ind)){
            ll x = ind[j];
            
            for(int k = 31; k>= 0; k--){
                if((x>>k)&1){
                    if(!b[k]){
                        //pra limpar os bits baixos
                        for(int l = k - 1; l >= 0; l--){
                            if(b[l] && ((x >> l) & 1)){
                                x ^= b[l];
                            }
                        }
                        b[k] = x;

                        //limpa os cara de cima
                        for(int l = 31; l>k; l--){
                            b[l] = min(b[l], b[l]^x);
                            // if (b[l] && ((b[l] >> k) & 1)) {
                            //     b[l] ^= b[k];
                            // }
                        }

                        break;
                    }
                    x ^= b[k];
                }
            }

            
            vi novo;
            rep(k,0,32){
                if(b[k]) novo.push_back(b[k]);
            }
            bases[j+1].insert(hashString(novo).x);
        }


    }
    for(int j = 1; j <= 32; j++) res+= bases[j].size();

    cout<<res<<"\n";
}


int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int t = 1;
	cin>>t;

	while(t--) solve();
}


/*

5
3
1 2 3
4
10 12 17 33
6
1 0 9 8 7 3
8
9012 91829 9819 78 237 862 7672 2
10
0 1 2 4 8 16 32 64 128 256

*/