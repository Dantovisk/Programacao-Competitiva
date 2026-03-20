#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n, ax, ay, bx, by;
    cin>>n>>ax>>ay>>bx>>by;

    vi xs(n), ys(n);

    map <int, int> mn, mx;
    rep(i, 0, n){
        cin>>xs[i];
    }
    rep(i, 0, n){
        cin>>ys[i];
    }

    int fim = 0;

    rep(i, 0, n){
        fim = max(fim, xs[i]);
        if(mn.find(xs[i]) == mn.end()){
            mn[xs[i]] = ys[i];
            mx[xs[i]] = ys[i];
        }
        else{
            mn[xs[i]] = min(ys[i], mn[xs[i]]);
            mx[xs[i]] = max(ys[i], mx[xs[i]]);
        }
    }

    int lx = ax, lmn = ay, lmx = ay;
    vi prev(2, 0);
    vi dp(2, 0);

    for(auto [x, miny] : mn){
        int maxy = mx[x];

        int dx = x - lx;
        int dy = maxy - miny;

        dp[1] = min(prev[0] + abs(lmn - miny), prev[1] + abs(lmx - miny)) + dx + dy;
        dp[0] = min(prev[0] + abs(lmn - maxy), prev[1] + abs(lmx - maxy)) + dx + dy;
        
        // cout<<"x: "<<x<<", dx = "<<dx<<" = "<<dp[0]<<" "<<dp[1]<<"\n";
        if(x == fim){

            int dxx = bx-x;
            dp[1] += dxx + abs(maxy-by);
            dp[0] += dxx + abs(miny-by);
            // cout<<"cabou! dxx = "<<dx<<" = "<<dp[0]<<" "<<dp[1]<<"\n";
        }

        lx = x;
        lmn = miny;
        lmx = maxy;
        prev = dp;
    }

    cout<<min(dp[0], dp[1])<<"\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;
    while(t--) solve();
}