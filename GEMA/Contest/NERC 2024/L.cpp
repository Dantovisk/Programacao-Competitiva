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
    int n, k, x;
    ll m;
    cin>>n>>k>>x>>m;

    vi cost(n), val(n);
    rep(i, 0, n) cin>>cost[i];
    rep(i, 0, n) cin>>val[i];
    
    ll l = 1, r = 1e9+7;
    ll best = -1;

    while(l< r){
        ll mid = (l+r)/2LL;

        vi maior, menor;
        rep(i, 0, n){
            if(val[i] >= mid) maior.push_back(cost[i]);
            else menor.push_back(cost[i]);
        }

        sort(all(maior));
        
        ll acum = 0;
        int cont = 0;
        
        if(x > maior.size()){
            r = mid;
            continue;
        }
        
        rep(i, 0, x){
            acum += maior[i];
            cont++;
        }
            
        rep(i, x, maior.size()) menor.push_back(maior[i]);
            
        sort(all(menor));

        rep(i, 0, min(k-x, (int)menor.size())){
            acum += menor[i];
            cont++;
        }
        
        if(acum > m || cont < k){
            r = mid;
            continue;
        }
        else{
            best = max(best, mid);
            l = mid+1LL;
        }

    }

    cout<<best<<"\n";
}

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int n = 1; 
    cin>>n;
    rep(i, 0, n){
        solve();
    }
}