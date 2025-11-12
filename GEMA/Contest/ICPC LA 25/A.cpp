#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
 */

bool ehCycle = false; 

vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret, s = {src};
	if(!ehCycle) D[src]++; // to allow Euler paths, not just cycles
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

int proib[1010][1010];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;

    int l, r;
    cin>>l;

    int cnt = 0;

    vector<vector<pii>> adj(n+1, vector<pii>(0));

    int from = -1, to = -1;
    int last = 0;
    
    if(l>0) {
        cin>>last;
        from = last;
    }
    rep(i, 1, l){
        int a; cin>>a;
        if(proib[last][a] == 1 || last == a){
            cout<<"N\n";
            return 0;
        }

        proib[last][a] = 1;
        proib[a][last] = 1;

        last = a;
        from = a;
    }

    cin>>r;
    int last2 = 0;

    if(r>0) {
        cin>>last2;
        to = last2;
    }
    rep(i, 1, r){
        int a; cin>>a;
        if(proib[last2][a] == 1 || last2==a){
            cout<<"N\n";
            return 0;
        }

        proib[last2][a] = 1;
        proib[a][last2] = 1;
        
        last2 = a;
    }

    int id = 0;
    for (int i = 1; i<= n; i++){
        for (int j = i+1; j<= n; j++){
            if(proib[i][j]) continue;
            
            adj[i].push_back({j, id});
            adj[j].push_back({i, id});
            id++;
        }
    }

    
    int start = 1;
    
    if(id == 0){
        if(from != -1 && from == to){
            cout<<"N\n";
        }
        else if(from != -1 && to != -1 && proib[from][to] == 1){
            cout<<"N\n";
        }
        else{
            cout<<"Y\n";
        }
        return 0;
    }

    if(from != -1 && to != -1){
        if(from != to) {
            adj[to].push_back({from, id});
            // adj[from].push_back({to, id});
            id++;
        }
        start = from;
        ehCycle = true;
    }
    else if(from != -1){
        start = from;
    }
    else if(to != -1){
        start = to;
    }
    else{
        start = 1;

        for(int i = 1; i<=n; i++){
            if(adj[i].size() > 0) {
                start = i;
                break;
            }
        }

        for(int i = 1; i<=n; i++){
            if(adj[i].size() % 2) {
                start = i;
                break;
            }
        }

    }
    
    // cout<<"Foi\n";
    // return 0;


    vi res = eulerWalk(adj, id, start);
    if(res.size() == id + 1) cout<<"Y\n";
    else cout<<"N\n";

}