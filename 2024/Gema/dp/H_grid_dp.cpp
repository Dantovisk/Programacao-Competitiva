//nesse problema os pesos vão até 10^9
#include <bits/stdc++.h>
const int mod = 1e9+7;

using namespace std;

int dp [1010][1010];      //buscamos o minimo peso possivel em um determinado valor
char val [1010][1010];

int main(){
    int n, m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>val[i][j];
        }
    }
    dp[0][0]=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(val[i][j] != '#'){
                if(j>0) dp[i][j]+=dp[i][j-1];
                if(i>0) dp[i][j]+=dp[i-1][j];
                dp[i][j]%=mod;
            }
        }
    }
    cout<<dp[n-1][m-1];
    return 0;   
}