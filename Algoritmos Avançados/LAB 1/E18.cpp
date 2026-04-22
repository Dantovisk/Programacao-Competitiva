#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e5+7;

//ALGORITMO DE KOSARAJU
int vis[MAX];
vector<int> adj[MAX];
vector<int> adjT[MAX];
stack<int> st;

//1ª DFS do kosaraju
void dfs(int u){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v]) dfs(v);
    }
    st.push(u);
}

//2ª dfs do kosaraju, que encontra os SCCs
void scc(int u){
    vis[u] = 1;
    for(auto v: adjT[u]){
        if(!vis[v]) scc(v);
    }
}


void solve(){
    int n, m;
    cin>>n>>m;
    
    for(int i = 0; i< m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }
    
    dfs(1);
    if(st.size() < n){
        //a primeira dfs não achou todos os vértices.
        //O grafo nem sequer é conectado
        cout<<"NAO\n";
        return;
    }

    //limpa o vetor de visitados para usar de novo
    memset(vis, 0, sizeof(int)*(n+1));


    //verfica se temos mais de 1 SCC
    int cont = 0;
    while(!st.empty()){
        int u = st.top();
        st.pop();

        // Vertice já foi visitado?
        if(vis[u]) continue;

        //Visita o scc do vertice
        cont++;
        scc(u);
    }

    if(cont > 1){
        cout<<"NAO\n";
    }
    else cout<<"SIM\n";

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t = 1; 

    for(int i =0; i<t; i++){
        solve();
    }

}