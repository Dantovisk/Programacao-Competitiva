#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100010];
int cor[100010];
bool resp = true;

bool bfs(int k){
    queue <int> q;
    q.push(k);
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(auto v: adj[u]){
            if(cor[u] == cor[v]) resp = false;
            if(cor[v]) continue;

            cor[v] = (cor[u] == 1? 2 : 1);
            q.push(v);
        }
    }
    
    return true;
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i =0; i<m; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1; i<=n; i++){
        if(!cor[i]){
            cor[i] = 1;
            bfs(i);
        }
    }

    if(resp)
        for(int i=1; i<=n; i++) cout<<cor[i]<<" ";
    else cout<<"IMPOSSIBLE\n";
}