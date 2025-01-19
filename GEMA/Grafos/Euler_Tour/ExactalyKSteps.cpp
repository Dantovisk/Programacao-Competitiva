#include <bits/stdc++.h>
#define MAXN 200010
#define pii pair<int,int>

using namespace std;

vector <int> adj[MAXN];
vector <int> vqueries[MAXN]; //numero da pergunta, vertice u, distancia k
vector <int> vis;

map <pii, int> resp;

vector <pii> queries;

pair<int, int> dfs1(int u, int p, int d) {
    pair<int, int> res = {d, u}; // profundidade, vértice
    for (int v : adj[u]) {
        if (v != p) {
            res = max(res, dfs1(v, u, d + 1));
        }
    }
    return res;
}

void dfs2(int u, int p){
    vis.push_back(u);

    for (int k: vqueries[u]){
        if(vis.size()-1 < k) continue;
        resp[{u, k}] = vis[vis.size() - k - 1];
    }

    for(int x:adj[u]){
        if(x!=p) dfs2(x, u);
    }

    vis.pop_back();
}

int main(){
    int n; cin>>n;

    for(int i=1; i<n; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    //encontrando as extremidades
    int v1 = dfs1(1, -1, 0).second;
    int v2 = dfs1(v1, -1, 0).second;
    
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        queries.push_back({a,b});
        vqueries[a].push_back(b);
    }

    dfs2(v1, 0);
    dfs2(v2, 0);

    for(auto x: queries){
        int a = x.first;
        int b = x.second;

        if(resp.find({a,b}) == resp.end()){
            cout<<-1<<"\n";
        }
        else{
            cout<<resp[{a,b}]<<"\n";
        }
    }

    return 0;
}