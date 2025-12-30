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
    int n, m; cin>>n>>m;

    vi ct(62, 0);

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

        vector<vi> dp(62, vi(62, 0));

        rep(i, 0, 62){
            rep(j, 0, 62){

            }
        }

    }
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}