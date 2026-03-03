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
const int inf = 3e5+7;
void solve(){
    int n; 
    cin>>n;

    vi v(n+1);
    v[0] = 0;
    rep(i, 1, n+1) cin>>v[i];

    vector<vi> dp(n+1, vi(7, inf));

    int res = inf;
    rep(i,0,7) dp[0][i] = 0;

    rep(i, 1, n+1){
        if(v[i] + v[i-1] != 7 && v[i] != v[i-1]) dp[i][0] = dp[i-1][0];

        rep(j, 1, 7){
            if(v[i] + j != 7 && v[i] != j){
                dp[i][0] = min(dp[i][0], dp[i-1][j]);
            }
        }

        rep(j, 1, 7){
            if(v[i-1] + j != 7 && v[i-1] != j){
                dp[i][j] = dp[i-1][0] + 1;
            }

            rep(k, 1, 7){
                if(j == k || j+k==7) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][k] + 1);
            }
        }
    }

    rep(i, 0, 7){
        res = min(res, dp[n][i]);
    }

    cout<<res<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}