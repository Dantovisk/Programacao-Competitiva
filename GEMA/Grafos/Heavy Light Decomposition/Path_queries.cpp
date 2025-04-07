#include <bits/stdc++.h> //a ideia ta certa
#define MAXN 200010       //falta fazer iterativo pra otimizar

using namespace std;

int n, q;
int v[MAXN];
vector<int> adj[MAXN];
int heavy[MAXN], depth[MAXN], tam[MAXN], par[MAXN], head[MAXN];

//mapeamento da ordem de decomposição
int atual = 1;
int id[MAXN];

//segtree de maximo
int segval[MAXN], tree[4*MAXN];
/*
queremos encontrar os filhos pesados, a profundidade,
o pai, e o tamanho da subarvore de cada nó
*/
void dfs(int u, int p){
    par[u] = p;
    tam[u] = 1;
    
    int mxsz = 0;
    for (auto v: adj[u]){
        if(v == p) continue;

        depth[v] = depth[u] + 1;
        dfs(v, u);
        tam[u] += tam[v];

        if(tam[v] > mxsz){
            mxsz = tam[v];
            heavy[u] = v;
        }   
    }
}

//nó atual, cabeça da cadeia
void decompose(int u, int h){
    head[u] = h;
    id[u] = atual++;

    if(heavy[u] != -1) decompose(heavy[u], h);

    for (auto v : adj[u]){
        if(v == heavy[u] || v== par[u]) continue;
        //começa outra cadeia em v e que a cabeça é v
        decompose(v, v);
    }
}

void build(int no, int l, int r){
    if(l==r){
        tree[no] = segval[l];
        return;
    }

    int mid = (l+r)/2;
    build(2*no, l, mid);
    build(2*no+1, mid + 1, r);
    tree[no] = max(tree[2*no], tree[2*no+1]);
}

void update(int no, int l, int r, int i, int val){
    if(l>i || r<i) return;
    if(l==r) {
        tree[no] = val;
        return;
    }

    int mid = (l+r)/2;
    update(no*2, l, mid, i, val);
    update(no*2+1, mid+1, r, i, val);

    tree[no] = max(tree[2*no], tree[2*no+1]);
}

int query(int no, int i, int j, int l, int r){
    if(i>r || j<l) return 0;
    if(i>= l && j<=r) return tree[no];

    int mid = (i+j)/2;
    return max(query(2*no, i, mid, l, r), 
        query(2*no+1, mid+1, j, l, r));
}

int path(int a, int b){
    int resp = 0;
    while(head[a] != head[b]){
        if(depth[head[b]] > depth[head[a]]) swap(a, b);

        resp = max(resp, query(1, 1, n, id[head[a]], id[a]));
        a = par[head[a]];
    }
    if(depth[b] > depth[a]) swap(a, b);
    resp = max(resp, query(1, 1, n, id[b], id[a]));
    return resp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(heavy, -1, sizeof(heavy));
    cin>>n>>q;

    for(int i =1; i<=n; i++){
        cin>>v[i];
    }
    for(int i =1; i<n; i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    decompose(1, 1);

    for(int i =1; i<=n; i++){
        segval[id[i]] = v[i];
    }
    build(1, 1, n);
    
    for(int i =0; i<q; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==1){
            update(1, 1, n, id[b], c);
        }else{
            cout<<path(b, c)<<" ";
        }
    }


    return 0;
}