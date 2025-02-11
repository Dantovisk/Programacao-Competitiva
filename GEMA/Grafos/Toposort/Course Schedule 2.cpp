#include <bits/stdc++.h> //CSES
#define MAXN 100010
using namespace std;

//esse problema também é chamado de Topological Labelling
//ou Lexicographically Smallest Topological Ordering

vector<int> adjT[MAXN];
int kout[MAXN]; //grau de saida do vertice

//nesse exercicio precisamos priorizar tarefas de menor indice
priority_queue <int> pq;
vector<int> resp;

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adjT[b].push_back(a);
        kout[a]++;
    }

    //construiremos a resposta de tras pra frente
    for(int i=1; i<=n; i++){
        if(kout[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int u = pq.top();
        pq.pop();
        resp.push_back(u);

        for(auto v: adjT[u]){
            kout[v]--;
            if(kout[v] == 0) pq.push(v);
        }
    }

    reverse(resp.begin(), resp.end());
    for(auto x: resp) cout<<x<<" ";
    
    return 0;
}