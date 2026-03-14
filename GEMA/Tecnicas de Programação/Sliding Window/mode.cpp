#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int main() {
	cin.tie(0)->sync_with_stdio(0);

    int n, ks;
    cin>>n>>ks;

    map <int, int> mp;
    set <pii> s;
    vi v(n);
    rep(i,0,n) cin>>v[i];

    rep(i, 0, ks-1) {
        int k = (++mp[v[i]]);
        if(k>1)s.erase({-(k-1), v[i]});
        s.insert({-k, v[i]});
    }

    rep(i, 0, n-ks+1){
        int k = (++mp[v[i+ks-1]]);
        // cout<<"i = "<<i<<", k ="<<k<<"\n";

        if(k>1) s.erase({-(k-1), v[i+ks-1]});
        s.insert({-k, v[i+ks-1]});
    
        // for(auto [qt, ke] : s){
        //     cout<<"{"<<qt<<", "<<ke<<"}\n";
        // }
        cout<<((*s.begin()).second)<<" "; 
        
        s.erase({-mp[v[i]], v[i]});
        if((--mp[v[i]]) == 0) mp.erase(v[i]);
        else{
            s.insert({-mp[v[i]], v[i]});
        }
    }
    cout<<"\n";


}