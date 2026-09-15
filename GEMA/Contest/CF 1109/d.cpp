#include <bits/stdc++.h>
using namespace std;

#define int long long

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
    int n, m; 
    cin>>n>>m;

    vi v(n+1), tem(n+1, 0);

    rep(i, 1, n+1) cin>>v[i];
    rep(i, 0, m){
        int a; cin>>a;
        tem[a] = 1;
    }

    vector<vi> dp(n+1, vi(2, 0));
    
    rep(i, 1, n+1){
        dp[i][0] = dp[i-1][0] + v[i];
        dp[i][1] = dp[i-1][1] + v[i];

        if(tem[i]){
            dp[i][0] = max(dp[i][0], -dp[i][1]);
            dp[i][1] = min(dp[i][1], -dp[i][0]);
        }
    }

    cout<<dp[n][0]<<"\n";

}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}