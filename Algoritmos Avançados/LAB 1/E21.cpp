#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e3+7;

//ALGORITMO DE KOSARAJU
int vis[MAX];
int comp[MAX]; // componente associado ao vertice
vector<int> vertOfComp[MAX]; // Membros
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
// Mantem o id do componente do vertice atual
void scc(int u, int id){
    comp[u] = id;
    vertOfComp[id].push_back(u);
    for(auto v: adjT[u]){
        if(!comp[v]) scc(v, id);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n>>m;

    // lê o grafo e a sua versão transposta
    for(int i = 0; i< m; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adjT[b].push_back(a);
    }

    // O grafo pode não ser conexo
    // processa os componentes isolados
    for(int i = 1; i<= n; i++){
        //verifica se o nó já foi visitado
        if(!vis[i]){
            dfs(i);
        }
    }

    int currComp = 0;
    //Esvazia a pilha de nós a serem visitados
    while(!st.empty()){
        int i = st.top();
        st.pop();
        //Verifica se o nó já é parte de algum componente
        if(!comp[i]) {
            scc(i, ++currComp);
        }
    }

    // Imprime os componentes
    // Crescentes pelo menor ID do grupo
    vector<int> visComp (n+1, 0);
    for(int i  = 1; i<= n; i++){
        if(!visComp[comp[i]]){
            visComp[comp[i]] = 1;

            //ordena os IDs do componente
            sort(vertOfComp[comp[i]].begin(), vertOfComp[comp[i]].end());

            cout<<"[";
            for(int j = 0; j< vertOfComp[comp[i]].size(); j++){
                cout<<vertOfComp[comp[i]][j];
                if(j < vertOfComp[comp[i]].size() - 1) cout<<",";
            }
            cout<<"]\n";
        }
    }

}