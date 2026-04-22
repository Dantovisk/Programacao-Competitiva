#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e3+7;

//ALGORITMO DE KOSARAJU
int vis[MAX];
int comp[MAX]; // componente associado ao vertice
int szComp[MAX]; // Tamanho do componente
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
    szComp[id] ++;
    for(auto v: adjT[u]){
        if(!comp[v]) scc(v, id);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin>>n>>m;
    while(n != 0){     
        //setup 
        for(int i = 0; i<= n; i++){
            adj[i].clear();
            adjT[i].clear();
            vis[i] = 0;
            comp[i] = 0;
            szComp[i] = 0;
        }

        // lê o grafo e a sua versão transposta
        for(int i = 0; i< m; i++){
            int a, b, c;
            cin>>a>>b>>c;

            adj[a].push_back(b);
            adjT[b].push_back(a);
            if(c == 2){
                adj[b].push_back(a);
                adjT[a].push_back(b);
            }
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

        if(currComp == 1){
            //Apenas um componente
            cout<<"confianca total\n";
        }else{
            //Imprime os tamanhos dos componentes
            // Os ids dos componentes devem ser de acordo
            // Com os menores ids dos vértices
            vector<bool> visComp (currComp+1, false);

            // Vai imprimindo os componentes de acordo com os 
            // vértices não vistos
            int currId = 1;
            for(int i = 1; i<= n; i++){
                if(!visComp[comp[i]]){
                    visComp[comp[i]] = true;
                    cout<<"["<<currId++<<","<<szComp[comp[i]]<<"]";
                }
            }
            cout<<"\n";
        }

        cin>>n>>m;
    }
}