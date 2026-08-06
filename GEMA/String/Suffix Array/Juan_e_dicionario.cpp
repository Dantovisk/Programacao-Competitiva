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

const int maxn = 2e5+4;
const int inf = 1e9+3;

/**
 * Author: 罗穗骞, chilli
 * Date: 2019-04-11
 * License: Unknown
 * Source: Suffix array - a powerful tool for dealing with strings
 * (Chinese IOI National team training paper, 2009)
 * Description: Builds suffix array for a string.
 * \texttt{sa[i]} is the starting index of the suffix which
 * is $i$'th in the sorted suffix array.
 * The returned vector is of size $n+1$, and \texttt{sa[0] = n}.
 * The \texttt{lcp} array contains longest common prefixes for
 * neighbouring strings in the suffix array:
 * \texttt{lcp[i] = lcp(sa[i], sa[i-1])}, \texttt{lcp[0] = 0}.
 * The input string must not contain any nul chars.
 * Time: O(n \log n)
 * Status: stress-tested
 */
struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string s, int lim=256) { // or vector<int>
		s.push_back(0); int n = sz(s), k = 0, a, b;
		vi x(all(s)), y(n), ws(max(n, lim));
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
			for (k && k--, j = sa[x[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

/**
 * Author: Johan Sannemo, pajenegod
 * Date: 2015-02-06
 * License: CC0
 * Source: Folklore
 * Description: Range Minimum Queries on an array. Returns
 * min(V[a], V[a + 1], ... V[b - 1]) in constant time.
 * Usage:
 *  RMQ rmq(values);
 *  rmq.query(inclusive, exclusive);
 * Time: $O(|V| \log |V| + Q)$
 * Status: stress-tested
 */
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

int pos[maxn];
int visto[maxn];

void solve(){
    int n;
    string a;
    cin>>n>>a;

    SuffixArray sa(a);

    // só para checar os valores
    // rep(i, 0, sz(a)+1){
    //     cout<<sa.lcp[i]<<" "<<sa.sa[i]<<'\n';
    // }

    RMQ rmq(sa.lcp);

    rep(i, 0, n+1){
        pos[sa.sa[i]] = i;
    }
    
    ll res = 0;
    int q;
    cin>>q;

    //guarda as posicoes vistas
    set<int> vis;

    rep(i, 0, q){
        int l, r;
        cin>>l>>r;

        int pr = l-1;
        int quero = r-l+1;
        int p = pos[pr];

        //nao muda nada
        if (quero <= visto[p]) {
            cout << res << "\n";
            continue;
        }

        int foi = visto[p];
        int limesq = -1, limdir = -1;

        
        auto ptr = vis.lower_bound(p);
        //testa pra esquerda
        if(ptr != vis.begin()){
            ptr--;
            int w = visto[(*ptr)];

            limesq = rmq.query((*ptr)+1, p+1);
            foi = max(foi, min(limesq, w));
        }

        //testa pra direita
        ptr = vis.upper_bound(p);
        if(ptr != vis.end()){
            int w = visto[(*ptr)];

            limdir = rmq.query(p+1, (*ptr)+1);
            foi = max(foi, min(limdir, w));
        }

        if(quero <= foi){
            visto[p] = max(visto[p], foi);
            cout << res << "\n";
            continue;
        }

        // agora realmente adicionamos novos caracteres
        res += quero - foi;
        visto[p] = quero;
        vis.insert(p);

        // limpa a esquerda
        auto curr = vis.find(p);
        while(curr != vis.begin()){
            auto L = prev(curr);

            int lim = rmq.query((*L)+1, p+1);
            int w = visto[*L];
            if(w <= lim and w <= quero){
                vis.erase(L);
            } else break;
        }

        // limpa a direita
        auto R = vis.upper_bound(p);
        while(R != vis.end()){
            int lim = rmq.query(p+1, (*R)+1);
            int w = visto[*R];
            if(w <= lim and w <= quero){
                R = vis.erase(R);
            } else break;
        }


        cout<<res<<"\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}