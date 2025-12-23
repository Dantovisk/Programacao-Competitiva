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

void solve(){
    int n;
    cin>>n;

    vi v(n+1), pref(n+1, 0), suf(n+2, 0);
    rep(i, 1, n+1) {
        cin>>v[i];
    }

    rep(i, 2, n+1) {
        pref[i] = pref[i-1] + abs(v[i]- v[i-1]);
    }

    for(int i = n-1; i>= 1; i--){
        suf[i] = suf[i+1] + abs(v[i]- v[i+1]);
    }

    int best = 1e9+7;

    rep(i, 1, n+1) {
        int curr = pref[i-1] + suf[i+1];

        if(i >1 && i < n){
            curr += abs(v[i-1] - v[i+1]);
        }

        best  = min(best, curr);
    }

    cout<<best<<"\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}