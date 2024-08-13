#include <bits/stdc++.h>

using namespace std;
vector <vector<int>> adj(2510);
stack <int> rota;   //para encontrar o tamanho do ciclo

int menorAdj = 50000;

int main(){
    vector <bool> visitados (2510, false);
    int n, m;
    cin>>n>>m;
    int a, b;
    for(int i =0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    return 0;
}

