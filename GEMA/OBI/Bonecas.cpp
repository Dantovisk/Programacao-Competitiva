#include <bits/stdc++.h>    //OBI 2023 - Terceira fase

#define int long long
#define MAXN 10010
using namespace std;

const int inf = 1e18 + 77;
int v[MAXN];
int dp[MAXN][3010]; //indice atual da boneca, quantos trios foram formados

int32_t main() {
    int n, k;
    cin>>n>>k;

    for(int i=1; i<=n; i++) cin>> v[i];
    sort(v+1, v+n+1);
    reverse(v+1, v+n+1);

    //eh impossivel de ter formado trios
    for(int i= 1; i<= k; i++) dp[1][i] = inf;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(3*j>i) {
                dp[i][j] = inf;
                continue;
            }
            dp[i][j] = min(dp[i-1][j], dp[i-2][j-1] +
                ((v[i-1] - v[i])*(v[i-1] - v[i])));
        }
    }

    cout<<dp[n][k];
    return 0;
}