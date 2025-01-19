#include <bits/stdc++.h>    //Tree Distances - CSES

using namespace std;

vector <int> adj[200010];
long long int dist[200010];
int subSize[200010];
int n;

void dfs(int v, int parent){
    subSize[v]=1;
    dist[v]=0;

    for(int x: adj[v]){
        if(x !=  parent){
            dfs(x, v);

            dist[v] += dist[x] + subSize[x];
            subSize[v] += subSize[x];
        }
    }
    
}

void dfs2(int v, int parent){
    for(int x: adj[v]){
        if(x !=  parent){
            dist[x] = dist[v]+(n - 2 * subSize[x]);
            dfs2(x, v);
        }
    }
    
}

int main() {
    cin >> n;

    int a, b;
    for (int i = 0; i < n-1; i++) {   //esse grafo eh direcionado
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0);

    dfs2(1, 0);
    
    for(int i=1; i<=n; i++){
        cout<<dist[i]<<" ";
    }

    return 0;
}

