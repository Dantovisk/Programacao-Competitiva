#include <bits/stdc++.h>    //Codeforces: Array Shrinking

using namespace std;

int v[510];

// Quantidade minima de elementos resultantes
int dp[510][510];

// Valor resultante
int res[510][510]; 

const int inf = 10000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin>>n;

    for(int i =0; i<=n; i++) {
        for(int j =0; j<=n; j++) {
            dp[i][j] = inf;
        }
    }

    for(int i =1; i<=n; i++) {
        cin>>v[i];
        res[i][i] = v[i];
        dp[i][i] = 1;
    }


    for(int s = 2; s<=n; s++){
        for(int i =1; i<=n; i++){
            int j = i+s-1;
            if(j>n) break;

            for(int mid = i +1; mid<= j; mid++){
                if(dp[i][mid-1] == 1 &&  dp[mid][j]  == 1){
                    if(res[i][mid-1] == res[mid][j]){
                        dp[i][j] = 1;
                        res[i][j] = res[i][mid-1] + 1;
                        break;
                    }
                    else{
                        dp[i][j] = min(dp[i][j], 2);
                    }
                }
                else{
                    dp[i][j] = min(dp[i][j], dp[i][mid-1] + dp[mid][j]);
                }
            }
        }
    }

    cout<<dp[1][n]<<"\n";
}
