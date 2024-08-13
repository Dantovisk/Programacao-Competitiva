#include <bits/stdc++.h>

using namespace std;
int n, m;
vector <int> adj[110], resp;
int cont[110];
queue <int> q;

int main() {
    cin>>n>>m;
    while(n!=0 && m!=0){
        resp.clear();
        for(int i=0; i<=n; i++) adj[i].clear();
        memset(cont, 0, sizeof(cont));

        for(int i=0; i<m; i++){
            int a, b;
            cin>>a>>b;
            adj[a].push_back(b);
            cont[b]++;
        }

        //realização do toposort;

        for(int i=1; i<=n; i++){
            if(cont[i]==0) q.push(i);
        }

        while(!q.empty()){
            int v = q.front();
            q.pop();
            resp.push_back(v);
            for(int x: adj[v]){
                cont[x]--;
                if(cont[x]==0) q.push(x);
            }
        }
        for(int x: resp){
            cout<<x<<" ";
        }
        if(n!= 0 && m!= 0) cout<<"\n";
        cin>>n>>m;
    }

    return 0;
}

