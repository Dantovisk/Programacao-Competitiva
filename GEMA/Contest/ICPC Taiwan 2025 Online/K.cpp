#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second

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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;

    int nodes = 2 + 2*n + 2*n*n; 
    int grande = 1e7 + 1;


    Dinic flow = Dinic(nodes);
    // 0 -> src
    // [1, n^2] -> cada nó
    // [n^2 + 1, n^2 + n] -> linhas
    // [n^2 + n + 1, n^2 + 2n] -> colunas
    // [n^2 + 2n + 1, 2n^2 + 2n] -> cada nó
    // 2n^2 + 2n + 1 -> sink

    int ids = 1;
    int safe = 0;

    rep(i, 0, n){
        rep(j, 0, n){
            int a; cin>>a;

            if(a) {
                safe ++;
                a--; 
                
                if(a > 0){              
                    //liga com o source
                    flow.addEdge(0, ids, a);
                }
            }
            else{
                //do target pro sink
                flow.addEdge(n*n + 2*n + ids, nodes-1, 1);
            }
            
            //liga com a linha e da linha pro target
            flow.addEdge(ids , n*n + i + 1, grande);
            flow.addEdge(n*n + i + 1 , n*n + 2*n + ids, grande);

            //liga com a coluna e da coluna pro target
            flow.addEdge(ids , n*n + n + j + 1, grande);
            flow.addEdge(n*n + n + j + 1 , n*n + 2*n + ids, grande);

            ids++;
        }
    }

    ll res = flow.calc(0, nodes-1);
    // cout<<"{res, safe} = "<<res<<", "<<safe<<"\n";

    // cout<<res.first<<" "<<res.second<<"\n";
    cout<<res + (n*n-res-safe)*2<<"\n";
}