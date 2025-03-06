// O objetivo é encontrar o caminho com o menor tempo
// Que não ultrapasse um dado custo s
// Dijkstra com vertices auxiliares
#include <bits/stdc++.h>
#define tiii tuple<int, int, int> //tempo, destino, custo

using namespace std;
int n, m, s;

vector<tiii> adj[10010];

//peso, destino, custo ate o instante
priority_queue<tiii, vector <tiii>,  greater<tiii>> pq; 

// guarda o peso do vertice alcançavel para cada dinheiro
vector<vector<int>> pesos(10010, vector<int>(210, 100000000)); 

int st, ed;

int dijkstra(){
    for(int i=0; i<=n; i++) pesos[st][i] = 0;
    
    pq.push({0, st, 0});

    while(!pq.empty()){
        int v = get<1>(pq.top());
        int c = get<2>(pq.top());
        pq.pop();

        if(v == ed) return pesos[v][c];

        for(auto x: adj[v]){
            int dest = get<1>(x);
            int time = get<0>(x);
            int cost = get<2>(x);

            if(c + cost <= s && pesos[v][c] + time < pesos[dest][c+cost]){
                pesos[dest][c+cost] = pesos[v][c] + time;
                pq.push({pesos[dest][c+cost], dest, c+cost});
            }
        }
    }
    
    return -1;
}

int main(){
    cin>>s>>n>>m;

    for(int i=0; i<m; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        adj[a].push_back({c, b, d});
        adj[b].push_back({c, a, d});
    }

    cin>>st>>ed;

    cout<<dijkstra();

    return 0;
}