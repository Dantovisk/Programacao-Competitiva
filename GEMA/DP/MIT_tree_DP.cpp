//dessa vez o objetivo é minimizar o peso para um dado valor
#include <bits/stdc++.h>

using namespace std;

const long long int inf = 1e6 + 9;

vector<int> adj[100010];
int dp[100010][3];  //dp[i][0] -> numero minimo de paredes para nao interligar i a P ou S
//dp[i][1] -> para interligar no maximo a P
//dp[i][2] -> para interligar no maximo a S
int n;
string S;

void dfs(int k){
    dp[k][0] = inf;
    if(S[k] == 'P') dp[k][2] = inf;
    else dp[k][2] = 0;
    if(S[k] == 'S') dp[k][1] = inf;
    else dp[k][1] = 0;

    int cont = 0;
    if(S[k] != 'C') cont = inf;
    
    for(int x: adj[k]){
        dfs(x);
        dp[k][1] += min({dp[x][1], dp[x][2] + 1, dp[x][0]});
        dp[k][2] += min({dp[x][2], dp[x][1] + 1, dp[x][0]});
        cont += dp[x][0];
    }

    dp[k][0] = min({dp[k][1] + 1, dp[k][2] + 1, cont});
}

int main(){
    int k;
    cin>>k;
    while(k--){
        cin>>n;
        for(int i=1; i<=n; i++){
            adj[i].clear();
        }
        memset(dp, 0, sizeof(dp));
        for(int i=2; i<=n; i++){
            int a; cin>>a;
            adj[a].push_back(i);
        }

        cin>>S;
        S = "X" + S;

        dfs(1);

        cout<<min({dp[1][0], dp[1][1], dp[1][2]})<<endl;
    }

    
    
    return 0;
}