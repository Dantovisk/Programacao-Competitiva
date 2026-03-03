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
    int n; 
    cin>>n;

    vi v(n*2);
    rep(i,0, n) {
        cin>>v[i];
        v[i+n] = v[i];
    }

    vi win(n, 0);

    rep(i, 0, n){
        pii best = {0, -1};
        rep(j, 0, n){
            best = max(best, {v[i+j], (i+j)});
        }
        win[(best.ss)%n] = 1;
    }

    int res = 0;   
    rep(i, 0, n) if(win[i]) res++;

    cout<<res<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1; 
    cin>>t;

    while(t--)solve();
}