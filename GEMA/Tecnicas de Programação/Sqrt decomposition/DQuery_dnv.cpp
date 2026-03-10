#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAX = 3e4 + 7, MAXSZ = 1e6+3;

int v[MAX], freq[MAXSZ];
int cnt = 0;

void add(int ind, int end) {
    freq[v[ind]] ++;
    if(freq[v[ind]] == 1) cnt ++;
} // add a[ind] (end = 0 or 1)
void del(int ind, int end) {
    freq[v[ind]] --;
    if(freq[v[ind]] == 0) cnt --;
} // remove a[ind]
int calc() {
    return cnt;
} 

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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin>>n;
    rep(i, 0, n) cin>>v[i];

    int k; cin>>k;
    vector<pii> q;

    rep(i, 0, k){
        int a, b;
        cin>>a>>b;

        q.push_back({a-1,b});
    }

    vi res = mo(q);
    for(auto u : res) cout<<u<<"\n";
}