#include <bits/stdc++.h> //CSES - Distinct Colors
#define MAXN 200010
using namespace std;

vector<int> adj[MAXN];
set <int> colors[MAXN];
int cor[MAXN];
int resp[MAXN];

void calc(int u, int p){
    colors[u].insert(cor[u]);
    for(auto v: adj[u]){
        if(v == p) continue;
        calc(v, u);

        if(colors[u].size() < colors[v].size()) swap(colors[u], colors[v]);
        for(auto x : colors[v]) colors[u].insert(x);
    }
    resp[u] = colors[u].size();
}

int main(){
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