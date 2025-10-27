#include <bits/stdc++.h> // Static Range Inversions Query - LibChecker
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<long long> vi;

const int MAX = 1e5 + 7, MAXSZ = 2e6+3;

int v[MAX];
ll pref[MAX];

ll cnt = 0;
vector<int> cord;
int todos = 0;

// FT
vector<int> s(MAX);
void update(int pos, int dif = 1) { // a[pos] += dif
    for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
}
int query(int pos) { // sum of values in [0, pos)
    int res = 0;
    for (; pos > 0; pos &= pos - 1) res += s[pos-1];
    return res;
}


int id(int u){
    return lower_bound(all(cord), u) - cord.begin();
}

void add(int ind, int end) {
    int cara = id(v[ind]);

    if(end == 0){ // esq -> quantos caras menores que eu dps de mim
        cnt += query(cara);
    }
    else{ // dir -> quantos caras maiores q eu antes de mim
        cnt += todos - query(cara+1);
    }

    todos++;
    update(cara);

} // add a[ind] (end = 0 or 1)

void del(int ind, int end) {
    int cara = id(v[ind]);
    update(cara, -1);
    todos--;

    if(end == 0){ // esq -> quantos caras menores que eu dps de mim
        cnt -= query(cara);
    }
    else{ // dir -> quantos caras maiores q eu antes de mim
        cnt -= (todos - query(cara+1));
    }
} 

ll calc(){
    return cnt;
}

vi mo(vector<pii> Q) {
    int L = 1, R = 1, blk = 300; // ~N/sqrt(Q)
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
    int n, xd;
    cin>>n>>xd;

    cord.push_back(-1);
    rep(i, 1, n+1){
        cin>>v[i];
        cord.push_back(v[i]);
    }
    
    sort(all(cord));
    cord.resize(unique(all(cord)) - cord.begin());

    vector<pii> q;

    rep(i, 0, xd){
        int a, b;
        cin>>a>>b;
        q.push_back({a+1,b+1});
    }

    vi res = mo(q);
    for(auto u : res) cout<<u<<"\n";
}