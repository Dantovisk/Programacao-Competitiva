#include <bits/stdc++.h>

using namespace std;

int dp[1010][1010];
int A[1010];
int B[1010];

int main(){
    int n, k;
    cin>>n>>k;

    for(int i=0; i<n;i++){
        cin>>A[i];
    }
    for(int i=0; i<k;i++){
        cin>>B[i];
    }

    for(int i=1; i<=n;i++){
        for(int j=1; j<=k;j++){
            if(A[i-1]==B[j-1]){
                dp[i][j]=dp[i-1][j-1]+=1;
            }else{
                dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
            }

        }
    }
    cout<<n-dp[n][k]<<" "<<k-dp[n][k];

    return 0;
}