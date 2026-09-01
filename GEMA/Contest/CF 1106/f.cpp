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

const int maxn = 4e5+4;
const int inf = 1e9+3;

const ll mod = 1000000007; 

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

ll inv(ll a) {return modpow(a, mod-2);}
ll mul(ll a, ll b) {return (a*b)%mod;}

ll fac[maxn];
int tot[30];

void solve(){
    memset(tot, 0 , sizeof(tot));
    int n, k;
    cin>>n>>k;

    int qtd = 0;
    k++;

    rep(i, 0, 20){
        if(!((1<<i) & k)) continue;

        if(i >= n){
            qtd += (1<<(i-n+1));
            tot[n-1] += (1<<(i-n+1));
        } else {
            qtd++;
            tot[i]++;
        }
    }


    int id = qtd-1;
    ll cat = mul(fac[2*id], inv(mul(fac[id+1], fac[id])));
    // cout<<"catalao: "<<cat<<"\n";
    // cout<<"qtd = "<<qtd<<"\n";
    // rep(i, 0, 5)cout<<"tot["<<i<<"] = "<<tot[i]<<"\n";
    ll aux = fac[qtd];
    rep(i, 0, 20) if(tot[i]) aux = mul(aux, inv(fac[tot[i]]));

    cout<<mul(cat, aux)<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    fac[0] = 1;

    rep(i, 1, maxn-1){
        fac[i] = (fac[i-1] * (ll)i) %mod;
    }

    int t = 1;
    cin>>t;

    while(t--) solve();
}