#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5+8;
int dp[MAX][105];

const int mod = 1e9+7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m; cin>>n>>m;
    int x; cin>>x;
    if(x == 0)
        rep(i, 1, m+1)dp[1][i] = (1);
    else dp[1][x] = 1; 

    rep(i, 2, n+1){
        int a; cin>>a;

        if(a== 0){
            rep(k, 1, m+1){
                for(int j = max(1, k-1); j <= min(m, k+1); j++){
                    dp[i][k] += dp[i-1][j];
                    dp[i][k] %= mod;
                }
            }
            
        }else{
            for(int j = max(1, a-1); j <= min(m, a+1); j++){
                dp[i][a] += dp[i-1][j];
                dp[i][a] %= mod;
            }
        }
        
    }

    ll res = 0;
    rep(i, 1, m+1){
        res += dp[n][i];
        res %= mod;
    }
    cout<<res<<"\n";

}