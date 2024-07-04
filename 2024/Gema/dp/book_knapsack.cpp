//nesse problema os pesos vão até 10^9
#include <bits/stdc++.h>
const int inf = 1e9+4;

using namespace std;

int dp [100010];      //buscamos o maximo valor possivel em um determinado peso
int value [1010], weight[1010];

int main(){
    int n, soma;
    cin>>n>>soma;
    for(int i=0; i<n; i++){
        cin>> weight[i];
    }
    for(int i=0; i<n; i++){
        cin>> value[i];
    }
    dp[0]=0;
    for(int i=0; i<n; i++){
        for(int k=soma; k>0; k--){
            if(k<weight[i])break;
            dp[k] = max(dp[k], dp[k-weight[i]]+value[i]);
        }
    }
    
    cout<<dp[soma];
    return 0;   
}