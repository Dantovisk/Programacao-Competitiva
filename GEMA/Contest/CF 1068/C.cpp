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

void solve(){
    int n, k; cin>>n>>k;

    vi v(n);
    set <int> s, vis;


    rep(i, 0, n) {
        cin>>v[i];
        s.insert(v[i]);
    }
    
    sort(all(v));

    vi res;

    for(auto a : v){
        if(vis.find(a) != vis.end()) continue;

        res.push_back(a);

        for(int i = a; i <= k; i+=a){
            if(vis.find(i) != vis.end()) continue;
            if(s.find(i) == s.end()){
                cout<<"-1\n";
                return;
            }
            vis.insert(i);
        }
    }
    cout<<res.size()<<"\n";
    for(auto r: res) cout<<r<<" ";
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}