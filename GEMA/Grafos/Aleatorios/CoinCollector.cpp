// Solucao eh fazer kosaraju pra ter um DAG
// Aí basta fazer uma dp com toposort pra achar a resposta

#include <bits/stdc++.h> //CSES - Coin Collector
#define MAXN 100010
#define int long long int
using namespace std;

vector<int> adj[MAXN], adjT[MAXN];
int coins [MAXN];
int vis[MAXN];
int n, m;

//para kosaraju
int component[MAXN];
int compCoins[MAXN];
vector<int> compVertex[MAXN];
vector <int> compAdj[MAXN];
int compIndex = 0;
stack <int> st;

//para toposort
queue <int> q;
int grau[MAXN];
vector <int> resp;
int dp[MAXN];

void dfs1(int u){
    vis[u] = 1;
    for(int x: adj[u]){
        if(!vis[x]) dfs1(x);
    }
    st.push(u);
}

void dfs2(int u){
    vis[u] = 1;
    component[u] = compIndex;
    compCoins[compIndex] += coins[u];
    compVertex[compIndex].push_back(u);

    //cout<<u<<" ";

    for(int x: adjT[u]){
        if(!vis[x]) dfs2(x);
    }
}

void kosaraju(){
    for(int i=1; i<=n; i++){
        if(!vis[i]) dfs1(i);
    }

    memset(vis, 0, sizeof(vis));

    while(!st.empty()){
        int k = st.top();
        st.pop();

        if(!vis[k]){
            //cout<<"\nComponente "<<compIndex<<" : ";
            dfs2(k);
            compIndex++;
        }
    }
}



int32_t main(){
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        cin>>coins[i];
    }

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }

    kosaraju();

    

    for(int i=1; i<=n; i++){
        for(int x: adj[i]){
            if(component[i] != component[x]){
                compAdj[component[i]].push_back(component[x]);
                grau[component[x]]++;
            }
        }
    }

    // Agora temos um DAG
    // Usaremos toposort para encontrar o caminho da resposta
    for(int i=0; i< compIndex; i++){
        if(grau[i] == 0) q.push(i);
        dp[i] = compCoins[i];
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        resp.push_back(u);

        for(int x: compAdj[u]){
            grau[x]--;
            if(grau[x] <=0) q.push(x);
        }
    }

    int maxResp = 0;
    for(int x: resp){
        for(int k: compAdj[x]){
            dp[k] = max(dp[k], dp[x] + compCoins[k]);
        }
        maxResp = max(maxResp, dp[x]);
    }

    
    cout<<maxResp<<"\n";
    //cout<<"\n";
    //for(int x: resp) cout<<x<<" "; 

    return 0;
}