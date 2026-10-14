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

const int maxn = 2e5+4;
const int inf = 1e9+3;

int v[maxn];

void solve(){
    int n; 
    cin>>n;

    ll sum = 0;
    ll sig = 1;
    rep(i, 0, n) {
        cin>>v[i];
        sum += sig*v[i];
        sig *= -1;
    }

    // int cur = 0;
    // // int last = 0;
    // rep(i, 0, n){
    //     int dx = v[i] - cur;
    //     cur += 2*dx;
    // }

    cout<<sum<<"\n";

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    cin>>t;

    while(t--) solve();
}