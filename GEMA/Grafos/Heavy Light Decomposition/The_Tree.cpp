#include <bits/stdc++.h> // G. The Tree - Codeforces round 502
#define MAXN 200010      //INCOMPLETO - Ideia é complicadinha, falta implementar

using namespace std;
const int inf = 1e9+7;

int n, q;
vector<int> adj[MAXN];

//para o hld
int heavy[MAXN], depth[MAXN], par[MAXN], sz[MAXN], head[MAXN];

int id[MAXN], atual = 1;
int maxid[MAXN]; //retorna o maior id da subarvore de um no
//tree de max
int v[MAXN];
//tree[no] é quantidade de propagações do preto: -1 para branco, 0 se apenas o nó virou preto, 1 se propagou 1 vez...
int tree[4*MAXN], lazy[4*MAXN];

void dfs(int u, int p){
    heavy[u] = -1;
    par[u] = p;
    sz[u] = 1;

    int mx = 0;
    for(auto v: adj[u]){
        if(p == v) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        sz[u] += sz[v];

        if(sz[v] > mx){
            mx = sz[v];
            heavy[u] = v;
        }
    }
}

void hld(int u, int h){
    head[u] = h;
    id[u] = atual++;
    maxid[u] = id[u];

    if(heavy[u] != -1){
        hld(heavy[u], h);
        maxid[u] = maxid[heavy[u]];
    }

    for(auto v: adj[u]){
        if(heavy[u] == v || par[u] == v) continue;

        hld(v, v);
        maxid[u] = maxid[v];
    }
}

void unlazy(int no, int l, int r){
    



    tree[no] += lazy[no];

    if(l<r){
        lazy[2*no] += lazy[no];
        lazy[2*no+1] += lazy[no];
    }
    lazy[no] = 0;
}

//pinta os filhos de preto
void op1(int no, int i, int j, int id){
    unlazy(no, i, j);
    if(i>id || j<id) return;
    if(i ==j){
        
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    op1(2*no, i, mid, id);
    op1(2*no+1, i, mid, id);
}

//marca tudo como branco
void op2(int no, int i, int j, int l, int r){
    unlazy(no, i, j);
    if(i>r || j<l) return;
    if(i >= l && j<= r){
        lazy[no] = 1;
        unlazy(no, i, j);
        return;
    }

    int mid = (i+j)/2;

    op2(no*2, i, mid, l, r);
    op2(no*2 + 1, mid+1, j, l, r);
}


int query(int no, int i, int j, int l, int r){
    unlazy(no, i, j);
    if(i>r || j<l) return -inf;
    if(i >= l && j<= r)
        return tree[no];

    int mid = (i+j)/2;

    return max (query(no*2, i, mid, l, r), 
        query(no*2 + 1, mid+1, j, l, r));
    
}

int path(int a, int b){
    int res = -inf;

    while(head[a] != head[b]){
        if(depth[head[a]] < depth[head[b]]) swap(a,b);

        res = max(res, query(1, 1, n, id[head[a]], id[a]));
        a = par[head[a]];
    }

    if(depth[a] < depth[b]){
        swap(a, b);
    }
    res = max(res, query(1, 1, n, id[b], id[a]));

    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>q;

    for(int i =2; i<=n; i++){
        int a;
        cin>>a;

        adj[i].push_back(a);
        adj[a].push_back(i);
    }

    dfs(1, 0);
    hld(1, 1);

    for(int i =0; i<q; i++){
        int a, b; cin>>a>>b;
        if(a == 1){

        } else if(a==2){
            
        } else{
            
        }
    }
   
    return 0;
}