#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> grafo; //lista de adjascencias
int peso[100010];

int dfs(int v){ //retorna o peso de cada vértice
    if(grafo[v].size()==0){
        return peso[v] = 1;
    }

    int contagem = 1;
    for(auto u: grafo[v]){
        contagem+= dfs(u);
    }
    return peso[v] = contagem;
}

bool balanceado(int v){ //cada camada terá um peso, e checa se todos os vértices tem o mesmo peso
    if(grafo[v].size()==0){
        return true;
    }
    int pesoreferencia = peso[grafo[v][0]];

    for(auto u: grafo[v]){
        if(pesoreferencia != peso[u] || !balanceado(u)){
            return false;  
        }
    }

    return true;
}


int main(){

    int n;
    cin>>n;

    grafo.resize(n+1);
    int a, b;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        grafo[b].push_back(a);
    }

    dfs(0);

    
    if(balanceado(0)){
        cout<<"bem";
    }else{
        cout<<"mal";
    }

    return 0;
}