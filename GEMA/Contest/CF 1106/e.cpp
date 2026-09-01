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

const int maxn = 510;
const int inf = 1e9+3;

//  dp[i][j][k] = max q dá pra obrigar que peguem
//  i = posicao no prefixo
//  j = qtos false eu tenho
//  k = tamanho da janela otima até agora (qtd sufixo)
int dp[maxn][maxn][maxn];

/*
FFTTTFFT
-1 -1 +1 +1 +1 -1 -1 +1
seis sete resenha
*/

int v[maxn]; 

/*
vou add um novo cara:
dp[i] = max(v[i], dp[i-1]+v[i])
*/

void solve(){
    int n;
    string a;
    cin>>n>>a;

    int r = 0;
    rep(i, 0, n) if(a[i] == 'F') r++;

    rep(i, 0, n + 2)
        rep(j, 0, n + 2)
            rep(k, 0, n + 2) dp[i][j][k] = maxn;

    dp[0][0][0] = 0;
 
    for(int i = 0; i<n; i++){
        for(int j = 0; j<=i; j++){
            for(int k = 0; k<=i; k++){
                if(dp[i][j][k] == maxn) continue; //n consigo partir dele

                if(a[i] == 'F' or a[i] == 'N'){
                    dp[i+1][j+1][k+1] = min(dp[i+1][j+1][k+1], max(dp[i][j][k], k+1)); //continuo
                    // dp[i+1][j+1][1] = min(dp[i+1][j+1][1], max(dp[i][j][k], 1)); //reseto
                }

                if(a[i] == 'T' or a[i] == 'N'){
                    if(k > 0)
                        dp[i+1][j][k-1] = min(dp[i+1][j][k-1], max(dp[i][j][k], k-1)); //continuo
                    else
                        dp[i+1][j][0] = min(dp[i+1][j][0], max(dp[i][j][k], 0)); //reseto
                }
            }
        }
    }

    int res = 0;
    rep(i, 0, n){
        rep(j, 0, n){
            // cout<<i<<" - dp[n]["<<i<<"]["<<j<<"] = "<<dp[n][i][j]<<"\n";
            if(dp[n][i][j] != maxn) res = max(res, i - dp[n][i][j]);
        }
    }
    
    cout<<res<<"\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}