// #pragma GCC optimize("Ofast,unroll-loops")

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
typedef vector<short int> vsi;

short int dp [1<<23]= {};
short int par[1<<23] = {};
short int nxt[320][24] = {};

void solve(){
    int n, k;
    cin>>n>>k;

    vi v(n);
    rep(i, 0, n){
        cin>>v[i];
    }

    if(k >= 24){
        set<int> resto;
        rep(i, 1, k+1) resto.insert(i);
    
        set<int> visto;
        vi resp;
    
        rep(i, 0, n){
            if(resp.size() == k) break;
    
            if(resto.find(v[i]) != resto.end()) visto.insert(v[i]);
    
            if(visto.size() == resto.size()){
                resp.pb(v[i]);
                resto.erase(v[i]);
                visto.clear();
            }
        }
    
        if(sz(resp) == k){
            cout<<"*\n";
            return;
        }
    
        for(auto k: resto){
            if(visto.find(k) == visto.end()){
                resp.push_back(k);
                resto.erase(k);
                break;
            }
        }
    
        for(auto x: resto) resp.push_back(x);
    
        for(auto x: resp) cout<<x<<" ";
        
        return;
    }

    vector<vsi> ocurr(k+1);
    memset(dp, -1, sizeof(dp));

    rep(i, 0, n){
        ocurr[v[i]].push_back(i);
    }
    rep(i, 0, k+1){
        ocurr[i].push_back(n+1);
    }

    rep(i, 1, k+1){
        rep(j, 0, n+3){
            auto ptr = lower_bound(all(ocurr[i]), j);
            if(ptr != ocurr[i].end()) nxt[j][i] = *ptr;
            else {
                nxt[j][i] = n+1;
            }
        }
    }

    dp[0] = -1;
    int goat = (1<<k)-1;

    rep(mask, 0, (1<<k)){
        if (dp[mask] >= n){
            goat = mask;
            break;
        }

        int curr = dp[mask] + 1;
        rep(i, 0, k){
            if((1<<i) & mask) continue;
            
            int nm = (mask |(1<<i));

            // int id = nxt[curr+1][i+1];

            if(nxt[curr][i+1] > dp[nm]){
                dp[nm] = nxt[curr][i+1];
                par[nm] = i+1;
            }
        }
    }

    // cout<<dp[goat]<<"\n";
    if(dp[goat] < n) {
        cout<<"*\n";
        return;
    }


    vi res;
    set<int> vis;

    int a = goat;
    while(par[a] != 0){
        res.pb(par[a]);
        vis.insert(par[a]);
        a = ((1<<(par[a]-1)) ^ a);
    }

    reverse(all(res));

    rep(i, 1, k+1){
        if(!vis.count(i)) res.push_back(i);
    }

    for(auto x: res) cout<<x<<" ";
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    // cin>>t;

    while(t--)solve();
}