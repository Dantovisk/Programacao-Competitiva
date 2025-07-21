#include <bits/stdc++.h>
#define MAXN 200010
#define int long long
#define pii pair <int,int>
using namespace std;

const int inf = 1e6+1;

vector<int> adj[MAXN];
int n;
int resp[MAXN];

// Primeira e segunda maior profundidade da subarvore enraizada em i, 
// distancia maxima fora da arvore
int prof1[MAXN], prof2[MAXN], out[MAXN]; 

void dfs1(int u, int p){
    for(auto v: adj[u]){
        if(v == p) continue;
        dfs1(v, u);

        //achou uma nova primeira profundidade maior
        if(prof1[v] + 1 > prof1[u]){
            prof2[u] = prof1[u];
            prof1[u] = prof1[v] + 1;
        }
        //achou uma nova segunda profundidade maior
        else if(prof1[v] + 1 > prof2[u])
            prof2[u] = prof1[v] + 1; 
    }
}

void dfs2(int u = 1, int p = 0, int dist = 0){
    resp[u] = max(prof1[u], dist);
    for(auto v: adj[u]){
        if(v == p) continue;

        //o caminho mais profundo ainda está na subarvore de v
        if(prof1[u] == prof1[v] + 1){
            dfs2(v, u, max(dist, prof2[u]) + 1);
        }
        // estava em alguma subárvore irmã, usa o vértice u como
        // ponte para a resposta
        else{
            dfs2(v, u, resp[u] + 1);
        }
        
    }
}

int32_t main(){
    cin>>n;

    if(n==1) {
        cout<<"0\n";
        return 0;
    }
    for(int i = 1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2();
    
    for(int i =1; i<=n; i++) cout<<resp[i]<<" ";
    return 0;
}