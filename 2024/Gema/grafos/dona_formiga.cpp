#include <bits/stdc++.h>    //representacao do grafico esta feita, falta implementar a logica de dfs
using namespace std;

vector <vector<int>> adj(1010);
queue <int> q;
int pesos[1010];

int main(){
    int n, t, p;
    cin>>n>>t>>p;

    for(int i=1; i<=n; i++){
        cin>>pesos[i];
    }

    int a, b;
    for(int i=0; i<t; i++){
        cin>>a>>b;
        if(pesos[a]>pesos[b]){
            adj[a].push_back(b);
        } else adj[b].push_back(a);
    }


    cout<<cont;
    return 0;
}