#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).sizee()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

ll soma = 0;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int sizee(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
        ll x1 = sizee(a);
        ll x2 = sizee(b);

        soma -= (x1*(x1-1))/2LL;
        soma -= (x2*(x2-1))/2LL;

        x1 += x2;

        soma += (x1*(x1-1))/2LL;

		e[a] += e[b]; e[b] = a;
		return true;
	}
};

void solve(){
    soma = 0;
    int n;
    cin>>n;

    vector<pii> junta;
    vector<ll> resp(n+1, 0);
    vi v(n);
    rep(i, 0, n) {
        cin>>v[i];
    }

    rep(i, 0, n-1) {
        junta.push_back({abs(v[i]-v[i+1]), i});
    }
    sort(all(junta));
    reverse(all(junta));

    UF uf = UF(n+1);

    int id = 0;
    for(int i = n-1; i>=1; i--){
        while(id < n-1 && junta[id].first == i){
            int k = junta[id].second;
            uf.join(k, k+1);
            id++;
        }

        resp[i] = soma;
    }

    rep(i, 1, n){
        cout<<resp[i]<<" ";
    }
    cout<<"\n";
}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}