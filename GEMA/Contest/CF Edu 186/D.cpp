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

ll mod = 998244353;

ll fac[60];
ll chose[55][55];

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

    int sobra; cin>>sobra;
    int qt = 0;

    vi v(n);
    rep(i, 0, n){
        cin>>v[i];
    }

    int mx = *max_element(all(v));

    rep(i, 0, n){
        if(v[i] < mx){
            int a = (mx - 1) - v[i];
            sobra -= a;
            qt ++;
        }
    }

    if(sobra < 0){
        cout<<"0\n";
    }
    else if(sobra > qt){
        // cout<<"uai\n";
        sobra -= qt;
        qt = 0;
        sobra %= n;

        ll res = chose[n][sobra];
        // cout<<res<<" - ";
        res = (res * fac[sobra])%mod;
        // cout<<res<<" - ";
        res = (res * fac[n-sobra])%mod;
        // cout<<res<<" - ";

        cout<<res<<"\n";
    }
    else{
        int total = qt - sobra;
        ll res = chose[qt][sobra];

        res = (res * fac[total])%mod;
        res = (res * fac[n-total])%mod;

        cout<<res<<"\n";
    }   

}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    fac[0] = 1;
    rep(i, 1, 52){
        fac[i] = (fac[i-1] * (ll)i)%mod;
    }

    chose[0][0] = 1;
    rep(i, 1, 52){
        chose[i][0] = chose[i][i] = 1;
        rep(j, 1, i){
            chose[i][j] = (fac[i] * inv((fac[j]*fac[i-j])%mod))%mod;
        }
    }

    while(t--)solve();
}