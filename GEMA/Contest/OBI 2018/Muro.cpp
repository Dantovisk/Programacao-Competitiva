#include <bits/stdc++.h>

using namespace std;
#define int long long int

int dp[10010];
int mod = 1e9 + 7;

int32_t main(){
    int n; cin>>n;
    dp[0] = 1;

    for(int i=0; i<n; i++){
        if(i + 1 <= n){
            dp[i+1] += dp[i];
            dp[i+1] %= mod;
        }
        if(i + 2 <= n){
            dp[i+2] += 4*dp[i];
            dp[i+2] %= mod;
        }
        if(i + 3 <= n){
            dp[i+3] += 2*dp[i];
            dp[i+3] %= mod;
        }
    }
    cout<<dp[n]<<"\n";

    return 0;
}