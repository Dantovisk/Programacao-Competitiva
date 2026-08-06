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

const int mod = 1e9+7;
int dp[27];

void solve(){
    dp[26] = 1;

    string a; cin>>a;

    for(auto c: a){
        rep(i, 0, 27){
            if(c-'a' == i) continue;
            dp[c-'a'] += dp[i];
            dp[c-'a'] %= mod;
        }
    }

    int res = 0;
    rep(i, 0, 26){
        res += dp[i];
        res %= mod;
    }

    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}