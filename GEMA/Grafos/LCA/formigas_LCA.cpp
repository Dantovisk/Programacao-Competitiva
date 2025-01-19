#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<pair<int,int>> adj[100010];
int ancestral[100010][25]; //indice, peso da aresta
int nivel[100010];
int soma[100010];

void dfs(int v, int p){
    for(auto x: adj[v]){
        int q = x.first, w = x.second;
        if(q == p) continue;
        nivel[q] = nivel[v] +1;
        soma[q] = soma[v] + w;
        ancestral[q][0] = v;
        dfs(q, v);
    }
}

int lca(int a, int b){
    if(nivel[b]>nivel[a]) swap(a,b);

    for (int i = 20; i>=0; i--){
        if(nivel[a] - (1<<i) >= nivel[b]) a = ancestral[a][i];
    }

    if(a==b) return a;

    for (int i = 20; i>=0; i--){
        if(ancestral[a][i] != -1 && ancestral[b][i] != -1  && ancestral[a][i] != ancestral[b][i]){
            a = ancestral[a][i];
            b = ancestral[b][i];
        }

    }

    return ancestral[a][0];
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; 
    cin>>n;

    while(n!=0){
        memset(ancestral, -1, sizeof(ancestral));
        memset(nivel, 0, sizeof(nivel));
        memset(soma, 0, sizeof(soma));

        for(int i=1; i<n; i++){
            int a, b;
            cin>>a>>b;
            adj[i].push_back({a,b});
            adj[a].push_back({i,b});
        }

        dfs(0, -1);

        for(int i=1; i<21; i++){
            for(int j=1; j<n; j++){
                if(ancestral[j][i-1] == -1) continue;
                ancestral[j][i] = ancestral[ancestral[j][i-1]][i-1];
            }
        }

        cin>>q;

        for(int i=0; i<q; i++){
            int a, b;
            cin>>a>>b;

            int c = lca(a,b);
            cout<< soma[a]+soma[b] - (2*soma[c])<<" ";
        }


        for(int i=0; i<n; i++) adj[i].clear();
        cin>>n;
        cout<<endl;
    }

    return 0;
}