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

const int MAX = 2510;

ll num1[MAX], num2[MAX];
set<ll> vis;
map <ll,int> id;
vector <ll> inv;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;

    vector<pii> q;

    for(int i=0;i<n; i++){
        ll a, b;
        cin>>a>>b;

        vis.insert(a-b);
        vis.insert(a+b);
        vis.insert(a*b);
        num1[i] = a;
        num2[i] = b;
    }

    int xd = 0;
    for(auto k: vis){
        id[k] = xd++;
        inv.push_back(k);
    }

    Dinic flow = Dinic(2+n+vis.size());

    for(int i=0; i<n; i++){
        flow.addEdge(0, i+1, 1);

        ll u = num1[i];

        ll x = u + num2[i], y = u - num2[i], z = u * num2[i];
        flow.addEdge(1+i, 1+n+id[x], 1);
        flow.addEdge(1+i, 1+n+id[y], 1);
        flow.addEdge(1+i, 1+n+id[z], 1);
    }

    for(int i =0; i<vis.size(); i++){
        flow.addEdge(1+n+i, n+vis.size()+1, 1);
    }

    ll res = flow.calc(0, n+vis.size()+1);
    // cout<<res<<"\n";

    if(res < n) {
        cout<<"impossible\n";
        return 0;
    }

    for(int i =1; i<= n; i++){
        for(auto e : flow.adj[i]){
            if(e.flow() == 1){
                string op;
                ll res = inv[e.to - n -1];
                if(num1[i-1] + num2[i-1] == res) op = " + ";
                else if(num1[i-1] - num2[i-1] == res) op = " - ";
                else op = " * ";
                cout<<num1[i-1]<<op<<num2[i-1]<<" = "<<res<<"\n";
            }
        }
    }
}