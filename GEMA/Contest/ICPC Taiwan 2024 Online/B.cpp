#include <bits/stdc++.h>

using namespace std;
const int MAX = 3e5+3;

#define ll long long

ll v[MAX], v2[MAX], dp[MAX];

int main(){
    int n; cin>>n;

    ll s = 0;

    for(int i =1; i<=n; i++){
        cin>>v[i];
        v2[i] = (v[i] < 0? v[i]*3LL : v[i]);
        s+= abs(v[i]);
    }
    dp[0] = s;

    for(int i =1; i<=n; i++){
        ll k = dp[i-1] + v2[i];
        if(k > s) dp[i] = k;
        else dp[i] = s;
    }

    cout<<(*max_element(dp, dp+n+1))<<"\n";

    return 0;
}