#include <bits/stdc++.h> //INCOMPLETO, PROBLEMA CHATO DE TÃO LONGO
#define MAXN 200010
using namespace std;
#define tii tuple<int,int, int>

map<int,int> adj[MAXN]; // {destino, custo}

int cost[MAXN];// custo de voltar de i até 1

// seg de soma que representa o custo de descer da raiz 1
// até o vérice N
int tree[4*MAXN]; 
int lazy[4*MAXN]; // soma

int tin[MAXN], tout[MAXN];
int prof[MAXN], par[MAXN][20]; //profundidade e ancestral

void unlazy(int no, int i, int j){
    if(lazy[no] == 0) return;

    tree[no] += lazy[no] * (j-i+1);

    if(i < j){
        lazy[2*no] += lazy[no];
        lazy[2*no+1] += lazy[no];
    }
    lazy[no] = 0;
}

void update(int no, int i, int j, int l, int r, int v){
    unlazy(no, i, j);
    if(i > r || j < l) return;
    if(i >= l && j <= r){
        lazy[no] += v;
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/ 2;
    update(2*no, i, mid, l, r, v); update(2*no+1, mid+1, j, l, r, v);
}

int query(int no, int i, int j, int id){
    if(i > id || j < id) return 0;
    if(i == j) return tree[no];

    int mid = (i+j)/ 2;
    return query(2*no, i, mid, id) + query(2*no+1, mid+1, j, id);
}

int tempo = 0;
void dfs(int u){
    tin[u] = ++tempo;

    for(auto [v, w] : adj[u]){
        par[v][0] = u;
        prof[v] = prof[u] + 1;
        dfs(v);
    }
    tout[u] = tempo;
}

int main(){
    int n, q;
    cin>>n>>q;

    memset(par, -1, sizeof(par));

    vector<tii> edges;

    for(int i=1; i<n; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj[a][b] = w;
        edges.push_back({a, b, w});
    }

    dfs(1);

    for(int u=1; u<n; u++){
        int p = par[u][0];

        update(1, 1, n, tin[u], tout[u], adj[p][u]);
    }

    for(int i=1; i<n; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj[a][b] = w;
    }

    for(int j = 1; j < 20; j++){
        for(int i = 1; i<=n; i++){
            if(par[i][j-1] == -1) continue; 
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }

    for(int i =0; i<q; i++){
        int t, a, b;
        cin>>t>>a>>b;
        if(t==1){ //update
            auto [u, v, w] = edges[a-1];
            int diff = w-adj[u][v];
            adj[u][v] = w;
            if(v != 1) update(1, 1, n, tin[v], tout[v], diff);

        }else{ //query
            bool tipo1 = false;
            int k = b;
            //b ta abaixo de a, vamo subir pra ver se ele ta na mesma subarvore
            while(prof[k] > prof[a]){
                for(int u = 19; u>= 0; u--){
                    if(prof[k] - (1<<u) >= prof[a]){
                        k = par[k][u];
                    }
                }
            }
            //tem que subir de a pra 1, e depois ir de 1 pra b
            if(k != a){
                int res = adj[a][1];

            }
            //pode ir direto de a pra b
            else{

            }
        }
    }




    return 0;
}