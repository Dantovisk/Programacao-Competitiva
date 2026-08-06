#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: User adamant on CodeForces
 * Source: http://codeforces.com/blog/entry/12143
 * Description: For each position in a string, computes p[0][i] = half length of
 *  longest even palindrome around pos i, p[1][i] = longest odd (half rounded down).
 * Time: O(N)
 * Status: Stress-tested
 */
array<vi, 2> manacher(const string& s) {
	int n = sz(s);
	array<vi,2> p = {vi(n+1), vi(n)};
	rep(z,0,2) for (int i=0,l=0,r=0; i < n; i++) {
		int t = r-i+!z;
		if (i<r) p[z][i] = min(t, p[z][l+t]);
		int L = i-p[z][i], R = i+p[z][i]-!z;
		while (L>=1 && R+1<n && s[L-1] == s[R+1])
			p[z][i]++, L--, R++;
		if (R>r) l=L, r=R;
	}
	return p;
}

const int inf = 1e9+7;
const int MAX = 2e5+3;

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
namespace seg {
	ll seg[4*MAX], lazy[4*MAX];
	int n, *v;

	ll build(int p=1, int l=0, int r=n-1) {
		lazy[p] = -1;
		if (l == r) return seg[p] = v[l];
		int m = (l+r)/2;
		return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
	}
	void build(int n2, int* v2) {
		n = n2, v = v2;
		build();
	}
	void prop(int p, int l, int r) {
        if(lazy[p] == -1) return;
		seg[p] = min(lazy[p], seg[p]);
		if (l != r) {
            lazy[2*p] = min(lazy[p], (lazy[2*p] != -1 ? lazy[2*p] : inf));
            lazy[2*p+1] = min(lazy[p], (lazy[2*p+1] != -1 ? lazy[2*p+1] : inf));
        }
		lazy[p] = -1;
	}
	ll query(int a, int b, int p=1, int l=0, int r=n-1) {
		prop(p, l, r);
		if (a <= l and r <= b) return seg[p];
		if (b < l or r < a) return inf;
		int m = (l+r)/2;
		return min(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
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
		return seg[p] = min(update(a, b, x, 2*p, l, m),
			update(a, b, x, 2*p+1, m+1, r));
	}
};

int st[MAX];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    string s; cin>>s;
    int n = sz(s);

    array<vi, 2> man = manacher(s);

    vi res(sz(s), 1);

    rep(i, 0, n) st[i] = i*2+1;
    seg::build(n, st);

    rep(i, 0, sz(s)){
        // cout<<man[0][i]<<" ";
        if(man[0][i])
            seg::update(i, i + man[0][i] - 1 , i*2);
        if(man[1][i])    
            seg::update(i, i + man[1][i], i*2 + 1);
    }


    rep(i, 0, n){
        int k = seg::query(i, i);
        int ds = (i - (k / 2) + 1)*2;

        // cout<<"l("<<i<<") = "<<k<<"\n";
        int res = ds - k%2;
        
        cout<<res<<" ";
    }
    cout<<"\n";
    // for(auto x: res) cout<<x<<"\n";


}