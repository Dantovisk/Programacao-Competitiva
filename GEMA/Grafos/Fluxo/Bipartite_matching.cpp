#include <bits/stdc++.h> // LibChecker - Bipartite Matching
#define ll long long    
#define vi vector<int>
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

using namespace std;

// Solve com dinic kactl

struct Dinic {
	struct Edge {
		int to, rev; //destino, indice da aresta reversa
		ll c, oc; //capacidade residual, capacidade original
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int l, r, m;
    cin>>l>>r>>m;

    Dinic d = Dinic(l+r+2);
    
    // NESSA LIB APENAS PRECISA ADICIONAR A ARESTA EM 1 SENTIDO
    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        b += l + 1;
        a++;
        
        d.addEdge(a, b, 1);
    }

    for(int i=1; i<=l; i++){
        d.addEdge(0, i, 1);
    }
    for(int i=1; i<=r; i++){
        d.addEdge(i+l, l+r+1, 1);
    }

    cout<<d.calc(0, l+r+1)<<"\n";
    
    //percorrendo os vértices à esquerda
    for(int u = 1; u <= l; ++u) {
        //percorrendo as arestas
        for (auto &e : d.adj[u]) {
            //verifica se foram emparelhados com fluxo positivo
            // e.to é o vértice destido, e .flow() verifica o fluxo da aresta
            //Só arestas que liguem vértices da esquerda à direita
            if (e.to > l && e.to <= l+r && e.flow() > 0){
                cout<< u-1 <<" "<<e.to - l - 1<<"\n";
            }
        }
    }

    return 0;
}

