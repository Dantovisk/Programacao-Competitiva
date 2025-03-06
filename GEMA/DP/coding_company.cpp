#include <bits/stdc++.h>    //CSES - Coding Company

using namespace std;

int v[5010];    //o valor e o peso dos itens é igual
const int mod = 1e9 + 7;

// dp[i][j][k] numero de formas que conseguimos criar times
// com as primeiras i pessoas
// tendo j pessoas nao participando e a penalidade total é k
int dp[102][102][102];

int main(){
    int n, m;
    cin>>n>>m;

    
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    sort(v, v+n);

    //vamos fazer um tipo diferente de knapsack
    

    //iterando pelas primeiras pessoas
    for(int i=0; i<=n; i++){
        //iterando pelo numero de pessoas faltando
        for(int j =0; j <= (n-i); j++){
            //iterando pela penalidade
            for(int k =0; k < n; k++){
                dp[i][j][k] += dp[i-1][j][k];
                
            }
        }

    }

    int resp = 0;
    for(int i=0; i<m; i++){
        for(int j=0; i<n-i; i++){
            
        }
    }
    cout<<resp<<"\n";

    return 0;
}