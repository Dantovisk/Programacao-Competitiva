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

const int maxn = 1e6+4;
const int inf = 1e9+3;

int dp[maxn];

void solve(){
    int x, y; 
    cin>>x>>y;

    if(gcd(x, y) > 1){
        cout<<"-1\n";
        return;
    }

    dp[0] = 1;

    rep(i, 0, maxn-max(x, y)-1){
        if(!dp[i]) continue;
        dp[i+x] =1;
        dp[i+y] =1;
    }

    cout<<count(dp, dp+maxn-10, 0)<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}