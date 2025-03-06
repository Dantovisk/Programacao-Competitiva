#include <bits/stdc++.h>

using namespace std;
int n, m;
vector<int> adj[25];
int dp[21][1100000]; 
const int mod = 1e9 +7;

int main(){
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
    }

    dp[1][1] = 1;

    
    for(int bm=1; bm< (1<<(n-1)); bm++){ //iterando por todas as mascaras  
        for(int i=1; i<n; i++){    //iterando pontos de parida
            if(!(((1<<(i-1))& bm))) continue;

            for(int x: adj[i]){ //
                int mask = (1<<(x-1));
                if(!(mask & bm)){
                    dp[x][bm | mask] = (dp[x][bm | mask]+dp[i][bm])%mod;
                }
            }
        }

    }
    

    cout<<dp[n][(1<<n)-1];

    return 0;
}