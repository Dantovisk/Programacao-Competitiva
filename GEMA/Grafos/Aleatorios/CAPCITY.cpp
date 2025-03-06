// a solucao consistirá em aplicar kosaraju para transformar o grafo
// em um DAG com componentes fortemente conectados
// Assim fica fácil encontrar as cidades da solução
#include <bits/stdc++.h>    

using namespace std;

int n, m;
vector<int> adj[100010];
vector<int> rev_adj[100010];
int vis[100010];

//para o grafo de componentes fortemente ligados
int component [100010]; //a qual componente cada vertice pertence
vector<int> compVertex[100010]; // quais vertices tem no componente i
set<int> compAdj[100010]; // quais vertices tem no componente i
int compIndex = 0; //o indice do componente que estamos criando

stack <int> st; //essa eh a pilha q vai definir a ordem do dfs 2

//dfs 1 pra fazer a pilha boladona
void dfs1(int x){
    vis[x] = 1;
    for (int v: adj[x]){
        if(!vis[v]) dfs1(v);
    }
    st.push(x);
}

//dfs 2 pra separar as componentes
void dfs2(int x){
    component[x] = compIndex;
    //cout<<x<<" ";
    compVertex[compIndex].push_back(x);
    vis[x] = 1;
    for(int v: rev_adj[x]){
        if(!vis[v]) dfs2(v);
    }
}

//confesso que esse algoritmo tem um nome bem maneiro
void kosaraju(){
    for(int i=1; i<=n; i++)
        if(!vis[i]) dfs1(i);

    memset(vis, 0, sizeof(vis));  

    while(!st.empty()){
        if(!vis[st.top()]){
            //cout<<"\nComponente "<<compIndex<<" : ";
            dfs2(st.top());
            compIndex++;
        }
        st.pop();
    }
} 

int main(){
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    kosaraju();

    for(int i=1; i<=n; i++){
        for(int x: adj[i]){
            if(component[i] != component[x])
                compAdj[component[i]].insert(component[x]);
        }
        
    }

    int indResp = -2;
    for(int i=0; i<compIndex; i++){
        if(compAdj[i].size() == 0){
            if(indResp == -2) indResp = i;
            else indResp = -1;
        } 
    }

    if(indResp < 0) cout<<0;
    else {
        cout<<compVertex[indResp].size()<<endl;
        sort(compVertex[indResp].begin(), compVertex[indResp].end());
        for(int x: compVertex[indResp]) cout<<x<<" ";
    }
    cout<<"\n";

    return 0;
}