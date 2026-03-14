#include <bits/stdc++.h>
using namespace std;

void solve(){
    //V é a soma total, M é a quantidade de moedas
    int v, m;
    cin>>v>>m;
    vector<int> moedas;
    for(int i = 0; i< m; i++){
        int k;  cin>>k;
        moedas.push_back(k);
    }

    vector<int> dp(v+1, 10000000);
    dp[0] = 0;

    // DP Clássica da Moeda
    for(int i = 0; i< v; i++){
        for(auto moeda: moedas){
            if(i + moeda > v) continue;
            dp[i+moeda] = min(dp[i+moeda], dp[i] + 1);
        }
    }

    cout<<dp[v]<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 
    cin>>t;

    for(int i =0; i<t; i++){
        solve();
    }

}