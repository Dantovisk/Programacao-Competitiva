#include <bits/stdc++.h>

using namespace std;

int dp [100010];

int main(){
    int n;
    cin>>n;

    vector <int> casas(n);
    int maxdp = 0;

    for(int i=0; i<n; i++){
        cin>>casas[i];
    }

    dp[0] = casas[0];
    for(int i=1; i<n; i++){
        dp[i] = max(dp[i-1]+casas[i], casas[i]);
        maxdp = max(dp[i], maxdp);
    }

    cout<< maxdp;
    
    return 0;
}