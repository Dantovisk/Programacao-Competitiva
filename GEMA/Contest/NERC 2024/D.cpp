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

vector<pii> utila = {{0, 0}}, utilb = {{0, 0}};

map<tuple<int,int,int>, int> dp;

set<tuple<int,int,int>> vis;

const int inf = 1e9+7;

int game(int at, int df, int player){
    // cout<<"to no"<<at<<" - "<<df<<" - "<<player<<"\n";

    if(dp.find({at, df, player}) != dp.end()) 
        return dp[{at, df, player}];

    if(vis.find({at, df, player}) != vis.end()){
        return dp[{at, df, player}] = 0;
    };

    vis.insert({at, df, player});

    int res = 0;

    if(player == 0){
        auto ptr = upper_bound(all(utilb), make_pair(df, inf));

        if(ptr == utilb.end()) res = -1;
        else{
            res = game((*ptr).ff, (*ptr).ss, 1);
        }
    } else{
        auto ptr = upper_bound(all(utila), make_pair(df, inf));

        if(ptr == utila.end()) res = 1;
        else{
            res = game((*ptr).ff, (*ptr).ss, 0);
        }
    }

    return dp[{at, df, player}] = res;
}

void solve(){
    int n, m; cin>>n;
    vi a1(n), d1(n);
    rep(i, 0, n) cin>>a1[i];
    rep(i, 0, n) cin>>d1[i];

    cin>>m;
    vi a2(m), d2(m);
    rep(i, 0, m) cin>>a2[i];
    rep(i, 0, m) cin>>d2[i];
    
    vector<pii> a, b;
    rep(i, 0, n){
        a.push_back({a1[i], d1[i]});
    }
    rep(i, 0, m){
        b.push_back({a2[i], d2[i]});
    }

    sort(all(a)); sort(all(b));

    utila.clear(); utilb.clear();
    vis.clear(); dp.clear();

    rep(i, 0, n){
        while(!utila.empty() && utila.back().ss <= a[i].ss) 
            utila.pop_back();
        
        utila.push_back(a[i]);
    }

    rep(i, 0, m){
        while(!utilb.empty() && utilb.back().ss <= b[i].ss) 
            utilb.pop_back();
        
        utilb.push_back(b[i]);
    }

    // cout<<"utila\n";
    // for(auto[x, y]:utila) cout<<x<<" "<<y<<"\n";
    // cout<<"\nutilb\n";
    // for(auto[x, y]:utilb) cout<<x<<" "<<y<<"\n";

    //agora podemos trabalhar com pareto :D
    map<int,int> res;
    for(auto [at, def] : a){
        res[game(at,def,0)]++;
    }
    cout<<res[-1]<<" "<<res[0]<<" "<<res[1]<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;
    rep(i, 0, t){
        solve();
    }
}