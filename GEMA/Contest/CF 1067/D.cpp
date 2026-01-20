#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, int> tii;
typedef vector<ll> vi;

const int mod = 998244353;

void solve(){
    int n, m;
    cin>>n>>m;
    
    vi v(n+1);
    map<pair<int, int>, int> dp;

    rep(i, 1, n+1) {
        cin>>v[i];
    }

    vector<vector<tii>> adj(n+1);

    vector<tuple<ll,int,int>> e;


    ll res = 0;
    rep(i, 0, m){
        int a, b;
        cin>>a>>b;
        adj[a].push_back({v[b], b});

        e.push_back({v[a]+v[b], a, b});
    }

    sort(all(e));
    reverse(all(e));

    rep(i, 1, n+1) sort(all(adj[i]));

    for(auto &[w, a, b]: e){
        auto id1 = make_pair(a, v[b]);

        dp[{a, v[b]}]++;

        ll cost = v[a]+v[b];

        if(dp.find({b, cost}) != dp.end()){
            dp[id1] += dp[{b, cost}];
            dp[id1] %= mod;
        }
        // cout<<"dp["<<a<<"]["<<b<<"] = "<<dp[a][b]<<"\n";
    }

    for(auto [key, val]: dp){
        res += val;
        res %= mod;
    }

    
    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}