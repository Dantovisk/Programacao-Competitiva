#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// SegTree
//
// Recursiva com Lazy Propagation
// Query: soma do range [a, b]
// Update: soma x em cada elemento do range [a, b]
// Pode usar a seguinte funcao para indexar os nohs:
// f(l, r) = (l+r)|(l!=r), usando 2N de memoria
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))
const int MAX = 4e5+7;

int seila[MAX];

namespace seg2 {
    //seg -> inicio
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

namespace seg {
    //seg -> inicio
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = 0;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = build(2*p, l, m) + build(2*p+1, m+1, r);
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
		seg[p] += lazy[p]*(r-l+1);
		if (l != r) lazy[2*p] += lazy[p], lazy[2*p+1] += lazy[p];
		lazy[p] = 0;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return 0;
		int m = (l+r)/2;
		return query(a, b, 2*p, l, m) + query(a, b, 2*p+1, m+1, r);
	}
	ll update(int a, int b, int x, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) {
			lazy[p] += x;
			prop(p, l, r);
			return seg[p];
		}
		if (b < l or r < a) return seg[p];
		int m = (l+r)/2;
		return seg[p] = update(a, b, x, 2*p, l, m) +
			update(a, b, x, 2*p+1, m+1, r);
	}
};

void solve(){
    int n, m;
    cin>>n>>m;

    seg::build(n, seila);

    //l, r, id
    set<tuple<int, int, int>> act;

    rep(i, 1, m+1){
        int l, r;
        cin>>l>>r;

        int qt = seg::query(l, r);

        auto it = act.lower_bound({l, l, 0});

        // cout<<qt<<"\n";
        if(it != act.begin()){
            it--;
            auto [l2, r2, id] = *it; 

            if(l2 < l && r2 >= l){
                qt += (r2-l2+1);
            }
        }
        

        if(qt > r-l+1){
            cout<<"0 0\n";
        }
        else{
            vi ret;

            auto ptr = act.lower_bound({l, l, 0});

            if(ptr != act.begin()){
                ptr--;
                auto [l2, r2, id] = *ptr; 

                if(l2 < l && r2 >= l){
                    seg::update(l2, l2, -(r2-l2+1));

                    ret.push_back(id);
                    ptr = act.erase(ptr);
                }else ptr++;
            }

            while(ptr != act.end() && get<0>(*ptr) <= r){
                auto [l2, r2, id] = *ptr;
                seg::update(l2, l2, -(r2-l2+1));

                ret.push_back(id);
                ptr = act.erase(ptr);
            }

            act.insert({l, r, i});
            seg::update(l, l, (r-l)+1);


            sort(all(ret));
            cout<<"1 "<<ret.size()<<" ";
            for(auto x: ret) cout<<x<<" ";            
            cout<<"\n";
        }
    }
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n = 1; 
    // cin>>n;
    rep(i, 0, n){
        solve();
    }
}