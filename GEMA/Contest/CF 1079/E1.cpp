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

int adj[20][20];
void solve(){
    memset(adj, 0, sizeof(adj));
    int n; cin>>n;

    int mx = 1e6+1;
    int mn = 1;
    vi last = {1};
    while(1){
        vi lb;
        int l = mn, r = mx;
        int res = -1;
        while(l < r){
            int mid = (r+l)/2;
            cout<<"? "<<mid<<endl;

            int k;
            cin>>k;

            if(k==0){
                mx = mid;
                r = mid;
                continue;
            }
            vi sla(k);

            rep(j, 0, k) cin>>sla[j];

            rep(j, 0, k-1){
                adj[sla[j]][sla[j+1]] = 1;
            }

            if(sla > last){
                lb = sla;
                r = mid;
            }
            else{
                l = mid+1;
            }
        }

        if(lb.size() == 0) break;

        last = lb;
        if(last.size() > 1)
            last.push_back(67);
    }

    vector<pii> res;
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            if(adj[i][j]) res.pb({i,j});
        }
    }
    cout<<"! "<<res.size()<<endl;
    for(auto [u, v]: res){
        cout<<u<<" "<<v<<endl;
    }


}

int main() {
	// cin.tie(0)->sync_with_stdio(0);
	// cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}