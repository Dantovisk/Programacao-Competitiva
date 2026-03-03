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

const int MAX = 1e5+7;
const int inf = 1e9+7;

void solve(){
    int n, x, y; 
    cin>>n>>x>>y;

    vi v(n);
    rep(i,0, n) cin>>v[i];

    pii mn = {inf, x};

    vi dentro (y-x);
    rep(i, x, y){
        mn = min(mn, {v[i], i});
    }

    int ct = 0;
    rep(i, mn.ss, y){
        dentro[ct++] =  v[i];
    }
    rep(i, x, mn.ss){
        dentro[ct++] =  v[i];
    }

    int st = 0;
    rep(i, 0, n){
        if(i >= x && i < y){
            continue;
        }
        if(v[i] < mn.ff){
            st= i+1;
        }
        else{
            break;
        }
    }

    rep(i, 0, n+1){
        if(i == st){
            for(auto k: dentro)
                cout<<k<<" ";  
        }

        if(i == n) continue;
        if(i >= x && i < y){
            continue;
        }
        else{
            cout<<v[i]<<" ";
        }
    }
    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}