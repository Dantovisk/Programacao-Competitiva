//Two sets - CSES
#include <bits/stdc++.h>

using namespace std;

int dp[200010];

int main(){
    int n; cin>>n;

    dp[0] = 1;

    if((n*(1+n)) %2 == 1){
        cout<<0;
        return 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=(n*(1+n))/2; j>0; j--){
            if(j-i < 0) continue;
            dp[j] += dp[j-i];
        }
    }

    cout<<dp[(n*(1+n))/4]/2;

    return 0;
}