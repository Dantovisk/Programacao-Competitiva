#include <bits/stdc++.h>

using namespace std;

int dp [100010];
int value [100010];

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++) cin>>value[i];

    dp[0]=0;
    dp[1]= abs(value[0]-value[1]);

    for(int i=2; i<n; i++){
        dp[i] = min (dp[i-1]+ abs(value[i]-value[i-1]), dp[i-2]+ abs(value[i]-value[i-2]));
    } 

    cout<<dp[n-1];
    return 0;   
}