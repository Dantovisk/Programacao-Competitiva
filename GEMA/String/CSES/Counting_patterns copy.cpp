#include <bits/stdc++.h>
using namespace std;
// COUNTING PATTERNS

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second

/**
 * Author: Simon Lindholm
 * Date: 2015-02-18
 * License: CC0
 * Source: marian's (TC) code
 * Description: Aho-Corasick automaton, used for multiple pattern matching.
 * Initialize with AhoCorasick ac(patterns); the automaton start node will be at index 0.
 * find(word) returns for each position the index of the longest word that ends there, or -1 if none.
 * findAll($-$, word) finds all words (up to $N \sqrt N$ many if no duplicate patterns)
 * that start at each position (shortest first).
 * Duplicate patterns are allowed; empty patterns are not.
 * To find the longest words that start at each position, reverse all input.
 * For large alphabets, split each symbol into chunks, with sentinel bits for symbol boundaries.
 * Time: construction takes $O(26N)$, where $N =$ sum of length of patterns.
 * find(x) is $O(N)$, where N = length of x. findAll is $O(NM)$.
 * Status: stress-tested
 */
struct AhoCorasick {
    enum {alpha = 26, first = 'a'}; // change this!
	struct Node {
		// (nmatches is optional)
		int back, next[alpha], start = -1, end = -1, nmatches = 0;
		Node(int v) { memset(next, v, sizeof(next)); }
	};
	vector<Node> N;
	vi backp;

    vi res;
    vi bfs_order;
    vi fim_pat;
	void insert(string& s, int j) {
		assert(!s.empty());
		int n = 0;
		for (char c : s) {
			int& m = N[n].next[c - first];
			if (m == -1) { n = m = sz(N); N.emplace_back(-1); }
			else n = m;
		}
		if (N[n].end == -1) N[n].start = j;
		backp.push_back(N[n].end);
		N[n].end = j;

        fim_pat[j] = n;
		N[n].nmatches++;
	}

	AhoCorasick(vector<string>& pat) : N(1, -1) {
        fim_pat.resize(sz(pat));
		rep(i,0,sz(pat)) insert(pat[i], i);
		N[0].back = sz(N);
		N.emplace_back(0);
        res.resize(sz(pat));

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
            int n = q.front(), prev = N[n].back;
            bfs_order.push_back(n);
			rep(i,0,alpha) {
				int &ed = N[n].next[i], y = N[prev].next[i];
				if (ed == -1) ed = y;
				else {
					N[ed].back = y;
					(N[ed].end == -1 ? N[ed].end : backp[N[ed].start])
						= N[y].end;
					N[ed].nmatches += N[y].nmatches;
					q.push(ed);
				}
			}
		}
	}

    vector<vi> adj;
    vi dp;

    vi countOcurr(string word){
        dp.resize(sz(N), 0);
        adj.resize(sz(N));

        int n = 0;
		for (char c : word) {
			n = N[n].next[c - first];
			dp[n] ++;
		}
        
        //propaga a dp pela ordem topologica (de baixo pra cima)
        reverse(all(bfs_order));
        // cout<<sz(N)<<"!\n";
        for(auto i: bfs_order){
            dp[N[i].back] += dp[i];
        }

        rep(i, 0, sz(res)){
            res[i] = dp[fim_pat[i]];
        }
        return res;
    }
};
 
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
 
    string a;
    cin>>a;

    int q;
    cin>>q;
    vector<string> v(q);
    rep(i, 0, q) cin>>v[i];

    AhoCorasick ac(v);

    vi res = ac.countOcurr(a);

    for(auto x: res) cout<<x<<"\n";
}