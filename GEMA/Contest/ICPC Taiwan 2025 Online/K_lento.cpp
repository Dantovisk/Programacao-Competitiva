#include <bits/stdc++.h>
// #include <ext/pb_ds/priority_queue.hpp>
#include <bits/extc++.h> /// include-line, keep-include
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second

// #pragma once

const ll INF = numeric_limits<ll>::max() / 4;

//MCMF não é rápido o suficiente nesse caso
struct MCMF {
	struct edge {
		int from, to, rev;
		ll cap, cost, flow;
	};
	int N;
	vector<vector<edge>> ed;
	vi seen;
	vector<ll> dist, pi;
	vector<edge*> par;

	MCMF(int N) : N(N), ed(N), seen(N), dist(N), pi(N), par(N) {}

	void addEdge(int from, int to, ll cap, ll cost) {
		if (from == to) return;
		ed[from].push_back(edge{ from,to,sz(ed[to]),cap,cost,0 });
		ed[to].push_back(edge{ to,from,sz(ed[from])-1,0,-cost,0 });
	}

	void path(int s) {
		fill(all(seen), 0);
		fill(all(dist), INF);
		dist[s] = 0; ll di;

		__gnu_pbds::priority_queue<pair<ll, int>> q;
		vector<decltype(q)::point_iterator> its(N);
		q.push({ 0, s });

		while (!q.empty()) {
			s = q.top().second; q.pop();
			seen[s] = 1; di = dist[s] + pi[s];
			for (edge& e : ed[s]) if (!seen[e.to]) {
				ll val = di - pi[e.to] + e.cost;
				if (e.cap - e.flow > 0 && val < dist[e.to]) {
					dist[e.to] = val;
					par[e.to] = &e;
					if (its[e.to] == q.end())
						its[e.to] = q.push({ -dist[e.to], e.to });
					else
						q.modify(its[e.to], { -dist[e.to], e.to });
				}
			}
		}
		rep(i,0,N) pi[i] = min(pi[i] + dist[i], INF);
	}

	pair<ll, ll> maxflow(int s, int t) {
		ll totflow = 0, totcost = 0;
		while (path(s), seen[t]) {
			ll fl = INF;
			for (edge* x = par[t]; x; x = par[x->from])
				fl = min(fl, x->cap - x->flow);

			totflow += fl;
			for (edge* x = par[t]; x; x = par[x->from]) {
				x->flow += fl;
				ed[x->to][x->rev].flow -= fl;
			}
		}
		rep(i,0,N) for(edge& e : ed[i]) totcost += e.cost * e.flow;
		return {totflow, totcost/2};
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;

    int nodes = 2 + 2*n + 2*n*n; 
    int grande = 1e7 + 1;


    MCMF flow = MCMF(nodes);
    // 0 -> src
    // [1, n^2] -> cada nó
    // [n^2 + 1, n^2 + n] -> linhas
    // [n^2 + n + 1, n^2 + 2n] -> colunas
    // [n^2 + 2n + 1, 2n^2 + 2n] -> cada nó
    // 2n^2 + 2n + 1 -> sink

    int ids = 1;
    rep(i, 0, n){
        rep(j, 0, n){
            int a; cin>>a;
            //liga com o source
            flow.addEdge(0, ids, a, 0);

            
            //liga com a linha e da linha pro final
            flow.addEdge(ids , n*n + i + 1, grande, 1);
            flow.addEdge(n*n + i + 1 , n*n + 2*n + ids, grande, 0);

            //liga com a coluna e da coluna pro final
            flow.addEdge(ids , n*n + n + j + 1, grande, 1);
            flow.addEdge(n*n + n + j + 1 , n*n + 2*n + ids, grande, 0);

            //do target pro sink
            flow.addEdge(n*n + 2*n + ids, nodes-1, 1, 0);

            //ligações diretas
            flow.addEdge(ids, n*n + 2*n + ids, 1, 0);

            ids++;
        }
    }

    rep(i, 0, n){
        rep(j, 0, n){
            if(i == j) continue;
            
            //andar de uma coluna pra outra ou de uma linha pra outra
            flow.addEdge(n*n + i + 1, n*n + j + 1, grande, 1);
            flow.addEdge(n*n + n + i + 1, n*n + n + j + 1, grande, 1);
        }
    }

    pair<ll, ll> res = flow.maxflow(0, nodes-1);

    // cout<<res.first<<" "<<res.second<<"\n";
    cout<<res.second<<"\n";
}