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

void solve(){
    int n; cin>>n;
    vi v(n);
    set<int> r;
    rep(i, 0, n) {
        cin>>v[i];
        r.insert(v[i]);
    }

    vector<pii> res;

    int mincov = n+1;

    UF uf = UF(n+1);

    rep(i, 0, n) {
        if(r.find(v[i]) != r.end()) r.erase(v[i]);

        auto ptr = r.lower_bound(v[i]);

        while(ptr != r.end()){
            if(uf.find(*ptr) == uf.find(v[i])) break;

            res.push_back({v[i], *ptr});
            uf.join(v[i], *ptr);
            ptr++;
        }
    }

    if(res.size() < n-1){
        cout<<"No\n";
        return;
    }

    cout<<"Yes\n";
    // A diferença entre o easy e o hard ta nessa linha
    // for(auto[a, b]:res) cout<<a<<" "<<b<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}