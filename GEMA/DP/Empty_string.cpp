#include <bits/stdc++.h>    //cses

using namespace std;

string s;
int dp[510][510];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>s;
    int n = s.length();

    for(int i=0; i<n-1; i++){
        if(s[i] == s[i+1]) dp[i][i+1] = 1;
        dp[i][2] = 0;
    }


    for(int s=4; s<=n; s+= 2){
        for(int i=0; i<n; i++){
            int j = i+s-1;
            if(j>=n) break;

            //a transição ainda nao ta clara pra mim

            
        }
    }
    
}