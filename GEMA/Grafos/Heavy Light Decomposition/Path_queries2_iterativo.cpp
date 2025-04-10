#include <bits/stdc++.h> // CSES - Path Queries 2
#define MAXN 200010       

using namespace std;

//segtree de maximo
int opmax (int a, int b) {
    return max(a, b);
}

// *Template da lib do gema*
// Example for segtree of sum:
// int sum(int a, int b) { return a + b; }
// segtree<int, 0, sum> seg;
template<typename T, T zero, T (*op)(T, T) >
struct segtree {
	vector<T> seg;
	int n;
	segtree(int n_): n(n_) {
		seg.assign(n_ + n_ + 5, zero);
	}

    //a query usa intervalo semi aberto [l, r)
	T query(int l, int r) {
		T ansl, ansr;
		ansl = ansr = zero;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l&1) ansl = op(ansl, seg[l++]);
			if(r&1) ansr = op(seg[--r], ansr);
		}
		return op(ansl, ansr);
	}

	void update(int p, T val) {
		for(seg[p += n] = val; p >>= 1;) {
			seg[p] = op(seg[2 * p], seg[2 * p + 1]);
		}
	}
};

int n, q;
int v[MAXN];
vector<int> adj[MAXN];
int heavy[MAXN], depth[MAXN], tam[MAXN], par[MAXN], head[MAXN];

//mapeamento da ordem de decomposição
int atual = 1;
int id[MAXN];

//criando uma segtree de maximo
segtree<int, 0, opmax> st(MAXN);

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

int path(int a, int b){
    int resp = 0;
    while(head[a] != head[b]){
        if(depth[head[b]] > depth[head[a]]) swap(a, b);

        resp = max(resp, st.query(id[head[a]], id[a]+1));
        a = par[head[a]];
    }
    if(depth[b] > depth[a]) swap(a, b);
    resp = max(resp, st.query(id[b], id[a]+1));
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
        st.update(id[i], v[i]);
    }
    
    for(int i =0; i<q; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a==1){
            st.update(id[b], c);
        }else{
            cout<<path(b, c)<<" ";
        }
    }

    return 0;
}