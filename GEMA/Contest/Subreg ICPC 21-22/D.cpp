#include <bits/stdc++.h>    // DSU diferenciado para bipartição dinâmica
using namespace std;        // Nao sei fazer ainda

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define tii tuple<int, int, int>

const int MAX = 6e5+ 15;
const ll mod  = 1e9+7;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

vector<tii> adj;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    rep(i, 0, m){
        int u, v, w;
        cin>>u>>v>>w;
        adj.push_back({w, u, v});
    }


    return 0;
}