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
    int n;
    cin>>n;

    vi v(n), pr(n, 0), sf(n, 0);
    rep(i, 0, n){
        cin>>v[i];
    }

    rep(i, 1, n){
        pr[i] = pr[i-1];
        if(v[i] == v[i-1]) pr[i]++;
    }

    for(int i = n-2; i>= 0; i--){
        sf[i] = sf[i+1];
        if(v[i] == v[i+1]) sf[i]++;
    }

    rep(i, 0, n){

    }

    int mn = pr[n-1];

    rep(i, 0, n-1){
        int l = (i > 0? pr[i-1] : 0);
        int r = (i < n-2? sf[i+2] : 0);
        if(v[i] == v[i+1]) l++;
        if(i > 0 and v[i+1] == v[i-1]) l++;
        if(i < n-2 and v[i+2] == v[i]) l++;
        mn = min(mn, l+r);
    }

    cout<<n-mn<<"\n";
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}