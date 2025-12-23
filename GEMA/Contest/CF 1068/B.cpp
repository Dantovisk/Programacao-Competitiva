#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
#define ff first
#define ss second

void solve(){
    int n; cin>>n;

    vi a(n), b(n);
    rep(i, 0, n) cin>>a[i];
    rep(i, 0, n) cin>>b[i];

    vector<vi> dp(n+1, vi(2, 0));

    rep(i, 1, n+1){
        dp[i][1] = max(b[i-1] - dp[i-1][0], dp[i-1][1] - a[i-1]);
        dp[i][0] = min(b[i-1] - dp[i-1][1], dp[i-1][0] - a[i-1]);
    }

    cout<<dp[n][1]<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}