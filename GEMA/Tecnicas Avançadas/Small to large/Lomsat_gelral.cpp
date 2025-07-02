#include <bits/stdc++.h> // Codeforces Educational Round 2
#define int long long

#define MAXN 100010      // Lomsat gelral
using namespace std;

vector<int> adj[MAXN];
map <int, int> colors[MAXN];
int cor[MAXN];
int quant[MAXN]; //quantidade de replicas de uma cor dominante no vertice
int resp[MAXN];  

void calc(int u, int p){
    for(auto v: adj[u]){
        if(v == p) continue;
        calc(v, u);

        if(colors[u].size() < colors[v].size()){
            swap(colors[u], colors[v]);
            swap(quant[u], quant[v]);
            resp[u] = resp[v];
        }

        for(auto x : colors[v]) {
            int key = x.first;
            int ct = x.second;
            colors[u][key] += ct;

            if(colors[u][key] > quant[u]){
                quant[u] = colors[u][key];
                resp[u] = key;
            }
            else if(colors[u][key] == quant[u]){
                resp[u] += key;
            }
        }   
    }

    colors[u][cor[u]]++;
    
    if(colors[u][cor[u]] > quant[u]){
        quant[u] = colors[u][cor[u]];
        resp[u] = cor[u];
    }
    else if(colors[u][cor[u]] == quant[u]){
        resp[u] += cor[u];
    }
}


int32_t main(){
    int n; cin>>n;

    for(int i =1; i<=n; i++){
        cin>> cor[i];
    }

    for(int i =2; i<=n; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    calc(1, 0);
    for(int i =1; i<=n; i++){
        cout<<resp[i]<<" ";
    }

    return 0;
}