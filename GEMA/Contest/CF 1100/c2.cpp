#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<long long> vi;
#define ff first
#define ss second
#define pb push_back

const int maxn = 2e5+4;
const ll inf = 1e15+3;

void solve(){
    int n;
    cin>>n;

    vi a(n+1);

    vi pref(n+2, 0), suf(n+2, 0);

    rep(i, 1, n+1) {
        cin>>a[i];
        pref[i] = pref[i-1] + abs(a[i]);
    }
    for(int i = n; i> 0; i--){
        suf[i] = suf[i+1] + a[i];
    }

    pii best = {suf[1], 0};

    rep(i, 1, n+1){
        if(a[i] < 0) continue;
        ll curr = 0;
        curr += pref[i-1] + suf[i+1] - a[i]; 

        best = max(best, {curr, i});
    }

    // cout<<best.ff<<"\n";
    vi res;
    int sig = 1;
    for(int i = best.ss-1; i > 0; i--){
        if(a[i]*sig > 0){
            sig *= -1;
            res.push_back(i);
        }
    }

    if(best.ss) res.push_back(best.ss);

    cout<<res.size()<<"\n";
    for(auto x: res) cout<<x<<" ";
    cout<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}