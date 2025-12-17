#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, int> tii;
typedef vector<ll> vi;

const int MAX = 2e5+7;
const int inf = 1e9+7;

namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = -inf;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = max(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}

    void prop(int p, int l, int r) {
        if(lazy[p] == -inf) return;
		seg[p] = max(lazy[p], seg[p]);
		if (l != r) lazy[2*p] = max(lazy[p], lazy[2*p]), lazy[2*p+1] = max(lazy[p], lazy[2*p+1]);
		lazy[p] = -inf;
	}

	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
        prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return -inf;
		int m = (l+r)/2;
		return max(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
	}

    ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] = x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = max(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}

    // primeira posicao >= val em [a, b] (ou -1 se nao tem)
    int get_left(int a, int b, int val, int p=1, int l=0, int r=n-1) {
        if (b < l or r < a or seg[p] < val) return -1;
        if (r == l) return l;
        int m = (l+r)/2;
        int x = get_left(a, b, val, 2*p, l, m);
        if (x != -1) return x;
        return get_left(a, b, val, 2*p+1, m+1, r);
    }

    // ultima posicao >= val em [a, b] (ou -1 se nao tem)
    int get_right(int a, int b, int val, int p=1, int l=0, int r=n-1) {
        if (b < l or r < a or seg[p] < val) return -1;
        if (r == l) return l;
        int m = (l+r)/2;
        int x = get_right(a, b, val, 2*p+1, m+1, r);
        if (x != -1) return x;
        return get_right(a, b, val, 2*p, l, m);
    }
};

int v[MAX], cost[MAX], q[MAX];

void solve(){
    int n; cin>>n;

    rep(i, 0, n) {
        cin>>v[i];
    }
    seg::build(n, v);

    rep(i, 0, n) {
        cin>>cost[i];
        cost[i] = -cost[i];
    }
    rep(i, 0, n) cin>>q[i];

    vi l(n), r(n);

    rep(i, 0, n){
        int a = seg::get_right(0, i, v[i]+1);
        int b = seg::get_left(i, n-1, v[i]+1);
        a = (a == -1? 0 : a+1);
        b = (b == -1? n-1 : b-1);
        l[i] = a;
        r[i] = b;
    }

    seg::build(n, cost);

    rep(i, 0, n){
        seg::update(l[i], r[i], cost[i]);
    }

    vi v2(n);
    rep(i, 0, n) v2[i] = seg::query(i, i);



    ll total = 0;
    //custo, id
    set<pair<int,int>> act;
    set<pair<int,int>> act2;
    rep(i, 0, n) {
        act.insert({-v2[i], i});
        act2.insert({i, -v2[i]});
        total -= v2[i];    
    }
    auto ptr = act.rbegin();
    int c = 0;
    if(ptr != act.rend()) c = (*ptr).first;

    cout<<total-c<<" ";
    
    rep(j, 0, n){
        // cout<<"Query "<<j<<": "<<q[j]<<"\n";
        int i = q[j] - 1;
        auto ptr = act2.lower_bound({l[i], -1});
        while(ptr != act2.end()){
            if((*ptr).first > r[i]) break;
            // cout<<"apagando "<<(*ptr).first<<" = "<<(*ptr).second<<"\n"; 

            total -= (*ptr).second;
            act.erase({(*ptr).second, (*ptr).first});
            ptr = act2.erase(ptr);
        }

        auto ptr2 = act.rbegin();
        int c = 0;
        if(ptr2 != act.rend()) c = (*ptr2).first;

        cout<<total-c<<" ";
    }
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}