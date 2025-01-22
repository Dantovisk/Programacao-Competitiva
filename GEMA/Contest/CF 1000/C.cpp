#include <bits/stdc++.h>
#define MAXN 200010
#define ll long long int 

using namespace std;

vector<int> adj[MAXN];

int par[MAXN];
pair<int, int> grau[MAXN]; //grau, indice

void dfs(int u){
    for(auto v: adj[u]){
        if(v == par[u]) continue;
        grau[u].first++;

        par[v] = u;
        dfs(v);
    }
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);

    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        
        for(int i=0; i<=n; i++){
            par[i] = 0;
            grau[i] = {0, i};
            adj[i].clear();
        }

        for(int i=1; i<n; i++){
            int a, b;
            cin>>a>>b;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }


        if(n==2){
            cout<<0<<"\n";
            continue;
        }

        dfs(1);

        sort(grau+1, grau+n+1);
        int maxt = 0;
        
        int a = grau[n-2].first;
        int b = grau[n-2].second;
        int c = grau[n-1].first;
        int d = grau[n-1].second;

        int m1 = a + c + 1;
        if (par[b] == d || par[b] == 0) m1 --;
        if (par[d] == b || par[d] == 0) m1 --;

        maxt = max(maxt, m1);

        a = grau[n-2].first;
        b = grau[n-2].second;
        c = grau[n].first;
        d = grau[n].second;

        m1 = a + c + 1;
        if (par[b] == d || par[b] == 0) m1 --;
        if (par[d] == b || par[d] == 0) m1 --;

        maxt = max(maxt, m1);

        a = grau[n-1].first;
        b = grau[n-1].second;
        c = grau[n].first;
        d = grau[n].second;

        m1 = a + c + 1;
        if (par[b] == d || par[b] == 0) m1 --;
        if (par[d] == b || par[d] == 0) m1 --;

        maxt = max(maxt, m1);


        cout<<maxt<<"\n";

        
    }


    return 0;
}
