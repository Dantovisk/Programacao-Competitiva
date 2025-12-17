#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    int n; cin>>n;
    vi v(n), vis(n, 0);

    int res = 0;
    rep(i, 0, n) {
        cin>>v[i];
    }

    for(int i = n-1; i >=0; i--){
        rep(j, i+1, n){
            if(v[j] < v[i] && vis[j] == 0){
                res++;
                vis[j] = 1;
            }
        }
    }
    
    cout<<res<<"\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t; cin>>t;

    while(t--) solve();
}