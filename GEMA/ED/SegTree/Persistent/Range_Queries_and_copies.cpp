#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

/**
 * Author: Simon Lindholm
 * Date: 2016-10-08
 * License: CC0
 * Source: me
 * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
 * Can be changed to other things.
 * Use with a bump allocator for better performance, and SmallPtr or implicit indices to save memory.
 * Time: O(\log N).
 * Usage: Node* tr = new Node(v, 0, sz(v));
 * Status: stress-tested a bit
 */
const int inf = 1e9+3;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0;
    ll val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = l->val + r->val;
		}
		else val = v[lo];
	}
	ll query(int L, int R) {
		if (R <= lo || hi <= L) return 0;
		if (L <= lo && hi <= R) return val;
		push();
		return l->query(L, R) + r->query(L, R);
	}
    void setaux(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->setaux(L, R, x), r->setaux(L, R, x);
			val = max(l->val, r->val);
		}
	}

	Node* set(int L, int R, int x) {
		if (R <= lo || hi <= L) return this;
		if (L <= lo && hi <= R) {
            Node* nn = new Node(lo, hi);
            nn->mset = nn->val = x;
            return nn;
        }
		else {
            Node* nn = new Node(lo, hi);
			push(), nn->l = l->set(L, R, x), nn->r = r->set(L, R, x);
			nn->val = nn->l->val + nn->r->val;
            return nn;
		}
	}

	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->setaux(lo,hi,mset), r->setaux(lo,hi,mset), mset = inf;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, q;
    cin>>n>>q;

    vi v (n);

    rep(i, 0, n){
        cin>>v[i];
    }
    vector<Node*> vers;
    vers.push_back(new Node(v, 0, n));

    vi id(1, 0);

    rep(i, 0, q){
        int t, k;
        cin>>t>>k;
        k--;

        if(t==1){
            int a, x;
            cin>>a>>x;

            //eh excluso?
            vers.push_back(vers[id[k]]->set(a-1, a, x));
            id[k] = sz(vers)-1;
        }
        else if(t == 2){
            int a, b;
            cin>>a>>b;
            ll res = vers[id[k]]->query(a-1, b);
            cout<<res<<"\n";
        }
        else{
            id.push_back(id[k]);
        }

    }
}