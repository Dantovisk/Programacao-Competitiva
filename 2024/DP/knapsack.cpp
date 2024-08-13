#include <bits/stdc++.h>

using namespace std;

int v[110], w[110], dp[100010];

int main(){
    int n, m;
    cin >> n >> m;

    for (int i=0; i<n; i++){
        cin>>w[i]>>v[i];
    }

    for(int i=0; i<n; i++){
        for(int j=m; j>0; j--){
            if(j-w[i]>=0){
                dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
            }
        }
    }

    cout<<dp[m];
    return 0;
}