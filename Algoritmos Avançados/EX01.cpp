#include <bits/stdc++.h>

using namespace std;

void solve(int n){
    vector<vector<int>> adj(n+1);
    vector<bool> doente(n+1, false);

    for(int i =0; i<n; i++){
        int id, p, m;
        string taruim;

        cin>>id>>taruim>>p>>m;

        if(p != -1) adj[id].push_back(p);
        if(m != -1) adj[id].push_back(m);
        if(taruim == "sim")doente[id] = true;
    }
    
    queue<int> q;
    q.push(1);
    int res = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        bool doenca = false;
        for(int v: adj[u]){
            if(doente[v]) doenca = true;
            q.push(v);
        }
        if(doenca && doente[u]) {
            res++;
        }
        
    }

    cout<<res<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin>>q;

    while(q--){
        int n; cin>>n;
        solve(n);
    }

}