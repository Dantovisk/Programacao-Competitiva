#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const int inf = 1e9+3;

void solve(){
    int n, k; 
    cin>>n>>k;
    vi v(n), add(n);

    ll res = -inf;

    rep(i, 0, n) {
        cin>>v[i];
    }
    rep(i, 0, n) {
        cin>>add[i];
    }

    if(k % 2 == 0){
        vi dp(n);
        dp[0] = v[0];
        rep(i, 1, n){
            dp[i] = max(dp[i-1] + v[i], v[i]);
        }
        res = *max_element(all(dp));
    }
    else{
        // cout<<"c&g\n";
        vector<vi> dp(n, vi(2, -inf));
        dp[0][0] = v[0];
        dp[0][1] = v[0] + abs(add[0]);
        rep(i, 1, n){
            dp[i][0] = max(dp[i-1][0] + v[i], v[i]);
            dp[i][1] = max({dp[i][1], dp[i-1][0] + v[i] + abs(add[i])});
            dp[i][1] = max({dp[i][1], v[i] + abs(add[i]), dp[i-1][1] + v[i]});
        }

        rep(i, 0, n) res = max(res, dp[i][1]);
    }

    cout<<res<<"\n";

}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}