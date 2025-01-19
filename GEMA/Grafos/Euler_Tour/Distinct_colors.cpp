#include <bits/stdc++.h>

using namespace std;

vector <int> adj[200010];
int cor [200010];
int resp [200010];
int cont = 0;
map<int, int> mp;

void dfs(int u, int p){
    mp[cor[u]]++;
    if(mp[cor[u]] == 1) cont++;

    
    for(int v: adj[u]){
        if(p==v) continue;

        dfs(v, u);
    }
    
    
}

int main(){
    int n;
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>cor[i];
    }

    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);

    for(int i=1; i<=n; i++){
        cout<<resp[i]<<" ";
    }

    return 0;
}