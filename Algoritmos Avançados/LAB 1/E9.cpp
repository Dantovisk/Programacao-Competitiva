#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;

    vector<int> v(n), dp(n, 0);

    for(int i = 0; i<n; i++)
        cin>>v[i];

    // DP da mochila
    for(int i = 0; i<=n; i++){
        // Nunca compenas pegar um pedaço com tamanho maior que 100
        // Pois os valores estão limitados
        for(int j = 0; j< min(100, n); j++){
            if(i - j - 1 < 0) continue;
            
            dp[i] = max(dp[i], dp[i-j-1] + v[j]);
        }
    }

    cout<<dp[n]<<"\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 
    // cin>>t;

    for(int i =0; i<t; i++){
        solve();
    }

}