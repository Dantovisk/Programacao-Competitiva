#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll inf = 1e16+7;

void solve(){
    int n; cin>>n;
    vi v(n);

    set<int> vis;
    map<int, int> id;

    rep(i, 0, n) {
        cin>>v[i];
        vis.insert(v[i]);
    }

    int xd = 0;
    for(auto x: vis){
        id[x] = xd;
        xd++; 
    }

    int mx = vis.size();
    
    vi v2(n);
    rep(i, 0, n) v2[i] = id[v[i]]; 

    vi cost(n);
    rep(i, 0, n) cin>>cost[i];

    vector<vector<ll>> dp(n+1, vector<ll>(mx+1, inf));
    dp[0][0] = 0;

    rep(i, 1, n+1){
        int k = v2[i-1];
        int c = cost[i-1];

        //meu atual está mudando
        rep(j, 0, mx){
            dp[i][j] = min(dp[i-1][j] + c, dp[i][j]);
        }

        //meu atual é maior, só mantém
        rep(j, 0, k+1){
            dp[i][k] = min(dp[i-1][j], dp[i][k]);
        }
    }

    ll best = inf;

    rep(j, 0, mx){
        best = min(dp[n][j], best);
    }

    cout<<best<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;
    while(t--) solve();
}