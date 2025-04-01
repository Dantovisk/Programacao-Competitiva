#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;

vector<int> adj [MAXN];
int v[MAXN]; //valor de cada no

//Variaveis para HLD
int par[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int currPos = 0;

//Segtree de soma
int tree[4*MAXN];

void build(int no, int l, int r){
    if(l==r) {
        tree[no] = v[pos[l]];
        return;
    }
    int mid = (l+r)/2;
    build(2*no, l, mid);
    build(2*no+1, mid+1, r);
    tree[no] = tree[2*no] + tree[2*no+1];
}

int query(int no, int i, int j, int l, int r){
    if(j<l || i > r) return 0;
    if(i>= l && j<= r) return tree[no];

    int mid = (i+j)/2;
    return query(2*no, i, mid, l, r) + query(2*no+1, mid+1, j, l, r);
}

//calcula o tamanho das subarvores e identifica filhos pesados
int dfs(int u){
    int sz = 1;
    int maxSz = 0; //tamanho do filho mais pesado
    heavy[u] = -1; //inicialmente, nao tem filho pesado

    for(auto v : adj[u]){
        if(v == par[u]) continue;
        par[v] = u;
        depth[v] = depth[u]+1;
        int k = dfs(v); //tamanho do filho
        sz += k;
        if(k > maxSz){
            maxSz = k;
            heavy[u] = v; //v virou o filho pesado de u
        }
    }
    return sz;
}

// DFS para decompor a árvore em caminhos pesados
void decompose(int u, int h){
    head[u] = h; //cabeça do caminho pesado
    pos[u] = currPos++; //posição do nó na segtree

    //se houver filho pesado, continua no mesmo caminho
    if(heavy[u] != -1) decompose(heavy[u], h);

    //filhos leves começam novos caminhos
    for(int v : adj[u]){
        if(v != par[u] && v != heavy[u]){
            decompose(v, v);
        }
    }
}

int queryPath(int u, int v){
    int res = 0;
    while(head[u] != head[v]){ //enquanto estão em caminhos diferentes
        if(depth[head[u]] < depth [head[v]]){
            swap(u, v); //u deve ser o caminho mais profundo
        }
        // Soma do caminho pesado de u até a cabeça
        res += query(1, 1, currPos-1, pos[head[u]], pos[u]);
        u = par[head[u]];//subindo para o caminho acima
    }
    //agora u e v estão no mesmo caminho pesado
    if(depth[u] < depth[v]) swap(u, v);
    res += query(1, 1, currPos-1, pos[v], pos[u]); // Soma do caminho final
    return res;
}

int main(){
    int n, q; // Número de nós
    cin >> n >> q;

    // Ler os valores dos nós
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    // Ler as arestas da árvore
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Pré-processamento
    par[1] = -1; // Raiz
    depth[1] = 0;
    dfs(1); // Calcular tamanhos e filhos pesados
    decompose(1, 1); // Decompor a árvore
    build(1, 1, currPos-1); // Construir a Segment Tree

    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << "Soma entre " << u << " e " << v << ": " << queryPath(u, v) << endl;
    }


    return 0;
}