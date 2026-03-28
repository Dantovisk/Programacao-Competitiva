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

const int inf = 1e8+3;
int n, m;

void calc(vector<vector<int>> &dp, vector<vector<int>> &lucro){
    dp[0][0] = 0;
    rep(i, 1, n+1){
        dp[i][0] = 0;
        rep(j, 1, m+1){
            rep(k, 0, j+1){
                dp[i][j] = max(dp[i][j], dp[i-1][k] + lucro[i-1][(j-k)]);
            }
        }
    }
}

void calclucro(vi &a, vi &b, vector<vi> &lucro){
    rep(i, 0, n){
        lucro[i][0] = 0;
        rep(j, 1, m+1){
            lucro[i][j] = lucro[i][j-1] + max(0, a[i]-(j-1)*b[i]);
        }
    }
}

void solve(){
    cin>>n>>m;

    vi a(n), b(n);

    rep(i, 0, n) cin>>a[i];
    rep(i, 0, n) cin>>b[i];

    vi a2 = a, b2 = b;
    reverse(all(a2));
    reverse(all(b2));

    vector<vi> lucro(n+2, vi(m+1, 0));
    vector<vi> lucro2(n+2, vi(m+1, 0));

    calclucro(a, b, lucro);
    calclucro(a2, b2, lucro2);

    vector<vector<int>> dp(n+2, vi(m+1, -inf));
    vector<vector<int>> dp2(n+2, vi(m+1, -inf));

    // cout<<"PREFIXO\n\n";
    calc(dp, lucro);
    // cout<<"SUFIXO\n\n";
    calc(dp2, lucro2);

    int res = 0;

    rep(i, 1, n+1){
        rep(j, 0, n+1-i){
            int sobra = m - ((i-1) + j + min((i-1),j));
            if(sobra < 0) break;

            rep(k, 0, sobra+1){
                // cout<<i<<" "<<j<<" "<<k<<" = "<<dp[i][k] + dp2[j][sobra-k]<<"\n";
                res = max(res, dp[i][k] + dp2[j][sobra-k]);
            }
        }
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