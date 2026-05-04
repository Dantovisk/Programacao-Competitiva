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

set <pii> s;

const int MAX = 510;

ll dist (pii& a, pii &b){
    return ((ll)a.ff * (ll)a.ff) + ((ll)b.ff * (ll)b.ff);
}

vi adj[MAX];
ll pow2[MAX];
ll dp[MAX];
const ll mod = 998244353;

void solve(){
    int n; cin>>n;

    pow2[0] = 1;
    rep(i, 0, n){
        pow2[i+1] = (pow2[i]<<1)%mod;
    }

    vector<pii> v;
    rep(i, 0, n){
        int a, b;
        v.pb({a, b});
    }


    pii cent = {0, 0};
    rep(i, 0, n){
        rep(j, i+1, n){
            ll d1 = dist(v[i], cent), d2 = dist(v[j], cent);
            ll dij = dist(v[i], v[j]); 

            if(dij > min (d1, d2)){
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    rep(i, 0, n){
        rep(j, 0, i){
            
        }
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;
    while(t--){
        solve();
    }
}