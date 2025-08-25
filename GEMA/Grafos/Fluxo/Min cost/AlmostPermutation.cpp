#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

//#include <bits/extc++.h> /// include-line, keep-include
#include <ext/pb_ds/priority_queue.hpp>

const ll INF = numeric_limits<ll>::max() / 4;

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
        //cout<<"Edge: "<<from<<" -> "<<to<<", c = "<<cost<<"\n";
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

	// If some costs can be negative, call this before maxflow:
	void setpi(int s) { // (otherwise, leave this out)
		fill(all(pi), INF); pi[s] = 0;
		int it = N, ch = 1; ll v;
		while (ch-- && it--)
			rep(i,0,N) if (pi[i] != INF)
			  for (edge& e : ed[i]) if (e.cap)
				  if ((v = pi[i] + e.cost) < pi[e.to])
					  pi[e.to] = v, ch = 1;
		assert(it >= 0); // negative cost cycle
	}
};



int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, q;
    cin>>n>>q;

    vector <vi> pos(n+1, vi(n+1, 1));


    while(q--){
        int t, l, r, v;
        cin>>t>>l>>r>>v;

        for(int i =l; i<=r; i++){
            if(t==1){
                for(int j =1; j<v; j++)
                    pos[i][j] = 0;
            }
            else{
                for(int j =v+1; j<= n; j++)
                    pos[i][j] = 0;
            }
        }
    }

    

    //construção do grafo
    MCMF fluxo = MCMF(2*n+2);

    
    for(int j = 1; j<=n; j++){
        int ant = 0;
        for(int i =1; i<=n; i++){
            fluxo.addEdge(0, j, 1, i*i - ant);
            ant = i*i;
        }
    }

    for(int j = 1; j<=n; j++){
        for(int i =1; i<=n; i++){
            if(pos[j][i]){
                fluxo.addEdge(i, j+n, 1, 0);
            }
        }
    }
    for(int i = n+1; i<=n*2; i++){
        fluxo.addEdge(i,2*n+1, 1, 0);
    }


    
    auto[flow, cost] = fluxo.maxflow(0, n*2+1);

    if(flow < n) cout<<"-1\n";
    else cout<<cost<<"\n";
}