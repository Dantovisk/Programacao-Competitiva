#include <bits/stdc++.h>

using namespace std;

string grid[1010];
int dp[1010][1010];

const int mod = 1e9+7;

int main(){
    int n; cin>>n;

    
    for(int i=0; i<n; i++){
        cin>>grid[i];
    }
    dp[0][0] = (grid[0][0]=='.'? 1:0);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(grid[i][j] == '*'){
                continue;
            }
            dp[i][j] += (i>0? dp[i-1][j]: 0);
            dp[i][j] %= mod;
            dp[i][j] += (j>0? dp[i][j-1]: 0);
            dp[i][j] %= mod;
        }
    }

    cout<<dp[n-1][n-1]<<endl;

    return 0;
}