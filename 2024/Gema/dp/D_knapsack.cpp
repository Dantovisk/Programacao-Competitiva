#include <bits/stdc++.h>

const long long int inf = 10e17+4;

using namespace std;

long long int dp [100010];      //buscamos o maximo valor possivel em um determinado peso
int value [110], weight[110];

int main(){
    int n, soma;
    cin>>n>>soma;
    for(int i=0; i<n; i++){
        cin>> weight[i]>> value[i];
    }

    for(int i=0; i<n; i++){ //iterando pelos itens
        for(int k=soma; k>0; k--){ //iterando pelas somas
            if (k-weight[i]>=0){
                dp[k] = max(dp[k-weight[i]]+value[i], dp[k]);
            }
        }
    } 

    cout<<dp[soma];

    return 0;   
}