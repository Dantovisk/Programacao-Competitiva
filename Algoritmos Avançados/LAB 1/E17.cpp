#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

//dp[i][mask] = formas de organizar as roupas considerando que
//usei as 'i' primeiras roupas para as pessoas indicadas na bitmask
long long dp[110][35000];

//usa[i][j] = 1 se a pessoa i pode usar a roupa j
int usa[20][110];

void solve(){
    int n, m;
    cin>>n>>m;

    dp[0][0] = 1;

    for(int i = 0; i<n; i++){
        int k; cin>>k;

        for(int j = 0; j< k; j++){
            int a; cin>>a;
            usa[i][a] += 1;
        }
    }

    //roupa atual
    for(int rp = 1; rp <= m; rp++){
        //caras que já estão usando uma roupa
        for(int mask = 0; mask < (1<<n); mask++){
            //próximo cara a receber uma roupa
            for(int k = 0; k < n; k++){
                //ele já está usando uma roupa
                if((1<<k) & mask) continue;
                //ele não tem essa roupa
                if(!usa[k][rp]) continue;

                dp[rp][(mask|(1<<k))] += (long long)usa[k][rp]*dp[rp-1][mask];
                dp[rp][(mask|(1<<k))] %= mod;
            }

            //escolho não dar a roupa atual para ninguém
            dp[rp][mask] +=dp[rp-1][mask];
            dp[rp][mask] %= mod;
        }
    }

    cout<<dp[m][(1<<n)-1]<<"\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 
    // cin>>t;

    for(int i =0; i<t; i++){
        solve();
    }

}