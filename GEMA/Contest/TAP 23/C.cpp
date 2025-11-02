#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n; cin>>n;

    vi a(n), b(n);

    rep(i, 0, n) cin>>a[i];
    rep(i, 0, n) cin>>b[i];

    sort(all(a));
    sort(all(b)); reverse(all(b));

    int maxx = 0;
    int minn = 2e9+3;

    rep(i, 0, n){  
        maxx = max(maxx, b[i] + a[i]);
        minn = min(minn, a[i]+b[i]);
    }

    cout<<maxx-minn<<"\n";
}