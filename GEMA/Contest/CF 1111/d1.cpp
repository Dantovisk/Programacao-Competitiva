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
    int n, q; 
    cin>>n>>q;

    vi v(n);

    vector<pii> v2;

    rep(i, 0, n){
        cin>>v[i];

        v2.emplace_back(v[i],i);
    }

    ll res = 0;

    sort(all(v2));

    rep(i, 0, n){
        auto [val, j] = v2[i];
        ll dif = 0;

        for(int k = 30; k>= 0; k--){
            int aux = (1<<k);
            if((i & aux) ^ (j & aux)){
                dif = aux;
                break;
            }
        }
        res = max(res, dif);
    }

    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}