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

void solve(){
    int n; cin>>n;
    vi v (n);

    int ct = 0;
    ll soma = 0;
    rep(i, 0, n) cin>>v[i];

    rep(i, 0, n){
        if(v[i] == -1) {
            if(i < n-1 && i > 0) v[i] = 0;
            else v[i] = max(v[n-i-1], 0);
        }
    }

    cout<<abs(v[0]-v[n-1])<<"\n";
    for(auto x: v) cout<<x<<" ";
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}