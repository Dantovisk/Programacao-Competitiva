#include <bits/stdc++.h> 
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<long long> vi;

const int MAX = 2e5+5;
int v[MAX];

const ll MOD = 1e9 + 7;

ll mexp(ll b, ll e, ll mod = MOD){
    if(e==0) return 1;
    if(e==1) return b;

    ll k = mexp(b, e/2, mod);
    k = (k*k)%mod;
    if(e%2) return (k*b)%mod;
    return k;
}

ll inv(ll a){return mexp(a, MOD-2);}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin >> n;
    map<int, int> vis;

    ll resp = 0;
    ll acum = 1;

    rep(i, 1, n+1) {
        cin>>v[i];
        resp = (resp + (acum * inv(vis[v[i]] + 1))) % MOD;
        // cout<<acum<<" ";
        acum = (acum * inv(vis[v[i]] + 1))% MOD;
        vis[v[i]]++;
        acum = (acum * (vis[v[i]] + 1))% MOD;
    }

    cout<<resp<<"\n";

}