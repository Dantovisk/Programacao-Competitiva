#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



void solve(){
    int n, m;
    cin>>n>>m;

    vi v(n+1), pref(n+1, 0);
    rep(i, 1, n+1) {
        cin>>v[i];
        pref[i] = pref[i-1] + v[i];
    }

    vector<pii> cres;
    cres.push_back({0, 0});
    rep(i, 1, n+1){

        int best = 1e9+2;
        int l = 0, r = 1e9+2;
        while(l < r){
            int mid =(l+r)/2;

            auto ptr = upper_bound(all(cres), make_pair(mid, 100000067LL));
            ptr--;

            auto [sla, id] = *ptr;

            int sum = pref[i] - pref[id];
            int dist = i-id;
            if(sum <= mid*dist){
                r = mid;
                best =  min(best, mid);
            }else{
                l = mid+1;
            }
        }

        while((!cres.empty()) && cres.back().first >= best) {
            cres.pop_back();
        }
        cres.push_back({best, i});
    }

    // for(auto [w, id]: cres)cout<<"["<<w<<" , "<<id<<"] ";
    // cout<<"\n";

    rep(i, 0, m){
        int q; cin>>q;

        auto ptr = upper_bound(all(cres), make_pair(q, 100000067LL));
        ptr--;

        auto [sla, id] = *ptr;

        int sum = pref[n] - pref[id];
        int dist = n-id;

        cout<<max(0LL, sum - q*dist)<<" ";
    }
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n = 1; 
    // cin>>n;
    rep(i, 0, n){
        solve();
    }
}