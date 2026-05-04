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

ll calc(ll a, ll b, ll c){
    ll res  = a*a + b*b + c*c;
    res  -= a*b + b*c + a*c;
    return res;
}

void solve(){
    int n; cin>>n;

    vector<ll> v(n);
    rep(i, 0, n){
        cin>>v[i];
    }

    sort(all(v));
    reverse(all(v));

    ll res = 0;
    rep(i, 0, n){
        rep(j, i, n){
            res = max(res, calc(v[0],v[i], v[j]));
        }
    }

    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}