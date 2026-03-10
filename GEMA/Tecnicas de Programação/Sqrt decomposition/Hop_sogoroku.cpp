#include <bits/stdc++.h> // Atcoder - Hop Sogoroku
#define MAXN 200010      

using namespace std;

int v[MAXN];

const int inf = 1e9 + 3;
const int mod = 998244353;

int dp[MAXN];

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i =0; i<n; i++) {
        cin>>v[i];
        dp[i] = 1;
    }

    // Tamanho de cada bucket
    int sq = 1;
    while(sq * sq < n) sq++;

    //pref[i][j] = soma de todos os dp[k] tal que k%i = j;
    vector<vector<int>> pref(sq+1, vector<int>(sq+1, 0));


    for(int i = n-1; i>=0; i--){
        if(v[i] >= sq){ //pouquinhos saltos, v[i] não cabe na tabela
            for(int j = i + v[i]; j < n; j += v[i]){
                dp[i] = (dp[i]+dp[j])%mod;
            }
        }
        else { // muitos saltos, usa prefixo
            dp[i] = (dp[i] + pref[v[i]][i%v[i]])%mod;
        }

        for(int j = 1; j <= sq; j++){
            pref[j][i%j] = (pref[j][i%j] + dp[i]) % mod;
        }
    }


    cout<<dp[0]<<"\n";
    return 0;
}