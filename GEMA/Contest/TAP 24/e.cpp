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

struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

const int maxp = 1e5 + 10;

int a[maxn], b[maxn], c[maxn];
int dp[maxp];

void solve(){
    int n, p;
    cin >> n >> p;
    
    vector<pair<int, pair<int, int>>> caras(n);
    rep(i, 0, n) {
        cin >> caras[i].ff >> caras[i].ss.ff >> caras[i].ss.ss;
    }
    sort(all(caras));
    rep(i, 0, n) {
        a[i+1] = caras[i].ff;
        b[i+1] = caras[i].ss.ff;
        c[i+1] = caras[i].ss.ss;
    }   

    Tree seg(p+5);
    seg.update(p, 0);
    rep(i, 0, p) dp[i] = -inf;

    rep(i, 1, n+1) {
        for(int j = 0; j <= p; j++) {
            ll low = (ll) j * a[i] + b[i];
            ll high = low + a[i] - 1;
            high = min(high, (ll) p);
            
            if(low <= high) {
                int r = c[i] + seg.query(low, high+1);
                if(r > dp[j]) {
                    dp[j] = r;
                    seg.update(j, r);
                }
            }

            //cerr << i << " " << j << " " << dp[j] << endl;
        }
    }

    cout << seg.query(0, p+1) << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}