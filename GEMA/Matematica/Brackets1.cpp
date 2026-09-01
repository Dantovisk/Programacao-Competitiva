#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1e9+7;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

ll inv(ll a) {return modpow(a, mod-2);}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n;
    cin>>n;

    if(n%2){
        cout<<"0\n";
        return 0;
    }

    ll res = 1; //Catalan de 0
    for(int i = 1; i<= n/2; i++){
        res *= (2 * (2*i - 1));
        res %= mod;
        res *= inv(i+1);
        res %= mod;
    }
    cout<<res<<"\n";
}