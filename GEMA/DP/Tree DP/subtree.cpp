#include <bits/stdc++.h> // Atcoder - V. Subtree
#define MAXN 200010      
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
// portanto dp[i][0] = 2, sendo i uma raiz

// dp[i][1] => quant de formas de pintar a arvore desconsiderando
// a subarvore de i (ou o pai de i é preto, ou todos os nós da 
// subarvore i sao brancos)
// portanto dp[1][1] = 1
int dp[MAXN][2]; 
int resp[MAXN];
int par[MAXN];

//primeiro calcula a dp[i][0] a partir da raiz
void dfs1(int u, int p){
    dp[u][0] = 1;

    for(auto v: adj[u]){
        if(v == p) continue;
        par[v] = u;
        
        dfs1(v, u);
        dp[u][0] *= dp[v][0];
        dp[u][0] %= m;
    }

    dp[u][0]++;
}

// agora calcularemos dp[i][1] para todo i 
void dfs2(int u = 1, int p = 0){
    int sz = adj[u].size();
    vector<int> child;

    for(auto v: adj[u])
        if(v != p)
            child.push_back(v);

    int k = child.size();
    vector<int> pref(k + 1, 1), suff(k + 1, 1);

    for(int i = 0; i < k; i++){
        pref[i+1] = (pref[i] * dp[child[i]][0]) % m;
    }

    for(int i = k - 1; i >= 0; i--){
        suff[i] = (suff[i+1] * dp[child[i]][0]) % m;
    }

    for(int i = 0; i < k; i++){
        int v = child[i];

        int prod = (pref[i] * suff[i+1]) % m;

        dp[v][1] = (1 + (dp[u][1] * prod) % m) % m;

        dfs2(v, u);
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
    dp[1][1] = 1;

    dfs1(1, 0);
    dfs2();

    for(int i =1; i<=n; i++) {
        cout<<((dp[i][0] - 1 + m) * (dp[i][1]))%m<<"\n";
    }
    return 0;
}