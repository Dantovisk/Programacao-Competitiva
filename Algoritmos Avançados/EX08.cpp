#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+7;
typedef long long ll;

int dp[30][30];

int v[30];

int calc(int l, int r){
    if(r-l == 1) return max(v[l], v[r]);
    if(dp[l][r] != -1) return dp[l][r];
    //vez da maria
    if((r-l+1) % 2 == 0){
        dp[l][r] = max(calc(l, r-1)+v[r], calc(l+1, r) + v[l]);
    }
    //vez do jose
    else{
        dp[l][r] = min(calc(l, r-1), calc(l+1, r));
    }

    return dp[l][r];
}

void solve(){
    memset(dp, -1, sizeof(dp));
    int n; 
    cin>>n;

    for(int i =0; i<n; i++){
        int a, b;
        scanf(" (%d,%d)", &a, &b);
        v[i] = a+b;
    }

    cout<<calc(0, n-1)<<"\n";
}

int main(){
    int t; cin>>t;

    while(t--) solve();
}