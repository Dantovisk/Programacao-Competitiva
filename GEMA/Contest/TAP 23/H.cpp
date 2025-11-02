#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const int MAX = 1e3+9;

//vertical 
ll dp[MAX][2];
int grid[MAX][MAX];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;


    vector<pii> pos(n*n+1);

    ll res = 0;

    rep(i, 1, n+1){
        rep(j, 1, n+1){
            cin>>grid[i][j];
            pos[grid[i][j]] = {i, j};
        }
    }

    for(int i =1; i<= n*n; i++){
        auto [x, y] = pos[i];
        ll k = dp[x][0];
        dp[x][0] = max(dp[y][1] + 1, dp[x][0]);
        dp[y][1] = max(k + 1, dp[y][1]);

        res = max({res, dp[x][0], dp[y][1]});

        // rep(i, 1, n+1){
        //     cout<<dp[i][0]<<" "<<dp[i][1]<<" - ";
        // }cout<<"\n";
    }
    cout<<res<<"\n";
}