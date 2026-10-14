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
    int n, m; 
    cin>>n>>m;
    vi a(n), b(m);

    rep(i, 0, n) cin>>a[i];
    rep(i, 0, m) cin>>b[i];

    sort(all(a));
    sort(all(b));

    int l =0;
    vi a2, b2;
    rep(i, 0, m){
        while(l < n and a[l] < b[i]){
            a2.pb(a[l]);
            l++;
            // cout<<"a\n";
        }
        if(l >= n){
            b2.pb(b[i]);
            // cout<<"b\n";
            continue;
        }

        if(a[l] == b[i]) {
            l++;
            // cout<<"c\n";
            continue;
        }
        else {
            // b[i] < a[l]
            // cout<<"d\n";
            b2.pb(b[i]);
        }
    }
    rep(i, l , n) a2.pb(a[i]);

    // for(auto x: a2) cout<<x<<" ";
    // cout<<"\n";

    // cout<<sz(b2)<<" - "<<sz(a2)<<'\n';

    l = 0;
    int r = sz(a2)-sz(b2);
    if(2*b2.size() > sz(a2)){
        cout<<"NO\n";
        return;
    }

    rep(i, 0, sz(b2)){
        if(a2[l] > b2[i]){
            cout<<"NO\n";
            return;
        }
        if(a2[r] < b2[i]){
            cout<<"NO\n";
            return;
        }
        l++;
        r++;
    }

    cout<<"YES\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}