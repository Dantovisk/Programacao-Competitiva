#include <bits/stdc++.h> // SPOJ - DQuery
#define MAXN 30010      // Solve com MoQueries do kactl

using namespace std;
/**
 * Author: Simon Lindholm
 * Date: 2019-12-28
 * License: CC0
 * Source: https://github.com/hoke-t/tamu-kactl/blob/master/content/data-structures/MoQueries.h
 * Description: Answer interval or tree path queries by finding an approximate TSP through the queries,
 * and moving from one query to the next by adding/removing points at the ends.
 * If values are on tree edges, change \texttt{step} to add/remove the edge $(a, c)$ and remove the initial \texttt{add} call (but keep \texttt{in}).
 * Time: O(N \sqrt Q)
 * Status: stress-tested
 */

#define vi vector<int>
#define pii pair<int,int>
#define sz(x) (x).size()
#define all(x) (x).begin(),(x).end()

vector<int> v(MAXN); //array original
int freq[1000010]; //contagem de frequencia dos numeros
int cont = 0; //contagem de diferentes

// o end é mais avançado (acho que usa mais na moTree)
void add(int ind, int end) { if(++freq[v[ind]] == 1) cont++; } // add a[ind] (end = 0 or 1)
void del(int ind, int end) { if(--freq[v[ind]] == 0) cont--; } // remove a[ind]
int calc() { return cont; } // compute current answer

vi mo(vector<pii> Q) {
	int L = 0, R = 0, blk = 350; // ~N/sqrt(Q)
	vi s(sz(Q)), res = s;
#define K(x) pii(x.first/blk, x.second ^ -(x.first/blk & 1))
	iota(all(s), 0);
	sort(all(s), [&](int s, int t){ return K(Q[s]) < K(Q[t]); });
	for (int qi : s) {
		pii q = Q[qi];
		while (L > q.first) add(--L, 0);
		while (R < q.second) add(R++, 1);
		while (L < q.first) del(L++, 0);
		while (R > q.second) del(--R, 1);
		res[qi] = calc();
	}
	return res;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    vector<pii> Q;
    cin>>q;
    for(int i=0; i<q; i++){
        int a, b; cin>>a>>b;
        Q.push_back({a-1,b}); //no intervalo [a, b) (convertendo de 1 para 0 indexado)
    }

    vi r = mo(Q);
    for(auto x: r) cout<<x<<"\n";

    return 0;
}