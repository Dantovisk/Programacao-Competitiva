#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
#define ff first
#define ss second
#define pb push_back

const int maxn = 2e5+4;
const ll inf = 1e18+3;

void solve(){
    ll n, m, d; 
    cin>>n>>m>>d;
    
    vector<pii> cord;
    cord.pb({0, 0});
    vi p(m+1), r(m+1);
    rep(i, 1, m+1) {
        cin>>p[i]>>r[i];
        cord.pb({p[i], i});
    }


    vi psum(m+1, 0);
    rep(i, 1, m+1) psum[i] = psum[i-1] + r[i];

    rep(i, 0, m+1){
        rep(j, 1, m+1){
            ll qtd = p[i]+p[j]+1;
            ll curr = psum[i] + psum[j] + (qtd-1)*d;

            ll base = 0;
            base += d*qtd;

            if(qtd > n){
                qtd -= n;
                base += psum[m];
            }
            auto ptr = upper_bound(all(cord), make_pair(qtd, (ll)inf));

            auto [sla, id] = *prev(ptr);

            base += psum[id];


            // cout<<qtd<<"\n";

            // cout<<i<<", "<<j<<": "<<base<<" x "<<curr<<"\n";

            if(base < curr){
                cout<<"YES\n";
                return;
            }
        }
    }

    cout<<"NO\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}