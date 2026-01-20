#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, int> tii;
typedef vector<ll> vi;

const int MAX = 2e5+7;
const int inf = 1e9+7;

void solve(){
    int n, m, h;
    cin>>n>>m>>h;

    vi v(n), curr(n), last(n, -1);

    rep(i, 0, n){
        cin>>v[i];
        curr[i] = v[i];
    }

    int reset = -1;
    rep(i, 0, m){
        int a, b;
        cin>>a>>b;
        a--;

        if(last[a] < reset){
            curr[a] = v[a];
        }
        curr[a] += b;
        last[a] = i;
        
        if(curr[a] > h){
            reset = i;
            curr[a] = v[a];
        }
    }

    rep(i, 0, n){
        if(last[i] < reset){
            curr[i] = v[i];
        }
        cout<<curr[i]<<" ";
    }

    cout<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}