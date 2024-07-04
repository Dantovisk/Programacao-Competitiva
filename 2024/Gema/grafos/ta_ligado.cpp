//exercicio simples sobre representacao de grafos, esse tipo de representacao
//se da pelo fato das entradas irem ate 10^5, e nao queremos estourar a memoria
#include <bits/stdc++.h>
using namespace std;

vector < set<int>> adj(100010);
set <int> resp;

int main(){
    int n, m;
    cin>>n>>m;

    int a, b, c;
    for(int i=0; i<m; i++){
        cin>>a>>b>>c;
        if(a==0){
            if(adj[b].find(c) != adj[b].end()) cout<<1<<endl;
            else cout<<0<<endl;
        } else{
            adj[b].insert(c);
            adj[c].insert(b);
        }   
    }
    return 0;
}