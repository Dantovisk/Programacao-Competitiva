#include <bits/stdc++.h> //Codeforces - D. Flood Fill
using namespace std;

#define MAXN 5010
const int inf = 1e8 + 9999;

int v[MAXN];

//range dp
//dp[i][j][k] = o minimo de turnos para igualar o intervalo [i,j] 
//à cor original de:
//k=0 : cor[i]
//k=0 : cor[j]
int dp[MAXN][MAXN][2];

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>v[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j][0] = dp[i][j][1] = (i == j ? 0 : inf);
        

    for(int s=2; s<=n; s++){
        for(int i=0; i + s - 1 < n; i++){
            int j = i+s-1;

            dp[i][j][0] = min(dp[i+1][j][0] + (v[i] != v[i+1]),
                dp[i+1][j][1] + (v[i] != v[j]));
            dp[i][j][1] = min(dp[i][j-1][1] + (v[j] != v[j-1]),
                dp[i][j-1][0] + (v[i] != v[j]));
        }
    }

    cout<<min(dp[0][n-1][0], dp[0][n-1][1]);



    return 0;
}