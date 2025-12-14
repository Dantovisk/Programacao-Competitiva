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

void solve(){
    int n; cin>>n;
    vi v1 (n), v2(n);

    rep(i, 0, n) cin>>v1[i];
    rep(i, 0, n) cin>>v2[i];

    for(int k = 20; k >= 0; k--){
        int state = 0;
        rep(i, 0, n){
            int a = ((1<<k) & v1[i]), b = ((1<<k) & v2[i]);
            
            if(a != b) {
                state += (i%2 ? 1 :-1);
            }
    
            if(state >= 2) state = 0;
            if(state <= -2) state = 0;
        }
        if(state != 0){
            // cout<<"k = "<<k<<": "<<state<<"\n";
            if(state > 0) cout<<"Mai\n";
            else cout<<"Ajisai\n";
            return;
        }
    }
    cout<<"Tie\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; cin>>t;

    while(t--)solve();
}