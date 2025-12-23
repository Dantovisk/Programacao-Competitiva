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
// #define pb push_back

const int inf = 1e9+7;

void solve(){
    int n;
    cin>>n;
    vi v(n+1, 0);
    vi ub(n+1, 0);
    rep(i, 0, n) cin>>v[i];

    if(n<=1){
        cout<<"0\n";
        return;
    }


    ub[0] = v[1]-v[0];
    ub[n-1] = v[n-1] - v[n-2];

    for(int i = 1; i <n-1; i++){
        ub[i] = min(v[i+1]-v[i], v[i]-v[i-1]);
    }

    // rep(i, 0, n) cout<<ub[i]<<" ";
    // cout<<"\n";


    int mx = ub[0], mn = 0;
    int res = 0;

    rep(i, 1, n){
        int ds = v[i]-v[i-1];
        
        if(ds >= mx + ub[i]){
            mn = 0;
            mx = ub[i];
            // cout<<i<<"=F"<<" -> ";
        }
        else{
            res++;
            int minn = mn;
            mn = max(0, ds-mx);
            mx = min(ds-minn, ub[i]);
            // cout<<i<<"=V"<<" -> ";
        }
    }   
    cout<<res<<"\n";
    
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}