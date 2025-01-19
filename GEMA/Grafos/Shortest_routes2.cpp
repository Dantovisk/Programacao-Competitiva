#include <bits/stdc++.h>    //Shortest routes II - CSES
//exercicio simples que pode ser resolvido com floyd warshall

using namespace std;
int n, m, q;

int adj[510][510]; //matriz de adjascencia facilita floyd warshall
long long dist[510][510];
const long long inf = 10e17 + 123;


int main() {
    cin >> n >> m>> q;

    int a, b, c;
    for (int i = 0; i < m; i++) {   //esse grafo eh nao direcionado
        cin >> a >> b >> c;
        if(!adj[a][b]){
            adj[a][b] = c;
            adj[b][a] = c;
        }
        else{
            adj[a][b] = min(adj[a][b], c);
            adj[b][a] = min(adj[b][a], c);
        }
        
    }

    //vamos incializar a matrizz dist
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= n; j++) { 
            if(i==j) dist[i][j] = 0;
            else if(adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = inf;
        }
    }

    for (int k = 1; k <= n; k++) { //intermediario
        for (int i = 1; i <= n; i++) { // incio
            for (int j = 1; j <= n; j++) { // destino
                dist[i][j] = min(dist[i][j],
                    dist[i][k]+dist[k][j]);
            }   
        }
    }
    
    for (int j = 0; j < q; j++) { 
        int a, b;
        cin>>a>>b;
        cout<<(dist[a][b]!=inf?dist[a][b]:-1)<<"\n";
    }
}

