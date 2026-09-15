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


struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] = dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] = max(dif, s[pos]);
	}
	ll query(int pos) { // max of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res = max(s[pos-1], res);
		return res;
	}
};

void solve(){
    int n; 
    cin>>n;


    ll res = 0;
    vi v(n);
    vector<ll> resaux(n+1, 0);

    //linha de fim, tipo (0 =teste, 1 = add), id
    vector<tuple<int, int, int>> q;

    FT ft(2*n+8), ft2(n+1);

    rep(i, 0, n){
        cin>>v[i];
        if(v[i] >= n){
            res = max(res, (ll)v[i]);
            v[i] = 0;
        }
        //add
        q.pb({(i+v[i]), 1, i});

        //query
        q.pb({i, 0, i});
    }

    sort(all(q));
    int last = -1;
    for(auto [linha, t, i] : q){
        if(t == 0){
            //query
            ll aux = 0;
    
            if(i -v[i] > 0) aux = ft.query(i-v[i]);
            aux += v[i];

            resaux[i] = max(resaux[i], aux);
        }
        else{
            ft.update(i, resaux[i]);
        }
    }

    cout<<max(ft.query(2*n+1), res)<<'\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}