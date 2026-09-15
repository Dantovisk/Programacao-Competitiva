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
#define pb push_back

const int maxn = 2e5+4;
const int inf = 1e9+3;

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
};

void solve(){
    int n, q; 
    cin>>n>>q;

    string a;
    cin>>a;

    FT ft(n);

    rep(i, 0, n-1){
        if(a[i] == a[i+1]) {
            ft.update(i, 1);
        }
    }

    rep(i, 0, q){
        int l, r, k;
        cin>>l>>r>>k;
        l--;
        r--;

        int qt = ft.query(r+1);
        if(l > 0) qt -= ft.query(l);

        if(r < n-1 and a[r] == a[r+1]) qt--;

        if((qt+1)/2 <= k){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}