#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5+7;
const int k = 20;

typedef long long ll;
const ll mod = 1e9+7;

// soma de subconjunto
vector<ll> sos_dp(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if ((mask>>i&1)) f[mask] = (f[mask] + f[mask ^ (1 << i)]) % mod;
	return f;
}

// inverso de subconjunto
vector<ll> sos_dp_inv(vector<ll> f) {
	int N = __builtin_ctz(f.size());
	assert((1<<N) == f.size());

	for (int i = 0; i < N; i++) for (int mask = 0; mask < (1<<N); mask++)
		if ((mask>>i&1)) f[mask] = (f[mask] - f[mask ^ (1 << i)] + mod) % mod;
	return f;
}


ll mexp(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;

    ll x = mexp(a, b/2);
    if(b%2) return (((x*x)%mod)*a)%mod;
    return ((x*x)%mod);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<ll> v((1<<k), 0);

    ll tudo = (1<<k)-1;

    for(int i=0; i<n; i++){
        int a; cin>>a;
        v[a^tudo] ++;
    }

    vector<ll> sos = sos_dp(v);

    vector<ll> comb(1<<k, 0);

    for(int i=0; i<(1<<k); i++){
        if(sos[i] == 0) continue; 
        comb[i] = (mexp(2, sos[i]) - 1 + mod) %mod;
    }

    vector<ll> sosinv = sos_dp_inv(comb);

    cout<<sosinv[tudo]<<"\n";
}