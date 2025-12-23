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

//0 -> nao deixou carry, deixou carry ->
int dp[32][32][2];

void solve(){
    int n, k; cin>>n>>k;

    memset(dp, 0, sizeof(dp));

    if(k==0){
        cout<<"0\n";
        return;
    }

    // for(int i = 20; i>=0; i--){
    //     if((1<<i)&n)cout<<"1";
    //     else cout<<"0";
    // }
    // cout<<"\n";

    rep(i, 0, 31){
        dp[i][0][1] = -1000;
        dp[0][i][1] = -1000;
    }


    rep(i, 1, 31){
        if((1<<(i-1)) & n){
            //caso em que o bit atual é 1
            for(int j = 1; j <= min(k, i); j++){
                // o carry vai propagar sem fazer nada
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + 1);

                //A gente decide propagar na mão
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0] + 1);

                //decido não fazer nada
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0]);
            }
        }else{
            //caso em que o bit atual é 0
            for(int j = 1; j <= min(k, i); j++){
                // decidimos não fazer nada
                dp[i][j][0] = max({dp[i][j][0], dp[i-1][j][0], dp[i-1][j][1]});

                // propagamos na mão
                dp[i][j][1] = max({dp[i][j][1], dp[i-1][j-1][1] + 1});
            }
        }
    }

    int res = k-1;

    rep(i, 1, 31){
        for(int j = 1; j <= min(k, 31); j++){
            res = max(res, dp[i][j][0] + (k-j));
            res = max(res, dp[i][j][1] + (k-j));
        }
    }

    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}