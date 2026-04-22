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

const int MAX = 1e5+7;
const int inf = 1e9+7;
const ll mod = 676767677;

void solve(){
    int n, m; 
    cin>>n>>m;

    vector<vi> ct(m+1);
    vi pref(m+1, 0);
    
    vi v(n), l(n, 0), r(n, 0);
    rep(i,0, n) cin>>v[i];
    if(n == 1){
        if(v[0] == 0) cout<<"1\n";
        else cout<<"0\n";
        return;
    }

    int deu = 1;
    if(v[0] != 0 && v[1] >= v[0]) deu = 0;
    if(v[n-1] != 0 && v[n-2] >= v[n-1]) deu = 0;

    rep(i, 1, n-1){
        if(v[i] != 0){
            if(v[i-1] >= v[i] and v[i+1] >= v[i]) deu = 0;
        }
    }
    if(deu == 0){
        cout<<"0\n";
        return;
    }

    rep(i, 0, n) ct[v[i]].pb(i);

    pref[0] = sz(ct[0]);

    rep(i, 1, m) pref[i] = pref[i-1]+sz(ct[i]);

    ll res = 1;
    for(auto x: ct[0]){
        l[x] = 0;
        r[x] = 0; 
    }

    rep(i, 1, m){
        for(auto x: ct[i]){
            int dar = 1;
            if(x > 0 and v[x-1] < v[x]-1){
                dar = 0;
            }
            if(x < n-1 and v[x+1] < v[x]-1){
                dar = 0;
            }

            int mx, mn;
            if(dar){
                mn = 1;
            }else{
                if(i == 1) mn = 1;
                else mn = pref[i-2] + 1;
            }

            mx = pref[i-1];
            // cout<<x<<": "<<mx<<" "<<mn<<"\n";

            res *= (mx-mn+1);
            res %= mod;


        }
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