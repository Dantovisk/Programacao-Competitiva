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

void solve(){
    int n; 
    cin>>n;

    vi a(n), b(n);
    rep(i, 0, n){
        cin>>a[i];
    }
    rep(i, 0, n){
        cin>>b[i];
    }

    int res = 0;
    rep(i, 0, n){
        res ^= (b[i]-a[i]-1)%2;
    }

    if(res == 0) cout<<"Oponente\n";
    else cout<<"Eu\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

    int t = 1;
    // cin>>t;

    while(t--) solve();
}