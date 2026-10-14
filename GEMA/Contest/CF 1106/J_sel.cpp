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

const int MAX = 6e5+10;
const int LOG = 20;

// SegTree Iterativa com Lazy Propagation
//
// Query: soma do range [a, b]
// Update: update x em cada elemento do range [a, b]
// Para mudar, mudar as funcoes junta, poe e query
// LOG = ceil(log2(MAX))
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))

namespace seg {
	ll seg[2*MAX], lazy[2*MAX];
	int n;

	ll junta(ll a, ll b) {
		return a+b;
	}

	// altera x na posicao p de tamanho tam
	void poe(int p, ll x, int tam, bool prop=1) {
        if(x == -1) return;
		seg[p] = x*tam;
		if (prop and p < n) lazy[p] = x;
	}

	// atualiza todos os pais da folha p
	void sobe(int p) {
		for (int tam = 2; p /= 2; tam *= 2) {
			seg[p] = junta(seg[2*p], seg[2*p+1]);
			poe(p, lazy[p], tam, 0);
		}
	}

	// propaga o caminho da raiz ate a folha p
	void prop(int p) {
		int tam = 1 << (LOG-1);
		for (int s = LOG; s; s--, tam /= 2) {
			int i = p >> s;
			if (lazy[i] != -1) {
				poe(2*i, lazy[i], tam);
				poe(2*i+1, lazy[i], tam);
				lazy[i] = -1;
			}
		}
	}

	void build(int n2, int* v) {
		n = 1;
        while(n < n2) n *= 2; 


		for (int i = 0; i < n; i++) seg[n+i] = v[i];
		for (int i = n-1; i; i--) seg[i] = junta(seg[2*i], seg[2*i+1]);
		for (int i = 0; i < 2*n; i++) lazy[i] = -1;
	}

	ll query(int a, int b) {
		ll ret = 0;
		for (prop(a+=n), prop(b+=n); a <= b; ++a/=2, --b/=2) {
			if (a%2 == 1) ret = junta(ret, seg[a]);
			if (b%2 == 0) ret = junta(ret, seg[b]);
		}
		return ret;
	}

	void update(int a, int b, int x) {
		int a2 = a += n, b2 = b += n, tam = 1;
		for (; a <= b; ++a/=2, --b/=2, tam *= 2) {
			if (a%2 == 1) poe(a, x, tam);
			if (b%2 == 0) poe(b, x, tam);
		}
		sobe(a2), sobe(b2);
	}
};

// HLD - aresta
//
// SegTree de soma
// query / update de soma das arestas
//
// Complexidades:
// build - O(n)
// query_path - O(log^2 (n))
// update_path - O(log^2 (n))
// query_subtree - O(log(n))
// update_subtree - O(log(n))

// namespace seg { ... }

namespace hld {
	vector<pair<int, int> > g[MAX];
	int pos[MAX], sz[MAX];
	int sobe[MAX], pai[MAX];
	int h[MAX], v[MAX], t;

	void build_hld(int k, int p = -1, int f = 1) {
		v[pos[k] = t++] = sobe[k]; sz[k] = 1;
		for (auto& i : g[k]) if (i.first != p) {
			auto [u, w] = i;
			sobe[u] = w; pai[u] = k;
			h[u] = (i == g[k][0] ? h[k] : u);
			build_hld(u, k, f); sz[k] += sz[u];

			if (sz[u] > sz[g[k][0].first] or g[k][0].first == p)
				swap(i, g[k][0]);
		}
		if (p*f == -1) build_hld(h[k] = k, -1, t = 0);
	}
	void build(int root = 0) {
		t = 0;
		build_hld(root);
		seg::build(t, v);
	}
	ll query_path(int a, int b) {
		if (a == b) return 0;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return seg::query(pos[b]+1, pos[a]);
		return seg::query(pos[h[a]], pos[a]) + query_path(pai[h[a]], b);
	}
	void update_path(int a, int b, int x) {
		if (a == b) return;
		if (pos[a] < pos[b]) swap(a, b);

		if (h[a] == h[b]) return (void)seg::update(pos[b]+1, pos[a], x);
		seg::update(pos[h[a]], pos[a], x); update_path(pai[h[a]], b, x);
	}
	ll query_subtree(int a) {
		if (sz[a] == 1) return 0;
		return seg::query(pos[a]+1, pos[a]+sz[a]-1);
	}
	void update_subtree(int a, int x) {
		if (sz[a] == 1) return;
		seg::update(pos[a]+1, pos[a]+sz[a]-1, x);
	}
}

/**
 * Source: https://e-maxx.ru/algo/ukkonen
 * Description: Ukkonen's algorithm for online suffix tree construction.
 *  Each node contains indices [l, r) into the string, and a list of child nodes.
 *  Suffixes are given by traversals of this tree, joining [l, r) substrings.
 *  The root is 0 (has l = -1, r = 0), non-existent children are -1.
 *  To get a complete tree, append a dummy symbol -- otherwise it may contain
 *  an incomplete path (still useful for substring matching, though).
 * Time: $O(26N)$
 */
struct SuffixTree {
	enum { N = 600010, ALPHA = 27 }; // N ~ 2*maxlen+10
	int toi(char c) { return c - 'a'; }
	string a; // v = cur node, q = cur position
	int t[N][ALPHA],l[N],r[N],p[N],s[N],v=0,q=0,m=2;

	void ukkadd(int i, int c) { suff:
		if (r[v]<=q) {
			if (t[v][c]==-1) { t[v][c]=m;  l[m]=i;
				p[m++]=v; v=s[v]; q=r[v];  goto suff; }
			v=t[v][c]; q=l[v];
		}
		if (q==-1 || c==toi(a[q])) q++; else {
			l[m+1]=i;  p[m+1]=m;  l[m]=l[v];  r[m]=q;
			p[m]=p[v];  t[m][c]=m+1;  t[m][toi(a[q])]=v;
			l[v]=q;  p[v]=m;  t[p[m]][toi(a[l[m]])]=m;
			v=s[p[m]];  q=l[m];
			while (q<r[m]) { v=t[v][toi(a[q])];  q+=r[v]-l[v]; }
			if (q==r[m])  s[m]=v;  else s[m]=m+2;
			q=r[v]-(q-r[m]);  m+=2;  goto suff;
		}
	}

	SuffixTree(string a) : a(a) {
		fill(r,r+N,sz(a));
		memset(s, 0, sizeof s);
		memset(t, -1, sizeof t);
		fill(t[1],t[1]+ALPHA,0);
		s[0] = 1; l[0] = l[1] = -1; r[0] = r[1] = p[0] = p[1] = 0;
		rep(i,0,sz(a)) ukkadd(i, toi(a[i]));

	}
};

const int maxn = 4e5+10;

int suff[maxn];
int par[maxn][20];
int sum[maxn][20];

void solve(){
    int n; cin>>n;
    string a; cin>>a;

    // reverse(all(a));
    a.push_back('a'+26);
    SuffixTree* st = new SuffixTree(a);

    vector<vi> adj (st->m);
    // cout<<"st: "<<st->m<<"\n";

    queue<pii> q;
    q.push({0, 0});

    vector<tuple<int, int, int>> edit;
    memset(par, -1, sizeof(par));

    //gera o grafo pro HLD
    while(!q.empty()){
        auto [u, w] = q.front();
        q.pop();

        // cout<<"to no "<<u<<", com peso "<<w<<"\n";
        // return;

        rep(i, 0, 27){
            int v = st->t[u][i];
            if(v != -1){
                // cout<<u<<" -> "<<v<<"\n";
                adj[u].pb(v);
                adj[v].pb(u);
                q.push({v, w + ((st->r[u]) - (st->l[u]))});
                edit.pb({u, v, ((st->r[v]) - (st->l[v]))});
                par[v][0] = u;
                sum[v][0] = ((st->r[v]) - (st->l[v]));
            }
        }

        if(u != 0 and adj[u].size() == 1){
            w += (st->r[u]) - (st->l[u]);
            // cout<<"w terminal: "<<w-2<<"\n";
            if(w >= 2)
                suff[w-2] = u; 
        }
    }

    //builda a segtree do hld
    // HLD<true> *hld = new HLD<true>(adj);

    // vi pesos(st->m, 0);
    // for(auto [u, v, w] : edit){
    //     pesos[hld::pos[v]] = w;
    // }
    // hld::tree = new Node(pesos, 0, st->m);

    for(auto [u, v, w] : edit){
        hld::g[u].push_back({v, w});
        hld::g[v].push_back({u, w});
    }
    hld::build();

    // precomputa o binary lifting
    rep(j, 1, 19){
        rep(i, 0, st->m){
            if(par[i][j-1] == -1) continue;
            if(par[par[i][j-1]][j-1] == -1) continue;
            par[i][j] = par[par[i][j-1]][j-1];
            sum[i][j] = sum[i][j-1] + sum[par[i][j-1]][j-1];
        }
    }

    ll base = hld::query_subtree(0);
    // cout<<base<<"\n";

    // rep(i, 0, 8) cout<<"suff("<<i<<") = "<<suff[i]<<'\n';

    int quer; cin>>quer;
    while(quer--){
        int l1, r1;
        cin>>l1>>r1;

        int idsuf = n - (l1-1);

        int u = suff[idsuf];
        int sobra = n+1-r1;

        // encontra quem eu quero apagar
        int v = u;
        for(int j = 18; j>= 0; j--){
            if(par[v][j] != -1 && sobra >= sum[v][j]){
                sobra -= sum[v][j];
                v = par[v][j];
            }
        }

        if(sobra > 0) {
            int aux = hld::query_path(v, par[v][0]);
            hld::update_path(v, par[v][0], min(aux, sobra));
            v = par[v][0];
        }
        if(v != 0)
        {
            // cout<<"apagando: "<<hld::queryPath(v, 0)<<"\n";
            hld::update_path(v, 0, 0);
        }

        cout<<base - (hld::query_subtree(0))<<"\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;
    while(t--) solve();
}

/*
6
aaaaab 
8
2 4
1 3
2 3
6 6
4 6
1 6
2 6
3 6
*/