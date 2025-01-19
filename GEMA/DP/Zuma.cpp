#include <bits/stdc++.h>    //Codeforces: B - Zuma

using namespace std;

int v[510];
int dp[510][510];

const int inf = 10000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;

    for(int i=1; i<=n; i++){
        cin>>v[i];
        dp[i][i] = 1;
    }

    for(int i=1; i<n; i++){
        dp[i][i+1] = (v[i] == v[i+1]? 1 : 2);
    }

    for(int s=3; s<=n; s++){
        for(int i=1; i<=n; i++){
            int j = i+s-1;

            if(j>n) break;

            dp[i][j] = inf;

            if(v[i] == v[j]){
                dp[i][j] = dp[i+1][j-1];
            }
            
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
            }
        }
    }

    cout<<dp[1][n]<<"\n";
}

/*
7
1 4 4 2 3 2 1
*/

