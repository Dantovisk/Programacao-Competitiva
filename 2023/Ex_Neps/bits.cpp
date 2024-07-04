#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define MOD 1000000007 //o módulo para evitar overflow de dados

ll dp[1010][1010];
int n, k;  //numero de bits, numero de vezes que não pode se repetir

//Lembre-se de tirar o módulo após cada operação de soma para evitar overflow. 
//Lembre-se também de definir os casos base da DP, as sequência de tamanho 1.


int main(){
    cin>>n>>k;

    dp[1][0]=1; 
    dp[1][1]=1;

    for(int i=1; i<n; i++){
        for(int j=0; j<min(i+1,k); j++){
            dp[i+1][0]+=dp[i][j]; //se adicionar 0 no final, só somar com o anterior e mudar o numero
            dp[i+1][0]=dp[i+1][0] % MOD; //de consecutivos para 0
            dp[i+1][j+1]+=dp[i][j]; //se adicionar 1 no final, somar com anterior a aumentar o j
            dp[i+1][j+1]=dp[i+1][j+1] % MOD; //o j não deve ser igual a k
        }
    }

    int resposta = 0;
    for(int i=0; i<k; i++){
        resposta = (resposta+dp[n][i]) % MOD;
    }
    cout<<resposta;
    return 0;
}