#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back 
#define ff first
#define ss second

const int MAX = 1e6+3;

ll fac[MAX];
ll invfac[MAX];

ll suf[5010];
ll pref[5010];

const ll mod = 1000000007; // faster if const

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

ll mul(ll a, ll b){
    return (a*b)%mod;
}

ll add(ll a, ll b){
    return (a+b)%mod;
}

ll sub(ll a, ll b){
    return (a-b+mod)%mod;
}

ll inv(ll a){
    return modpow(a, mod-2);
}
int n, k;
vi v;
int resto;

map <pii, int> dp;

ll calc(int qt, int i){
    if(dp.find({qt, i}) != dp.end()) return dp[{qt, i}];

    if(i < 0){
        return dp[{qt, i}] = fac[pref[qt]];
    }
    // if(i == k-1 && !resto) return fac[v[i]];
    ll res = fac[pref[qt]];
    rep(j, 0, i+1){
        ll aux = mul(fac[pref[qt] - pref[j]], calc(j, j-1));
        res = sub(res, aux);
    }

    return dp[{qt, i}] = res;
}

void solve(){
    cin>>n>>k;
    v.resize(k);
    rep(i, 0, k) cin>>v[i];

    resto = n;
    rep(i, 0, k) resto -= v[i];

    suf[0] = n;
    rep(i, 1, k+1) suf[i] = suf[i-1] - v[i-1];

    
    if(k) pref[0] = v[0];
    rep(i, 1, k) pref[i] = pref[i-1] + v[i]; 
    pref[k] = n;

    // rep(i, 0, k+1) cout<<pref[i]<<" ";
    // cout<<"\n";


    if(resto == 0){
        cout<<"0\n";
        return;
    }

    fac[0] = 1;
    invfac[0] = 1;
    rep(i, 1, n+1){
        fac[i] = mul(fac[i-1], i);
        invfac[i] = inv(fac[i]);
    }
    
    cout<<calc(k, k-1)<<"\n";

}

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int t = 1;

    while(t--) solve();
}