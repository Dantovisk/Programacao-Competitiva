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

const ll mod = 998244353; // faster if const

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

ll mul(ll a, ll b) {
	return (a*b)%mod;
}

ll inv(ll a){
    return modpow(a, mod-2);
}

const int MAX = 1e6+5;
ll fac[MAX], invfac[MAX];

void solve(){
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    int sig = a+d - (b+c);

    if(sig != 1 or a==0 or (a==1 and b>0)){
        cout<<"0\n";
        return;
    }

    ll aux = mul(fac[a+d-2], inv(mul(fac[a-2], fac[d])));
    ll aux2 = mul(fac[b+c], inv(mul(fac[b], fac[c])));
    cout<<mul(aux, aux2)<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    fac[0] = 1;
    rep(i, 1, 1'000'003){
        fac[i] = mul(fac[i-1], i);
    }

    int t = 1; 
    cin>>t;
    while(t--){
        solve();

    }
}