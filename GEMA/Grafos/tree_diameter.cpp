#include <bits/stdc++.h>    //Tree Diameter - CSES

using namespace std;

vector <int> adj[200010];
int dist[200010];
int n, maxDist=0, bestStart=0;

void dfs(int v, int parent){
    for(int x: adj[v]){
        if(x !=  parent){
            dist[x] = dist[v]+1;
            if(dist[x]>maxDist){
                maxDist = dist[x];
                bestStart = x;
            }
            dfs(x, v);
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
    memset(dist, 0, sizeof(dist));
    dfs(bestStart, 0);

    cout<<maxDist;

    return 0;
}

