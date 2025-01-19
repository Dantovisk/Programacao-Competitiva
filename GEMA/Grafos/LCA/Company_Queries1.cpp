#include <bits/stdc++.h> //questão ainda não é sobre LCA diretamente, mas sobre binary lifting
#define MAXN 200010

using namespace std;

vector <int> adj[MAXN];
int ances [MAXN][20];

void dfs(int u, int p){
    ances[u][0] = p;

    for(auto v: adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q; 
    cin>>n>>q;

    for(int i=2; i<=n; i++){
        int a;
        cin>>a;
        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    memset(ances, -1, sizeof(ances));

    dfs(1, -1);

    //pré processamento
    for(int i=1; i<20; i++){
        for(int j=2; j<=n; j++){
            if(ances[j][i-1] == -1) continue;
            ances[j][i] = ances[ances[j][i-1]][i-1];
        }
    }

    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        for(int k = 18; k>=0; k--){
            if(b & (1<<k)) {
                if(a != -1) a = ances[a][k];
            }
        }
        cout<<a<<"\n";
    }

    return 0;
}