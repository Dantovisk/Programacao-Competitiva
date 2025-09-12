#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

const int MAX = 2e5 + 9;

int a[MAX], b[MAX], tr[MAX];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n, l, r;
    cin>>n>>l>>r;

    set<int> coord;
    map<int, int> id;

    int cta = 0, ctb = 0;

    for(int i = 0; i<n; i++) {
        cin>>tr[i];
        coord.insert(tr[i]);
    }
    for(int i = 0; i<l; i++) {
        cin>>a[i];
        coord.insert(a[i]);
    }
    for(int i = 0; i<r; i++) {
        cin>>b[i];
        coord.insert(b[i]);
    }
    coord.insert(0);

    int xd = 0;

    for(auto x: coord){
        id[x] = xd++;
    }

    FT ta = FT(coord.size()+2), tb = FT(coord.size()+2);
    
    int resp = 0;
    cout<<coord.size()<<"\n";
    cout<<"a\n";
    for(int i = 0; i<l; i++) {
        cout<<id[a[i]]<<" ";
        ta.update(id[a[i]], 1);
    }
    cout<<"\nb\n";
    for(int i = 0; i<r; i++) {
        cout<<id[b[i]]<<" ";
        tb.update(id[b[i]], 1);
    }

    for(int i = 0; i<n; i++) {
        //if(id[tr[i]] <= cta || id[tr[i]] <=ctb) continue;

        cout<<"\ntrain: "<<id[tr[i]]<<"\n";
        cout<<ta.query(id[tr[i]])<<" - "<<ta.query(cta)<<"\n";
        cout<<tb.query(id[tr[i]])<<" - "<<tb.query(ctb)<<"\n";

        int u = ta.query(id[tr[i]]) - ta.query(cta);
        int v = tb.query(id[tr[i]]) - tb.query(ctb);

        cout<<u<<" or "<<v<<"?\n";
        if(u < v){
            resp += u;
            cta = id[tr[i]];
        }else{
            resp += v;
            ctb = id[tr[i]];
        }
    }

    cout<<resp<<"\n";
}