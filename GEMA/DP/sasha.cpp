#include <bits/stdc++.h> //INCOMPLETO - me falta inverso modular
#define MOD 998244353    //se pa q nao consigo fazer esse ainda

using namespace std;

/*
dp[i][0]: N de maneiras de escolher 0 interseções perigosas 
na subárvore enraizada em i.
dp[i][1]: 1 interseção perigosa na subárvore enraizada em i.
dp[i][2]: 2 interseções perigosas na subárvore enraizada em i.
*/

long long int dp [300010][3]; 
int n, m;
vector <int> adj[300010];

void dfs(int v, int parent){
    dp[v][0] = 1;
    dp[v][1] = 0;

    long long int prod0 = 1;
    long long int sum1 = 0;

    for(int x: adj[v]){
        if(x != parent){
            dfs(x, v);

            prod0 *= dp[x][0];
            prod0 %= MOD;
            sum1 += dp[x][1];
            sum1 %= MOD;
            
        }
    }
    dp[v][0] = prod0;

    dp[v][1] = prod0;
    dp[v][1] += (sum1 * prod0) % MOD;

    dp[v][2] = 1;

    for(int i=0; i<adj[v].size(); i++){
        for(int j=0; j<adj[v].size(); j++){
            if(i != j){
                dp[v][2] = (dp[v][2]+((dp[i][1]+dp[j][1])%MOD))%MOD;
            }
        }
    }

    dp[v][2] = dp[v][2]*((sum1 * prod0) % MOD)%MOD;
}

int main(){
    int z;
    cin>>z;

    while(z--){
        cin>>n;

        for(int i=1; i<=n; i++){
            adj[i].clear();
        }

        for(int i=1; i<n; i++){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(1, 0);

        long long int resp = 0;
        resp = ((dp[1][0]+dp[1][1])%MOD + dp[1][2])%MOD;
        
        cout<<resp<<"\n";

        memset(dp, 0, sizeof(dp));
    }
    

    return 0;
}