#include <bits/stdc++.h>

using namespace std;

int state[60][2];

int game(int u, int curr, vector<vector<int>>& adj){
    if(state[u][curr] != -1) return state[u][curr];

    int venc = 1-curr;
    
    for(auto v: adj[u]){
        if(game(v, 1-curr, adj) == curr) venc = curr;
    }  

    return state[u][curr] = venc;
}

void solve(){
    int n, m, s;
    cin>>n>>m>>s;

    memset(state, -1, sizeof(state));

    vector<vector<int>> v(n+1);

    for(int i =0; i<m; i++){
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
    }

    cout<<(game(s, 0, v) == 0? "Ash\n" : "Noir\n");
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;

    while(t--) solve();
}