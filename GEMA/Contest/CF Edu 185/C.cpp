#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
#define ff first
#define ss second
#define pb push_back

void solve(){
    int n; cin>>n;

    ll k; cin>>k;
    vi q(n), r(n);

    multiset<ll> val;

    rep(i, 0, n) {
        cin>>q[i];
        val.insert(q[i]);
    }
    rep(i, 0, n) cin>>r[i];

    sort(all(r)); reverse(all(r));

    int res = 0;

    rep(i, 0, n){
        ll sobra = k-r[i];

        ll mx = 0;

        ll l = 0, d = 1e9+7;

        while(l < d){
            ll mid = (l+d)/2LL;
            if((r[i] + 1LL) * mid <= sobra){
                mx = max(mx, mid);
                l = mid+1;
            }
            else d = mid;
        }

        auto ptr = val.lower_bound(mx+1);
        if(ptr == val.begin()) continue;

        ptr--;
        val.erase(ptr);
        res++;

    }

    cout<<res<<"\n";

}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}