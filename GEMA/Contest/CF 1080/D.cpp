#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back

void solve(){
    int n; 
    cin>>n;

    vi f(n+1);
    rep(i, 1, n+1) cin>>f[i];

    vi res(n+1, 0);
    for(int i = 2; i<n; i++){
        res[i] = (f[i+1] + f[i-1] - 2LL*f[i])/2LL;
    }

    ll resn = f[1];
    rep(i, 2, n){
        resn -= res[i] * ll(i-1);
    }
    res[n] = resn/(ll)(n-1);

    ll res1 = f[n];

    rep(i, 2, n){
        res1 -= res[i] * ll(n-i);
    }
    res[1] = res1/(ll)(n-1);

    rep(i, 1, n+1) cout<<res[i]<<" ";
    cout<<"\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}