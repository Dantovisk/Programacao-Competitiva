#include <bits/stdc++.h> // Atcoder - V. Subtree
#define MAXN 200010      // quando m não é primo, a solução não funciona
#define int long long

using namespace std;

vector<int> adj[MAXN];
int n, m;

int mexp(int b, int p){
    if(p == 1) return b;
    if(p == 0) return 1;

    int k = mexp(b, p/2);

    if(p%2) return (((k*k)%m)*b)%m;
    return (k*k)%m;
}

// dp[i][0] => quant de formas de pintar a subarvore i 
// com o vertice i sendo preto
// ou NENHUM vértice da subárvore de i sendo preto

// dp[i][1] => quant de formas de pintar a arvore desconsiderando
// a subarvore de i
int dp[MAXN][2]; 
int resp[MAXN];

//primeiro calcula a dp a partir da raiz em 1
void dfs1(int u, int p){
    dp[u][0] = 1;
    dp[u][1] = 1;

    for(auto v: adj[u]){
        if(v == p) continue;
        
        dfs1(v, u);

        //vértice branco tem subárvore apenas branca
        dp[u][0] *= dp[v][0];
        dp[u][0] %= m;

        //vértice preto pode ter filhos das 2 cores
        dp[u][1] *= (dp[v][0] + dp[v][1]);
        dp[u][1] %= m;
    }
}

//rotação da raiz
void dfs2(int u = 1, int p = 0){
    resp[u] = dp[u][1];
    for(auto v: adj[u]){
        if(v == p) continue;
        
        // v passa a ser a raíz

        // tira a subarvore de v da contagem de u
        //dp[u][0] /= dp[v][0]; 
        dp[u][0] *= mexp(dp[v][0], m - 2);
        dp[u][0] %= m;

        //dp[u][1] /= (dp[v][0] + dp[v][1]);
        int k = (dp[v][0] + dp[v][1]) % m;
        dp[u][1] *= mexp(k, m - 2);
        dp[u][1] %= m;

        //agora adiciona u a contagem de v
        dp[v][0] *= dp[u][0];
        dp[v][0] %= m;
        dp[v][1] *= (dp[u][0] + dp[u][1]);
        dp[v][1] %= m;

        dfs2(v, u);

        // u volta a ser a raíz

        // tira a subarvore de u da contagem de v
        //dp[v][0] /= dp[u][0]; 
        dp[v][0] *= mexp(dp[u][0], m - 2);
        dp[v][0] %= m;

        //dp[v][1] /= (dp[u][0] + dp[u][1]);
        k = (dp[u][0] + dp[u][1]) % m;
        dp[v][1] *= mexp(k, m - 2);
        dp[v][1] %= m;

        //agora adiciona v a contagem de u
        dp[u][0] *= dp[v][0];
        dp[u][0] %= m;
        dp[u][1] *= (dp[v][0] + dp[v][1]);
        dp[u][1] %= m;

       
    }
}

int32_t main(){
    cin>>n>>m;

    for(int i = 1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2();

    for(int i =1; i<=n; i++) cout<<resp[i]<<"\n";

    return 0;
}