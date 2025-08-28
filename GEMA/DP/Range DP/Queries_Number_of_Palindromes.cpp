#include <bits/stdc++.h>

using namespace std;

int dp[5000][5000];
int pali[5000][5000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string cr7;
    cin>>cr7;
    int q; cin>>q;
    int n = cr7.length();

    for(int i=0; i<n; i++){
        dp[i][1] = 1; 
        pali[i][1] = 1;
        pali[i][0] = 1;
    }

    for(int s=2; s<=n; s++){
        for(int i=0; i<n; i++){
            if(i+s > n) break;

            int j = i+s-1;

            pali[i][s] = pali[i+1][s-2] && (cr7[i] == cr7[j]);

            //principio da inclusao exclusao
            dp[i][s] = dp[i][s-1] + dp[i+1][s-1] + pali[i][s] - dp[i+1][s-2]; 
        }
    }

    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        cout<<dp[a-1][b-a+1]<<"\n";
    }


}