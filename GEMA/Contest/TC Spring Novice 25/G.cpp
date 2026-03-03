#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 1e3+5;

int grid[MAX][MAX];
ll dp[2*MAX][2*MAX];

const ll inf = 1e16 +9;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, m, N, M;
    cin>>n>>m>>N>>M;

    rep(i, 0, n){
        rep(j, 0, m){
            cin>>grid[i][j];
        }
    }
    rep(i, 0, 2*n)
        rep(j, 0, 2*m)
            dp[i][j] = inf;

    dp[0][0] = grid[0][0];

    rep(i, 0, 2*n){
        rep(j, 0, 2*m){
            if(i > 0){
                if(i%2){
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + (N-1)*grid[i/2][j/2]);
                }
                else{
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i/2][j/2]);
                }
            }

            if(j > 0){
                if(j%2){
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + (M-1)*grid[i/2][j/2]);
                }
                else{
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i/2][j/2]);
                }
            }
        }
    }
    cout<<dp[2*n-1][2*m-1]<<"\n";
}