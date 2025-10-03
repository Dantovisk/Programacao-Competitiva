#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+7;
typedef long long ll;

ll v[MAX];

ll dp[MAX][2]; 
//0-> quebrei o cara sem ajuda do de baixo
//1-> o anterior será quebrado antes

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin>>n;

    for(int i =1; i<=n; i++){
        cin>>v[i];
    }

    dp[0][1] = 1;
    dp[0][0] = 0;

    for(int i =1; i<=n; i++){
        ll k = min(dp[i-1][0], max(dp[i-1][1]-(i-1), 0LL));

        dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + v[i];

        dp[i][1] = min(dp[i-1][1] + (v[i] - 1LL), dp[i-1][0] + max(v[i] - (i-1), 0LL));
        // cout<<i<<": "<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }

    cout<<min(dp[n][0], dp[n][1])<<"\n";
    return 0;
}