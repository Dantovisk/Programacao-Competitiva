#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e6+8;
int dp[MAX];

const int mod = 1e9+7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;
    dp[0] = 1;

    rep(i, 0, n){
        rep(j, 1, 7){
            dp[i+j] += dp[i];
            dp[i+j] %= mod;
        }
    }
    cout<<dp[n]<<"\n";

}