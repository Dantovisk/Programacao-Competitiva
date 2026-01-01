#include <bits/stdc++.h>
using namespace std;
//tive q apelar pra editorial :c

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

const int MAXN= 6e5 + 67;
ll invfac[MAXN], fac[MAXN], dois[MAXN];

ll mod = 998244353;

ll mul(ll a, ll b){
    return (a*b)%mod;
}
ll sub(ll a, ll b){
    return (a-b+mod)%mod;
}
ll add(ll a, ll b){
    return (a+b)%mod;
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

ll chose(ll n, ll k){
    if(k > n || n <0 || k <0) return 0;
    return mul(fac[n], mul(invfac[n-k], invfac[k]));
}

ll somamaior(ll k, ll n){
    if(k >= n) return 0;

    ll base = dois[n];
    ll aux = 0;

    rep(i, 0, k+1){
        aux = add(aux, chose(n, i));
    }

    return sub(base, aux);
}

void solve(){
    int n, m; cin>>n>>m;

    vi ct(62, 0);

    fac[0] = 1; invfac[0] = 1, dois[0] = 1;

    rep(i, 1, n+m+6){
        fac[i] = mul(fac[i-1], i);
        invfac[i] = inv(fac[i]);
        dois[i] = mul(dois[i-1], 2);
    }

    rep(i, 0, n){
        int a; cin>>a;
        ct[a]++;
    }

    rep(i, 0, m){
        ll t, a;
        cin>>t>>a;

        if(t == 1) {
            ct[a]++;
            continue;
        }
        else if(t==2) {
            ct[a]--;
            continue;
        }

        //TIPO 3
        //soma tem q ser pelo menos x

        //quantidade minima necessaria de cada cara
        vi r(62, 0);
        int off = 0;

        for(ll i = 61; i>= 0; i--){
            if((1LL<<i) & a){
                r[i+off]++;
                off++;
            }
        }

        ll res = 0, msbchose = 1;
        ll menores = 0;
        rep(i, 0, 61) menores += ct[i];

        for(ll i = 60; i>= 0; i--){
            menores -= ct[i];

            ll aux = 1;
            aux = mul(aux, dois[menores]);
            aux = mul(aux, somamaior(r[i], ct[i]));
            aux = mul(aux, msbchose);

            res = add(res, aux);
            msbchose = mul(msbchose, chose(ct[i], r[i]));
        }
        res = add(res, msbchose);

        cout<<res<<"\n";
    }
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;

    while(t--)solve();
}