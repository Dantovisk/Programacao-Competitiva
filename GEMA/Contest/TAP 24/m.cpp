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

void solve(){
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> a(n);
    rep(i, 0, n) cin >> a[i].ff;
    rep(i, 0, n) cin >> a[i].ss;

    rep(i, 0, n) {
        int s;
        cin >> s;
        s = a[i].ff - s;
        if(s > 0) {
            a.push_back({s, inf});
        }
    }

    sort(all(a));
    reverse(all(a));

    ll res = 0;
    for(auto [v, c]: a) {
        c = min(c, k);
        k -= c;
        res += (ll) v * c;
    }

    cout << res << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}