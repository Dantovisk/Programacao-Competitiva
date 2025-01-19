#include <bits/stdc++.h>    //removing digits - CSES

using namespace std;

int dp[1000010];
const int inf = 1e9 + 3;
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        dp[i] = inf;
    }
    dp[n] = 0;

    for(int i=n; i>0; i--){
        if(dp[i] == inf) continue;
        set <int> a;
        int k = i;
        while(k>0){
            a.insert(k%10);
            k/=10;
        }
        for(int x: a) dp[i-x] = min(dp[i-x], dp[i]+1);
    }

    cout<<dp[0];
}