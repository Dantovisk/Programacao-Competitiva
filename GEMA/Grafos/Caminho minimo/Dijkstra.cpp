//Codeforces alpha round 20 - C. Dijkstra?
#include <bits/stdc++.h>

using namespace std;

int parent[100010];
int vis[100010];
priority_queue<pair<long long int,int>, vector <pair<int, int>>,  greater<pair<int,int>>> fila; //peso, destino
vector<vector<pair<long long int,int>>> adj(100010); //adj.first -> peso da aresta e second-> destino
vector<long long int> pesos(100010, 1000000000000); // guarda o peso do vertice
int n, m;
bool achou = false;

void dijkstra(){
    fila.push({0,1});
    pesos[1] = 0;

    while(!fila.empty()){
        int ind = fila.top().second;
        fila.pop();

        if(vis[ind]) continue;
        vis[ind] = 1;

        if(ind == n){
            achou = true;
            return;
        }

        for(auto x: adj[ind]){
            int k = x.second;
            long long int w = x.first;

            if(pesos[ind] + w < pesos[k]){
                parent[k] = ind;
                pesos[k]= pesos[ind]+ w;
                fila.push({pesos[k], k});
            }
        }
        
    }
}

int main() {
    cin >> n >> m;

    int a, b, c;
    for (int i = 0; i < m; i++) {   //esse grafo eh nao direcionado
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));  
    }
    
    //neste exercicio consideraremos o caminho entre os vertices 1 e n
    dijkstra();


    if(achou){
        vector<int> resp;
        int r = n;
        while(r != 0){
            resp.push_back(r);
            r = parent[r];
        }
        reverse(resp.begin(), resp.end());
        for(int x: resp) cout<<x<<" ";

    }else cout<<-1;
    

    return 0;
}

