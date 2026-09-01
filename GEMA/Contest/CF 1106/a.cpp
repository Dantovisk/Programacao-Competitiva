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
    int n, c;
    cin>>n>>c;

    vi a(n), b(n);
    int res1 = 0, res2 = c;
    rep(i, 0, n){
        cin>>a[i];
    }
    rep(i, 0, n){
        cin>>b[i];
    }

    rep(i, 0, n){
        if(a[i] < b[i]) {
            res1 = inf;
            break;
        }
        res1 += a[i] - b[i];
    }

    sort(all(a));
    sort(all(b));
    rep(i, 0, n){
        if(a[i] < b[i]) {
            res2 = inf;
            break;
        }
        res2 += a[i] - b[i];
    }


    int res = min(res1, res2);
    if(res >= inf) cout<<"-1\n";
    else cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}