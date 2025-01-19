//O - Matching (Atcoder)
#include <bits/stdc++.h>

#define ll long long int
const int MOD = 1e9+7;

using namespace std;

ll dp[1<<21][22];
//dp[i][j] = numero maximo de pares capazes de ser feitos
// com as mulheres da bitmask i, e todos os homens de 0 até j
int adj[22][22];

int main(){
    int n;  cin>>n;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>adj[i][j];
        }
    }

    dp[0][0] = 1;

    //iterando pelos homens
    for(int i=0; i<n; i++){
        //iterando pelas bitmasks de mulheres
        for(int bm = 0; bm<(1<<n); bm++){
            //o numero de mulheres e homens deve ser igual
            int cont = __builtin_popcount(bm);
            if(cont != i) continue;

            //verificando quais mulheres ainda não foram incluidas na bm
            for(int k=0; k<n; k++){
                
                if ((bm & (1<<k)) == 0 && adj[i+1][k+1]){
                    dp[bm | (1<<k)][i+1] += dp[bm][i];
                    dp[bm | (1<<k)][i+1] %= MOD;
                }
            }
        }
    }

    cout<<dp[(1<<n)-1][n]<<"\n";


    return 0;
}