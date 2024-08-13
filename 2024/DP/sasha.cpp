#include <bits/stdc++.h> //INCOMPLETO
#define MOD 998244353       //se pa q nao consigo fazer esse ainda

using namespace std;

int dp [300010][2]; //dp[i][0] não escolhe i, dp[i][1] escolhe i 
int n, m;
vector <int> adj[300010];

void dfs(int v, int parent){
    dp[v][0] = 1;
    dp[v][1] = 0;

    long long int cont = 1;

    for(int x: adj[v]){
        if(x != parent){
            dfs(x, v);
            
            dp[v][0] = dp[v][0] *(dp[x][0] + dp[x][1]) %MOD;
            cont = cont * dp[x][0] % MOD;
        }
    }
    dp[v][1] = cont;
}

int main(){
    int z;
    cin>>z;

    while(z--){
        cin>>n;

        for(int i=1; i<n; i++){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(1, 0);

        long long int resp = 1;
        
        
        cout<<resp;

        memset(dp, 0, sizeof(dp));
    }
    

    return 0;
}