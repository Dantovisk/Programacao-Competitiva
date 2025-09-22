#include <bits/stdc++.h>
#define ll long long

using namespace std;


ll dp[600'010];
int p[10010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;


    long long res = 0;

    int maxn = 0;

    for(int i = 0; i<n; i++) {
        cin>>p[i];
        maxn += p[i];
    }

    sort(p, p+n); reverse(p, p+n);

    int mid = (maxn+(maxn%2 ? 1: 2))/2;

    dp[0] = 1;

    for(int c = 0; c<n; c++){
        for(int j = maxn; j>0; j--){
            if(j - p[c] < 0) continue;
            dp[j] += dp[j-p[c]];

            if(j >= mid && j - p[c] < mid) res += dp[j-p[c]];
        }
    }

    cout<<res<<"\n";

}