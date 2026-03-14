#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e5+8;

int dp[MAX];

const int mod = 1e9+7;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;
    vi v(n);
    int s = 0;
    rep(i, 0, n){
        cin>>v[i];
        s+= v[i];
    }


    dp[0] = 1;
    vi res;
    for(auto c: v){
        for(int i = s; i> 0; i--){
            if(i-c >= 0 && dp[i-c] > 0){
                dp[i] = 1;
            }
        }
    }
    rep(i, 1, s+1) 
        if(dp[i]) res.push_back(i);

    cout<<res.size()<<"\n";
    for(auto x: res) cout<<x<<" ";
    cout<<"\n";
}