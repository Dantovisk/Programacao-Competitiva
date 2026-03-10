#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define pb push_back
#define ff first
#define ss second


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);

    int n; cin>>n;

    vector<pii> v;

    int last = -1;
    rep(i, 0, n){
        int a, b;
        cin>>b>>a;
        v.pb({a, -b});
    }

    sort(all(v));

    vector<pii> pts;
    ll acum = 0;
    for(auto[x, y] : v){
        y = -y;
        if(x + y > last){
            acum += y;
            pts.push_back({x, y});
            last = x + y;
        }
    }
    // cout<<"Acum: "<<acum<<"\n";

    vector<int> vant;

    rep(i, 0, sz(pts)-1){
        int exp = pts[i+1].ff - pts[i].ff;
        // cout<<exp<<" -> ";
        int aux = exp - pts[i].ss;
        vant.push_back({aux});
        // cout<<"Aux: "<<aux<<"\n";
    }

    sort(all(vant));
    vector<ll> res;

    for(auto k: vant){
        if(k <= 0)acum += k;
        else{
            res.pb(acum);
            acum += k;
        }
    }
    res.pb(acum);
    reverse(all(res));

    rep(i, 0, n){
        if(i < sz(res)) cout<<res[i]<<" ";
        else cout<<res.back()<<" ";
    }
    cout<<"\n";

}