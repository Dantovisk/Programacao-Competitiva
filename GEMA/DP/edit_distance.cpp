#include <bits/stdc++.h>    //CSES - Edit Distance

using namespace std;

int dp [5010][5010];

int main(){
    int n, m;
    string a, b;
    cin>>a>>b;
    n = a.length();
    m = b.length();

    for(int i=0; i<= max(n,m); i++){
        dp[i][0] = i;
        dp[0][i] = i;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            int c = (a[i-1] == b[j-1] ? 0 : 1);
            //inserir, remover e modificar respectivamente
            dp[i][j] = min({dp[i][j-1] + 1,
            dp[i-1][j] + 1, dp[i-1][j-1] + c});
        }
    }

    cout<<dp[n][m];


    return 0;
}