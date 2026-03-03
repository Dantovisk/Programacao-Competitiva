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
#define pb push_back

const int MAX = 1e6+7;
const int inf = 1e9+7;
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

vector<pii> eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges);
    vector<pii> ret, s = {{src, -1}};
	// D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back().first, y, e = s.back().second, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back({x, e}); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back({y, e});
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
    return {ret.rbegin(), ret.rend()};
}

int vis[MAX];

vi r;

void dfs(int u, int p, vector<vector<pii>>& gr){
    r.pb(u);
    vis[u] = 1;

    for(auto [v, id]: gr[u]){
        if(v == p) continue;
        if(vis[v]) continue;
        dfs(v, u, gr);
    }
}

void solve(){
    int n; 
    cin>>n;

    memset(vis, 0, sizeof(int)*(n+3));

    vi a(n), b(n), inv(n), inved(n);
    vi cont(n, 0);
    vector<vector<pii>> gr(n);
    rep(i, 0, n) cin>>a[i];
    rep(i, 0, n) cin>>b[i];

    rep(i, 0, n){
        a[i]--;
        b[i]--;
        cont[a[i]]++;
        cont[b[i]]++;
        gr[a[i]].pb({b[i], i});
        gr[b[i]].pb({a[i], i});
    }

    rep(i, 0, n){
        if(cont[i] % 2){
            cout<<"-1\n";
            return;
        }
    }

    vector<int> res;
    rep(i, 0, n){
        if(vis[i]) continue;
        r.clear();
        dfs(i, -1, gr);
        vi curr = r;

        if(curr.size() == 1) continue;

        // for(auto x: curr) cout<<x<<"!\n";
        vector<vector<pii>> gr2(sz(curr));

        vi edord;
        int ct = 0;
        int ct2 = 0;

        unordered_set <int> vise;
        for(auto v: curr) {
            inv[v] = ct++;
        }

        for(auto u: curr){
            for(auto [v, id]: gr[u]){
                if(vise.find(id) == vise.end()){
                    vise.insert(id);
                    inved[id] = ct2++;
                    edord.pb(id);
                }

                gr2[inv[u]].pb({inv[v], inved[id]});
            }
        }

        vector<pii> ed = eulerWalk(gr2, ct2, 0);
        //  vector<int> ed = eulerWalk(gr, 0, 0);
    
        if(!ed.size()){
            cout<<"-1\n";
            return;
        }
    
        for(auto [node, e] : ed){
            // cout<<node<<" -> "<<e<<"\n";
            if(e < 0) continue;
            if(b[edord[e]] == curr[node]) res.pb(edord[e]+1);
        }
    }

    sort(all(res));

    cout<<res.size()<<"\n";
    for(auto k: res) cout<<k<<" ";
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--) solve();
}