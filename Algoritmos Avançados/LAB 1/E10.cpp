#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, maxW;
    cin>>n>>maxW;

    // v é o número de páginas
    // w é o preço do livro
    vector<int> v(n), w(n), dp(maxW+1, 0);

    for(int i = 0; i<n; i++)
        cin>>w[i];
    for(int i = 0; i<n; i++)
        cin>>v[i];

    // DP Clássica de knapsack
    for(int i = 0; i< n; i++){
        for(int j = maxW; j>=0; j--){
            if(j-w[i] < 0) continue;
            dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }

    cout<<dp[maxW]<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 
    // cin>>t;

    for(int i =0; i<t; i++){
        solve();
    }

}