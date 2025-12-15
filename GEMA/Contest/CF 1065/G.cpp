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

const ll mod = 1e6+3;

ll fac[mod+3];

ll add(ll a, ll b){
    return (a + b)%mod;
}

ll mul(ll a, ll b){
    return (a * b)%mod;
}

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

ll inv(ll a){
    return modpow(a, mod-2);
}

void solve(){
    int n; cin>>n;
    vi v1(n), v2(n);

    rep(i, 0 , n) cin>>v1[i];
    rep(i, 0 , n) cin>>v2[i];

    int mindb = 30;
    rep(i, 0, n){
        int a = v1[i];
        int ct = 0;
        while((a<<1) <= v2[i]){
            a<<=1;
            ct++;
        }
        mindb = min(mindb, ct);
    }
    vector<vi> adds (n, vi(23, 0));
    
    ll res = mindb;
    rep(i, 0, n){
        int a = (v1[i]<<mindb);
        for(int s = mindb; s >= 0; s--){
            int diff = v2[i] - a;
            int curr = (1<<s);
            
            adds[i][s] += diff/curr;
            diff %= curr;

            res += adds[i][s];
            a = v2[i] - diff;
        }
    }

    cout<<res<<" ";

    ll ct = 1;

    for(int s = mindb; s >= 0; s--){
        ll total = 1;
        ll curr = 0;
        rep(i, 0, n){
            curr += adds[i][s];

            if(adds[i][s] > 1)
                total = mul(total, inv(fac[adds[i][s]]));
        }
        if(curr < mod){
            total = mul(fac[curr], total);
            ct = mul(total, ct);
        }
        else{
            ct = 0;
            break;
        }
    }

    cout<<ct<<"\n";
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    fac[0] = 1;
    rep(i, 1, mod+2){
        fac[i] = mul(fac[i-1], i);
    }

    while(t--)solve();
}