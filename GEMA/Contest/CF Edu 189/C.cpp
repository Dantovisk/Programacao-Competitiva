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

const int MAX = 1e5+7;
const int inf = 1e9+7;

void solve(){
    int n; 
    cin>>n;

    string a, b;
    vi dp(n+1 , inf);

    dp[0] = 0;

    cin>>a>>b;

    rep(i, 1, n+1){
        int cost = (a[i-1] == b[i-1] ? 0: 1);
        dp[i] = min(dp[i], dp[i-1] + cost);

        if(i == 1) continue;

        cost = 0;
        if(a[i-1] != a[i-2]) cost++;
        if(b[i-1] != b[i-2]) cost++;

        dp[i] = min(dp[i], dp[i-2] + cost);
    }

    cout<<dp[n]<<'\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}