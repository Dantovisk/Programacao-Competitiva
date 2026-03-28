#include <bits/stdc++.h>
using namespace std;

const long long inf= 1e9+7;

void solve(){
    int n; cin>>n;

    // o vetor e a dp tem uma "gordurinha" para não acessar fora do indice
    vector<int> v(n+4, 1);
    vector<vector<int>> dp(n+4, vector<int>(n+4, 0));

    v[0] = 0;
    v[n+3] = 0;
    for(int i = 2; i<=n+1; i++){
        cin>>v[i];
    }

    //tamanho do intervalo
    for(int s = 1; s<= n; s++){
        //indice do inicio do intervalo
        for(int i =2; i<=n+1; i++){
            //indice do final do intervalo
            int j = i + s-1;
            if(j > n+1) break;
            
            if(s == 1){
                dp[i][j] = v[i-1]*v[i]*v[i+1];
            }
            else{
                //cresci o intervalo pela esquerda ou pela direita
                dp[i][j] = max({
                    dp[i+1][j] + v[i-1] * v[i]*v[j+1],
                    dp[i][j-1] + v[i-1] * v[j]*v[j+1],
                });
            }

            // escolho um ponto intermediário dentro do intervalo
            // para construí-lo por 2 intervalos menores
            for(int k = i+1; k<j; k++){
                dp[i][j] = max(dp[i][j], dp[i][k-1]+dp[k+1][j]+v[i-1]*v[j+1]*v[k]);
            }
        }

    }

    cout<<dp[2][n+1]<<"\n";


}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 
    // cin>>t;

    for(int i =0; i<t; i++){
        solve();
    }

}