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


void solve(){
    int n, k;
    cin>>n>>k;

    int dig = 0;
    rep(i, 0, 31){
        if((1<<i) & n) dig = i;
    }

    vector<vi> dp(34, vi(65, 0));

    dp[0][0] = 1;
    int res = 0;

    rep(i, 0, 32){
        dp[i][0] = 1; 
    }

    //digito atual
    for(int i = dig-1; i>=0 ; i--){
        //custo
        for(int j = 62; j>= 1; j--){
            if(j==1){
                //coloquei um 1 só agora
                dp[i][j] = 1;
            }
            else{
                //usei 0 agora
                dp[i][j] += dp[i+1][j-1];

                //usei 1 agora
                if(j > 2)
                    dp[i][j] += dp[i+1][j-2];
            }
        }
    }

    rep(j, k+1, 64){
        res += dp[0][j];
    }

    // cout<<res<<" uai\n";

    if(dig >= k) res++;
    cout<<res<<"\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}