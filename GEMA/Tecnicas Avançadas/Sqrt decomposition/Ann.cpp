#include <bits/stdc++.h> // Codeforces - Ann and Books
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<long long> vi;

const int MAX = 1e5 + 7, MAXSZ = 2e6+3;

int a[MAX], b[MAX], v[MAX];
ll pref[MAX];

ll cnt = 0;
vector<ll> cord;
int visr[MAXSZ], visl[MAXSZ];
int n;
ll k;

int id_pr[MAXSZ], id_targetr[MAXSZ], id_targetl[MAXSZ], id_pl[MAXSZ];

int id(ll u){
    return lower_bound(all(cord), u) - cord.begin();
}

void add(int ind, int end) {
    int p_r = id_pr[ind];
    int targetr = id_targetr[ind];
    int targetl = id_targetl[ind];
    int p_l = id_pl[ind];

    if(end == 0){ //add pela esquerda
        visl[p_l] ++;
        visr[p_r] ++;

        cnt += visr[targetl]; //procura fins validos
    } else{ // add pela direita
        visl[p_l] ++;
        visr[p_r] ++;

        cnt += visl[targetr]; //procura inicios validos
    }

} // add a[ind] (end = 0 or 1)

void del(int ind, int end) {
    int p_r = id_pr[ind];
    int targetr = id_targetr[ind];
    int targetl = id_targetl[ind];
    int p_l = id_pl[ind];

    if(end == 0){ //remove pela esquerda
        cnt -= visr[targetl]; 

        visl[p_l] --;
        visr[p_r] --;

    } else{ // remove pela direita
        cnt -= visl[targetr]; 

        visl[p_l] --;
        visr[p_r] --;
    }


} // remove a[ind]

ll calc() {
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

    cin>>n>>k;
    rep(i, 0, n) cin>>a[i];
    rep(i, 0, n) cin>>b[i];

    rep(i, 0, n){
        if(a[i] == 1) v[i+1] = b[i];
        else v[i+1] = -b[i];
    }

    rep(i, 0, n)
        pref[i+1] = pref[i] + v[i+1];
    
    rep(i, 0, n+1){
        cord.push_back(pref[i]);
        cord.push_back(pref[i] - k);
        cord.push_back(pref[i] + k);
    }

    
    sort(all(cord));
    cord.resize(unique(all(cord)) - cord.begin());
    
    rep(ind, 1, n+1){
        id_pr[ind] = id(pref[ind]);
        id_targetr[ind] = id(pref[ind] - k);
        id_targetl[ind] = id(pref[ind-1] + k);
        id_pl[ind] = id(pref[ind-1]);
    }

    int xd; cin>>xd;
    vector<pii> q;

    rep(i, 0, xd){
        int a, b;
        cin>>a>>b;
        q.push_back({a,b+1});
    }

    vi res = mo(q);
    for(auto u : res) cout<<u<<"\n";
}