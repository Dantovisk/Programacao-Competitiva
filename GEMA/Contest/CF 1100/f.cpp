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

const int maxn = 2e5+4;
const int inf = 1e9+3;

void solve(){
    int n, k;
    cin>>n>>k;

    vi v(n);
    rep(i, 0, n) cin>>v[i];

    sort(all(v));
    ll add = v[n-1];
    if(n == k){
        cout<<add<<"\n";
        return;
    }
    n--;
    v.pop_back();

    ll best = 0;
    ll l = 1, r = 3e10+2;
    while(l < r){
        ll m = (l+r)/2LL;
        vector<vi> dp(k+1, vi((1<<n), -1)); // dp[k][mask];

        dp[0][0] = 0;

        for(int mk = 0; mk < (1<<n); mk++){
            rep(i, 0, k){
                if(dp[i][mk] == -1) continue;

                rep(j, 0, n){
                    if((mk & (1<<j))) continue;

                    int nm = (mk | (1<<j));
                    int id = i;
                    ll val = dp[i][mk] + v[j];
                    if(val >= m) {
                        id++;
                        val = 0;
                    }
    
                    dp[id][nm] = max(dp[id][nm], val);

                }
            }
        }
        
        // cout<<"m = "<<m<<"\n";
        // cout<<"dp "<<k<<", "<<(1<<n)-1<<" = "<<dp[k][(1<<n)-1]<<"\n";
        if(*max_element(all(dp[k])) >= 0){
            best = m;
            l = m+1;
        }
        else{
            r = m;
        }
    }

    cout<<best+add<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}