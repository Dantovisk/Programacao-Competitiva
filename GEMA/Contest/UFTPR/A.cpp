#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

int n, m;
int tin[MAXN], tout[MAXN];
pair<int,int> v[MAXN];
int dp[100];

int32_t main(){
    cin>>n;
    for(int i =0; i< n; i++){
        cin>>tin[i]>>tout[i];
        v[i] = {tin[i] +1, tout[i] + 1};
    }

    sort(v, v+n);
    
    for(int j=0; j<n; j++){
        auto [ti, to] = v[j];
        for(int i = 0; i <= ti; i++)
            dp[to] = max(dp[to], dp[i]+1);
    }
    int res = 0;
    for(int i =0; i<=25; i++){
        cout<<i<<": "<<dp[i]<<"\n";
        res = max(res, dp[i]);
    } 
    cout<<res<<"\n";
}