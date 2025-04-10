#include <bits/stdc++.h> // QTREE3 Spoj
#define MAXN 100010

using namespace std;

int n, q;
vector<int> adj[MAXN];
int depth[MAXN], par[MAXN], sz[MAXN], heavy[MAXN], head[MAXN];

int atual = 1, id[MAXN]; //id[i] = posicao do no na segtree
int vert[MAXN]; //mapeia o indice da segtree para o indice do nó
//segtree de soma, começa tudo em 0
int tree[4*MAXN];


void dfs(int u, int p){
    par[u] = p;
    sz[u] = 1;
    heavy[u] = -1;

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
    vert[atual] = u;
    id[u] = atual++;
    head[u] = h;

    if(heavy[u] != -1){
        hld(heavy[u], h);
    }

    for(auto v: adj[u]){
        if(par[u] == v || v == heavy[u]) continue;
        hld(v, v);
    }
}

// a query retorna a poisição do primeiro 1 de l até r
int query(int no, int i, int j, int l, int r){
    if(i>r || j < l || tree[no] == 0) return -1;
    if(i == j) return i; //achou 

    int mid = (i+j)/2;
    int esq = query(2*no, i, mid, l, r);
    if (esq != -1) return esq;
    return query(2*no+1, mid+1, j, l, r);
}

//vou passando em todos os segmentos até achar o
int path(int a){
    //cout<<"query: "<<a<<endl;
    int resp = -1;

    while(a > 0){
        resp = query(1, 1, n, id[head[a]], id[a]);
        //cout<<head[a]<<" -> "<< a<<" = "<< resp<<"\n";
        if(resp != -1){
            //cout<< "retornando "<<vert[resp]<<"\n";
            return vert[resp];
        }
        //cout<< a <<" virou "<< par[head[a]]<<"\n";
        a = par[head[a]];
    }

    return -1;
}

void update(int no, int l, int r, int i){
    if(l>i || r<i) return;
    if(l==r) {
        //inverte a cor do nó
        tree[no] = !tree[no];
        return;
    }
 
    int mid = (l+r)/2;
    update(no*2, l, mid, i);
    update(no*2+1, mid+1, r, i);
 
    tree[no] = (tree[2*no] + tree[2*no+1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>q;

    for(int i =1; i<n; i++){
        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    hld(1, 1);

    for(int i =0; i<q; i++){
        int a, b; cin>>a>>b;
        if(a==0){
            update(1, 1, n, id[b]);
        }else{
            cout<<path(b)<<"\n";
        }
    }
   
    return 0;
}