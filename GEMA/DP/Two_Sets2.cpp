#include <bits/stdc++.h>    //CSES - Empty String
#define ll long long
using namespace std;

int dp[150'000];
const int mod = 1e9+7;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;
    int sum = ((1+n)*n)/2;

    if(sum%2){
        cout<<"0\n";
        return 0;
    }

    dp[0] = 1;

    for(int c = 1; c<=n; c++){
        for(int i = sum/2; i >= c; i--){
            dp[i] += dp[i-c];
            dp[i] %= mod;
        }
    }
    
    ll res = dp[sum/2];
    res *= 500'000'004LL; //inverso de 2 mod 1e9+7
    res %= (ll)mod;
    cout<<res<<"\n";
    
}
