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
    int n = 7;
    cin>>n;

    ll res = 0;
    rep(i, 1, n+1){
        res += (ll)(n/i) * (ll)(n/i);
    }
    // int cont = 0;
    // rep(i, 1, n){
    //     rep(j, 1, n){
    //         rep(k, 1, n){
    //             int g1 = gcd(i, j);
    //             int g2 = gcd(j, k);
    //             if(gcd(i, k) == gcd((i*j)/g1, (j*k)/g2)){
    //                 cout<<"("<<i<<", "<<j<<"' "<<k<<")\n";
    //                 cont++;
    //             }
    //         }
    //     }
    // }
    // cout<<cont<<"\n";
    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}