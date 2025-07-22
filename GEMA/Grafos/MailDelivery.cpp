#include <bits/stdc++.h>    // CSES - Mail Delivery
#define pii pair<int,int>   // Questão sobre Eulerian path
#define MAXN 100010          // Utilizaremos Hierholzer’s algorithm
#define vi vector<int>
#define sz(x) int((x).size())

using namespace std;

vector<vector<pii>> adj(MAXN);

/**
 * Author: Simon Lindholm
 * Date: 2019-12-31
 * License: CC0
 * Source: folklore
 * Description: Eulerian undirected/directed path/cycle algorithm.
 * Input should be a vector of (dest, global edge index), where
 * for undirected graphs, forward/backward edges have the same index.
 * Returns a list of nodes in the Eulerian path/cycle with src at both start and end, or
 * empty list if no cycle/path exists.
 * To get edge indices back, add .second to s and ret.
 * Time: O(V + E)
 * Status: stress-tested
 */

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret, s = {src};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back(), y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(x); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back(y);
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin>>n>>m;


    for(int i=0; i<m; i++){
        int a, b;
        cin>>a>>b;

        //salva também o indice das arestas
        adj[--a].push_back({--b, i});
        adj[b].push_back({a, i});
    }

    vi res = eulerWalk(adj, m, 0);

    if(res.size() == 0 || m == 1) cout<<"IMPOSSIBLE\n";
    else{
        for (auto x: res) cout<<x+1<<" ";
    }

    return 0;
        
}

