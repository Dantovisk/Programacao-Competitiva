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

const int maxn = 2e5+4;
const int inf = 1e9+3;

void solve(){
    int n; 
    cin>>n;

    vi v(n);
    ll res = 0;
    rep(i, 0, n) cin>>v[i];

    rep(i, 0, n){
        ll s = 0;
        ll sobra = 0;
        rep(j, i, n){
            sobra += v[j];
            ll vai = min(1LL+ j - i, sobra);
            s += vai;
            sobra -= vai;
        }
        res = max(res, s);
        
        ll suf = 0;
        // os 1s vão de [l, r) 
        for(int r = n-1; r > i; r--){
            s -= min(v[r], r-i+1);
            suf += v[r];

            ll add = min((ll)(n-r)*(r-i), suf);
            res = max(res, add+s);
        }

    }

    cout<<res<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);


    int t = 1;
    cin>>t;

    while(t--) solve();
}