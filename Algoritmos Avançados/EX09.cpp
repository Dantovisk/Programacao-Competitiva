#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int k, n; cin>>k>>n;

    // 0 -> descanso
    // 1-> compro
    // 2 -> garimpo

    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
    dp[0][0] = k; 
    dp[0][1] = -1e16+7; //não posso começar já tendo comprado
    dp[0][2] = k;

    for(int i =1; i<=n; i++){
        ll a; cin>>a;

        //descanso: antes posso ter feito qq coisa
        dp[i][0] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2]});

        //compra: mantenho minha compra anterior, ou compro agr
        ll saldo =  dp[i-1][0] - a;

        //dá pra comprar outro
        if(saldo > 0) 
            dp[i][1] = max(dp[i-1][1], saldo);

        else dp[i][1] = dp[i-1][1]; //so consigo manter compra anterior

        // garimpo: tenho que ter comprado antes
        dp[i][2] = dp[i-1][1] + a;
    }
    cout<< max({dp[n][0], dp[n][1], dp[n][2]})<<"\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin>>t;


    while(t--){
        solve();
    }
    return 0;
}