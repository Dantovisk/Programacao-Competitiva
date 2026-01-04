#include <bits/stdc++.h> // O editorial é horrível!!!!
using namespace std;     // Mesmo tentando de 20 formas diferentes, a solução deles
                         // sempre dá MLE, TLE, etc.

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


const ll mod = 469762049, root = 3;
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.
typedef vector<ll> vl;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}

void conv(vl &a, vl &b) {
    int n = sz(a);

	ntt(a), ntt(b);
	rep(i,0,n) a[i] = (a[i] * b[i]) % mod;
    
    b.clear(); 
    b.shrink_to_fit();

	ntt(a);
    reverse(a.begin() + 1, a.end());
    ll inv = modpow(n, mod - 2);
	for(ll &x : a) x = (x * inv) % mod;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;

    //o b é o true;
    string a, b; 
    cin>>a>>b;

    string st = "", ed = "";
    for(auto x: a) {
        st += x;
        st += " ";
    }
    for(auto x: b) {
        ed += x;
        ed += x;
    }


    vl v1(n*4*26), v2(n*2*26);

    rep(j, 0, n*2){
        if(st[j] != ' ') v1[(2*n + j)*(26) + (st[j] - 'a')] = v1[j*(26) + (st[j] - 'a')] = 1;
        v2[2*n*26 - 1 - (j*26 + (ed[j] - 'a'))] = 1;
    }

    int s = sz(v1) + sz(v2) - 1, B = 32 - __builtin_clz(s),
	    n1 = 1 << B;

    v1.resize(n1, 0); 
    v2.resize(n1, 0);

    conv(v1, v2);

    ll best = 0;
    for(ll x : v1) best = max(best,x) ;

    cout<<n-best<<"\n";
    
}