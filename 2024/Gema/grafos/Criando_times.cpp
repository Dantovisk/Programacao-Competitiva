// CSES - Building Teams
// O objetivo do exercicio é separar N pessoas em 2 times, tal que
// dois integrantes com amizade nao podem estar no mesmo time.
// Será resolvido verificando se o grafo é bipartido

#include <bits/stdc++.h>  
using namespace std;

vector <vector<int>> adj(100010);
int times[100010];
queue <int> q;

bool ehBipartido(int s){
    q.push(s);
    times[s] =1;

    while(!q.empty()){
        int a = q.front();
        q.pop();

        for(int x: adj[a]){
            if(times[x] == 0)
            {
                times[x] = 3 - times[a];
                q.push(x);
            }
            else if(times[x]== times[a])
            {
                return false;
            }
        }
    }
    return true;
}

int main() {

    int n, m;
    cin>>n>>m;

    int a, b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    

    for(int i=1; i<=n; i++){
        if(times[i]==0){
            if(!ehBipartido(i)){
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
        
    }
    
    for(int i=1; i<=n; i++) cout<<times[i]<<" ";

    return 0;
}