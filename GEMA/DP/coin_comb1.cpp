#include <bits/stdc++.h>

using namespace std;

int dp[1000010];
vector <int> c;

const int mod = 1e9 + 7;

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        int a; cin>>a;
        c.push_back(a);
    }

    dp[0] = 1;
    for(int i=1; i<=m; i++){
        for(int x : c){
            if(i-x < 0) continue;
            dp[i] += dp[i-x];
            dp[i] %= mod;
        }
    }

    cout<<dp[m]<<endl;

    return 0;
}