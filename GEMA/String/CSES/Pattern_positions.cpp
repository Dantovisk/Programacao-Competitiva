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
const int inf = 1e7+67;
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
    vi nodeid;
    vi bfsord;
    vi dp;

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
		N[n].nmatches++;
        nodeid[j] = n;
	}
	AhoCorasick(vector<string>& pat) : N(1, -1) {
        nodeid.resize(sz(pat));
		rep(i,0,sz(pat)) insert(pat[i], i);
		N[0].back = sz(N);
		N.emplace_back(0);
        res.resize(sz(pat), -1);

		queue<int> q;
		for (q.push(0); !q.empty(); q.pop()) {
			int n = q.front(), prev = N[n].back;
            bfsord.push_back(n);
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
	vi find(string word) {
		dp.resize(sz(N), 2*inf);

        int n = 0;
        int ct = 1;
        for(auto c: word){
            n = N[n].next[c-first];
            dp[n] = min(dp[n], ct);
            // cout<<"dp["<<n<<"] = "<<dp[n]<<"\n";
            ct++;
        }

        reverse(all(bfsord));
        for(auto i: bfsord){
            dp[N[i].back] = min(dp[N[i].back], dp[i]);
            // cout<<"de "<<i<<" para "<<N[i].back<<"\n";
        }
	
        rep(i, 0, sz(res)){
            // cout<<i<<": "<<nodeid[i]<<"\n";
            res[i] = (dp[nodeid[i]] < inf? dp[nodeid[i]] : -1);
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

    vi res = ac.find(a);

    rep(i, 0, q) {
        auto x = res[i];
        cout<<(x != -1? x - sz(v[i]) + 1 : -1)<<"\n";
    }
}