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

    vi v(n+1);
    vector<vi> dp (n+1, vi(n+1, 0));
    int res = 0;
    rep(i, 1, n+1) {
        cin>>v[i];
    }

    rep(i, 1, n+1) {
        rep(j, i+1, n+1) {
            res = max(res, v[i]^v[j]);
        }
    }

    cout<<res<<"\n";

    // int mx = 2 + (n-2)/2;

    // rep(i, 1, n+1){
    //     rep(j, 1, mx+1){
    //         dp[i][j] = max()
    //     }
    // }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}