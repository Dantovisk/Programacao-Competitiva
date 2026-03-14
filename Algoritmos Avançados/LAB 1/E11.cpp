#include <bits/stdc++.h>
using namespace std;
const int inf= 1e6+4;

void solve(){
    int n;
    cin>>n;

    vector<int> v(n), dp(n+1, inf);

    for(int i = 0; i<n; i++)
        cin>>v[i];
    
    dp[n] = 0;
    // A linha de chegada precisa de 0 saltos
    dp[n-1] = 0;

    // Faz a DP de trás pra frente (da linha de chegada ao início)
    for(int i = n-1; i>= 0; i--){
        //todos os valores possíveis de salto
        for(int j = 1; j<= v[i]; j++){
            if(i+j > n) break;

            dp[i] = min(dp[i], dp[i+j]+1);
        }
    }

    if(dp[0] >= inf) cout<<"Salto impossivel\n";
    else cout<<dp[0]<<"\n";
    

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 
    // cin>>t;

    for(int i =0; i<t; i++){
        solve();
    }

}