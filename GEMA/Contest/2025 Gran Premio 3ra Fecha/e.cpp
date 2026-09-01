#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
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
		rep(L,0,1) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c)
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

int cap[1010][18];
vector<pii> edgs[1010];
const int inf = 1e9+7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, k, m;
    cin>>n>>k>>m;

    rep(i, 1, n+1){
        rep(j, 1, k+1){
            cin>>cap[i][j];
        }
    }

    rep(i, 0, m){
        int lv, u, v;
        cin>>lv>>u>>v;
        edgs[lv+1].push_back({u, v});
    }

    Dinic fl(2*n*k + 2);
    //saindo do source
    for(int i = 1; i<= k; i++){
        fl.addEdge(0, i, inf);
    }
    for(int lv = 1; lv <= n; lv++){
        //criando capacidade dos vertices
        for(int j = 1; j<= k; j++){
            fl.addEdge(j + (k*(lv-1)*2), j + (k*(lv-1)*2) + k, cap[lv][j]);
        }
        //adicionando fluxo pro andar anterior
        for(auto[u, v] : edgs[lv]){
            fl.addEdge((k*(lv-1)*2) + u - k, (k*(lv-1)*2) + v, inf);
        }
    }
    ll res = 0;
    vector<ll> resp;
    for(int lv = n; lv >= 1; lv--){
        //chegando no end
        for(int i = 2*lv*k-k+1; i<= 2*lv*k; i++){
            fl.addEdge(i, 2*n*k+1, inf);
        }
        res += fl.calc(0, 2*n*k+1);
        resp.push_back(res);
    }
    reverse(all(resp));
    for(auto x: resp){
        cout<<x<<" ";
    }
    cout<<"\n";
}