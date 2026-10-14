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
const ll inf = 1e17+3;

ll a[maxn];

void solve(){
    int n; 
    cin>>n;

    //minimo e maximo da soma S
    rep(i, 0, n) {
        cin>>a[i];
    }
    ll mn = a[0], mx = a[0];

    ll res = a[0];

    rep(i, 1, n){
        res = max({res, a[i], a[i]-mn, a[i]+mx});

        mn = min({a[i], mn + a[i], mn + a[i] + mn});
        mx = max({a[i], mx + a[i], mx + a[i] + mx});
    }

    cout<<res<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}