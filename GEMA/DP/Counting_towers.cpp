#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e6+8;

// 0 -> separado
// 1- > junto
int dp[MAX][2];

const int mod = 1e9+7;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    dp[1][0] = dp[1][1]= 1;

    rep(i, 2, 1'000'001){
        dp[i][0] += (dp[i-1][0] * 4LL);
        dp[i][0] += dp[i-1][1];
        dp[i][0] %= mod;

        dp[i][1] += 2LL*dp[i-1][1];
        dp[i][1] += dp[i-1][0];
        dp[i][1] %= mod;
    }

    int t; cin>>t;
    rep(i, 0, t){
        int n; cin>>n;
        cout<<(dp[n][1] + dp[n][0])%mod<<"\n";
    }


}